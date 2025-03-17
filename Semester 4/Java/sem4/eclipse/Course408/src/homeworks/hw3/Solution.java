package homeworks.hw3;

import java.util.Scanner;


	interface IFDeliverable{
		double deliveryPrice();
	}
	

	class DeliverableItem implements IFDeliverable {
	
		Boolean DI_deliverToAddress;
		static double DI_additionalPrice;
				
		public DeliverableItem(Boolean toAddress) {
			DI_deliverToAddress = toAddress;
		}
		
		public void setAdditionalPrice(double additionalPrice) {
			
			if(DI_deliverToAddress) {
				if(additionalPrice > 0)
					DI_additionalPrice = additionalPrice;
				else
					DI_additionalPrice = 1;
			}
				
		}
		
		public final Boolean getDeliveryType() { return DI_deliverToAddress; }
		
		@Override
		public double deliveryPrice() {
			return DI_additionalPrice;
		}
	}
	
	
	
	
//	Material class
	class Material{
		String M_name;
		Boolean M_isFragile;
		
		public Material(String name, Boolean isFragile) {
			M_name = name;
			M_isFragile = isFragile;
		}
		
		public Boolean isMaterialFragile() { return M_isFragile; }
	}
	
	
	
	
	
	class Document extends DeliverableItem implements IFDeliverable{
		double D_minimalDeliveryPrice;
		
		public Document(double price, Boolean deliverToAddress) {
			super(deliverToAddress);
			if(price > 0)
				D_minimalDeliveryPrice = price;
			else
				D_minimalDeliveryPrice = 1;
		}
		
		@Override
		public double deliveryPrice(){
			if(super.getDeliveryType()) {
				D_minimalDeliveryPrice += super.deliveryPrice();
			}
			return D_minimalDeliveryPrice;
		}
		
	
	}
	
	class WeightedItem extends DeliverableItem implements IFDeliverable{
		
		Material W_material;
		double W_weight;
		double W_DeliveryPrice;
		
			public WeightedItem(Material material, double weight, double price, Boolean deliverToAddress) {
				super(deliverToAddress);
				W_material = material;
				
				if(price > 0 && weight > 0) {
					W_weight = weight;
					W_DeliveryPrice = price;
				} else {
					W_weight = 1;
					W_DeliveryPrice = 1;
					
				}
					
			}
			
			@Override
			public double deliveryPrice() {
				
				W_DeliveryPrice *= W_weight;
				
				if(super.getDeliveryType()) {
					W_DeliveryPrice += super.deliveryPrice();
				}
				
				
				// 1% increase if fragile
				if(W_material.isMaterialFragile()) {
					W_DeliveryPrice = W_DeliveryPrice - W_DeliveryPrice * 0.01;
					//(wdp -= wdp * 0.01)
				}
				return W_DeliveryPrice;
			}
	}
	

	
public class Solution {
	

	static Boolean toBooleanValue(int x) {
		return (x == 1 ? true : false);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		String materialName = scanner.nextLine();
		
		int holdIsFragile = Integer.parseInt(scanner.nextLine());
		Boolean isFragile = toBooleanValue(holdIsFragile);
		int holdToAddress= Integer.parseInt(scanner.nextLine());
		Boolean toAddress = toBooleanValue(holdToAddress);
		
		double minPrice = Double.parseDouble(scanner.nextLine());
		double weight = Double.parseDouble(scanner.nextLine());
		double pricePerKg = Double.parseDouble(scanner.nextLine());
		double additionalPrice = Double.parseDouble(scanner.nextLine());
		
		
		
		
		IFDeliverable devb = new Document(minPrice, toAddress);
		
		System.out.println(devb.deliveryPrice());
		
		Material mat = new Material(materialName, isFragile);
		
		IFDeliverable devf = new WeightedItem(mat, weight, pricePerKg, toAddress);
		System.out.println(devf.deliveryPrice());
		
		
		
		
		
		
		
		
		
		
		
	}

}

