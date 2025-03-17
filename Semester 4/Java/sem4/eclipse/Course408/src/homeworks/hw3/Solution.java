package homeworks.hw3;



import java.util.Scanner;


public class Solution {
	
	
	interface IFDeliverable{
		double deliveryPrice();
	}
	
	
	
	
	class DeliverableItem implements IFDeliverable{
		
		Boolean atAddress;
		double extraFee;
		
		
		
		public DeliverableItem(Boolean atAddress) {
			this.atAddress = atAddress;	
		}
		
		void setExtraFee(double amount) {
			
			if(atAddress) {
				if(amount > 0)
					extraFee = amount;
				else 
					extraFee = 1;
			}
				
			
			
		}
		
		@Override
		public double deliveryPrice() {
			return extraFee;
		}
	}
	
	class Material{
		String name;
		Boolean isFragile;
		
		public Material(String name, Boolean isFragile) {
			this.name = name;
			this.isFragile = isFragile;
		}
		
		public Boolean isMaterialFragile() { return isFragile; }
	}
	
	class Document extends DeliverableItem implements IFDeliverable{
		double minimalDeliveryPrice;
		
		public Document(double price, Boolean atAddress) {
			super(atAddress);
			if(price > 0)
				minimalDeliveryPrice = price;
			else
				minimalDeliveryPrice = 1;
		}
		
		@Override
		public double deliveryPrice(){
			if(super.atAddress) {
				minimalDeliveryPrice += super.deliveryPrice();
			}
			return minimalDeliveryPrice;
		}
		
	
	}
	
	class WeightedItem extends DeliverableItem implements IFDeliverable{
		
		Material material;
		double weight;
		double _wDeliveryPrice;
		
		public WeightedItem(Material material, double weight, double price, Boolean atAddress) {
			super(atAddress);
			this.material = material;
			
			if(price > 0 && weight > 0) {
				this.weight = weight;
				_wDeliveryPrice = price;
			} else {
				this.weight = 1;
				_wDeliveryPrice = 1;
				
			}
				
		}
		
		@Override
		public double deliveryPrice() {
			
			_wDeliveryPrice *= weight;
			
			if(super.atAddress) {
				_wDeliveryPrice += super.deliveryPrice();
			}
			
			
			// 1% increase if fragile
			if(material.isMaterialFragile()) {
				_wDeliveryPrice = _wDeliveryPrice - _wDeliveryPrice * 0.01;
				//(wdp -= wdp * 0.01)
			}
			return _wDeliveryPrice;
		}
		
	}
		
		
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
		
		
		
		
		
		
		
		
		
		
		return;
		
	}

}
