package org.example.goods;

public interface ItemForSale {
    double productionPrice();
    double sellingPrice();

    default double profit() {   // default implementation
        return this.sellingPrice() - this.productionPrice();
    }

    /*private boolean validation(){
        return true; // for example
    }*/


}
