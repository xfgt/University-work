package homeworks.hw3;

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
			if(atAddress)
				extraFee = amount;
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
			minimalDeliveryPrice = price;
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
			this.weight = weight;
			_wDeliveryPrice = price;
		}
		
		@Override
		public double deliveryPrice() {
			
			_wDeliveryPrice *= weight;
			
			if(super.atAddress) {
				_wDeliveryPrice += super.deliveryPrice();
			}
			
			if(material.isMaterialFragile()) {
				_wDeliveryPrice = _wDeliveryPrice - _wDeliveryPrice * 0.01;
				//(wdp -= wdp * 0.01)
			}
			return _wDeliveryPrice;
		}
		
	}
		
		
	}
	
	public static void main(String[] args) {
		
		
		return;
		
	}

}
