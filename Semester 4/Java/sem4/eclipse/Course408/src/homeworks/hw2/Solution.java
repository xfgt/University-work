package homeworks.hw2;

import java.util.Scanner;

 class Manifacturer {
    
    private String m_name;
    private Boolean m_providesExtendedWarranty;
    
    public Manifacturer(String name, Boolean warranty){
        m_name = name;
        m_providesExtendedWarranty = warranty;
    }
    
    public String getName() { return m_name; }
    public Boolean providesExtendedWarranty() { return m_providesExtendedWarranty; }

}

 class ElectricDevice extends Manifacturer {
    
    private int m_monthsOfWarranty;
    
    public ElectricDevice(Manifacturer manifacturer, int minimalWarranty) {
        super(manifacturer.getName(), manifacturer.providesExtendedWarranty());
        
        if(minimalWarranty >= 6)
            m_monthsOfWarranty = minimalWarranty;
        else
            m_monthsOfWarranty = 6;
        
        
    }
    public int warranty() {
        if(super.providesExtendedWarranty()) {
            m_monthsOfWarranty += 12;
        }
        return m_monthsOfWarranty;
    }
    
    
}


 class Cooker extends ElectricDevice {
    
    private int m_minimalWarranty;
    private Boolean m_isGas;
    
    public Cooker(Manifacturer manifacturer, int minWarranty, Boolean isGas){
        super(manifacturer, minWarranty);
        m_minimalWarranty = super.warranty();
        m_isGas = isGas;
    }
    public int warranty() {
        
        if(m_isGas == true) {
            m_minimalWarranty += 12;
        }
        return m_minimalWarranty;
    }
    
    
}
 class WashingMachine extends ElectricDevice {
    
    private int m_minimalWarranty;
    private Boolean m_isTumbleDrier;
    
    public WashingMachine(Manifacturer manifacturer, int minWarranty, Boolean tumbleDrier){
        super(manifacturer, minWarranty);
        m_minimalWarranty = minWarranty;
        m_isTumbleDrier = tumbleDrier;
    }

    public int warranty() {
        
        if(m_isTumbleDrier == true) {
            m_minimalWarranty *= 0.5;
            m_minimalWarranty += super.warranty();
        }
        // third case pass:            m_minimalWarranty *= super.warranty() * 0.5;
        
        return m_minimalWarranty;
    }
    
    
}


public class Solution {
        
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        
        String manName = scanner.nextLine();
        int ltw_int = Integer.parseInt(scanner.nextLine()); // long term warranty (bool)
        int mw = Integer.parseInt(scanner.nextLine()); // minimal warranty
        int isGas_int = Integer.parseInt(scanner.nextLine());
        int isDrier_int = Integer.parseInt(scanner.nextLine()); 
        
        boolean ltw_b = (ltw_int == 0) ? false : true;
        Manifacturer m = new Manifacturer(manName, ltw_b);
        
        ElectricDevice ed = new ElectricDevice(m, mw);
        System.out.println(ed.warranty());
        
        boolean isGas_b = (isGas_int == 0) ? false : true;
        ed = new Cooker(m, mw, isGas_b);
        System.out.println(ed.warranty());
        
        boolean isDrier_b = (isDrier_int == 0) ? false : true;
        ed = new WashingMachine(m, mw, isDrier_b);
        System.out.println(ed.warranty()); 
        
        scanner.close();
    }
    
    
    
    

} 
