import java.util.Scanner;

public class P2 {
    public static void main(String[] args) {
        //  my domain is car garage management 
        
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of cars in the garage: ");
        int cars = s.nextInt();
        for (int i = 0; i < cars; i++) {
            System.out.println("Enter the car name: ");
            String carName = s.next();
            System.out.println("Enter the car model: ");
            String carModel = s.next();
            System.out.println("Enter the car price: ");
            double carPrice = s.nextDouble();
            double tax;
            if(carPrice<=1000000){
                System.out.println("car name: " + carName );
                System.out.println("car model: " + carModel );
                System.out.println("car price: " + carPrice );
                System.out.println("tax:"+1000000*0.1);
                System.out.println("on-road price: "+carPrice + 1000000*0.1 );
            }else if(carPrice > 2000000 && carPrice <= 3000000){
                System.out.println("car name: " + carName );
                System.out.println("car model: " + carModel );
                System.out.println("car price: " + carPrice );
                System.out.println("tax:"+carPrice*0.15);
                System.out.println("on-road price: "+carPrice + carPrice*0.15 );
                
            }
            else if(carPrice > 3000000 && carPrice <= 4000000){
                System.out.println("car name: " + carName );
                System.out.println("car model: " + carModel );
                System.out.println("car price: " + carPrice );
                System.out.println("tax:"+carPrice*0.2);
                System.out.println("on-road price: "+carPrice + carPrice*0.2 );
                
            }
            else if(carPrice > 4000000){
                System.out.println("car name: " + carName );
                System.out.println("car model: " + carModel );
                System.out.println("car price: " + carPrice );
                System.out.println("tax:"+carPrice*0.25);
                System.out.println("on-road price: "+carPrice + carPrice*0.25 );
                
            }
            else{
                System.out.println("car name: " + carName );
                System.out.println("car model: " + carModel );
                System.out.println("car price: " + carPrice );
                System.out.println("tax::"+carPrice*0.5);
                System.out.println("on-road price: "+carPrice + carPrice*0.5 );
            }
        }
        
    }
}