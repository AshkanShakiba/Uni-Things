import java.util.Scanner;

/**
 * The main class to run the program
 * @author Ashkan Shakiba
 * @version 0.0 (2020-04-23)
 */
public class Main {
    /**
     * Main method to run the program
     * @param args System arguments
     */
    public static void main(String[] args){
        Product product;
        Basket basket=new Basket();
        Inventory inventory=new Inventory();

        product=new Product("Carrot","Vegetables",5,20,15,3,2020,15,3,2021);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,10);

        product=new Product("Apple","Fruits",10,50,1,4,2020,1,8,2020);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,50);

        product=new Product("12xEggs","Egg",100,40,1,1,2020,1,6,2020);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,20);

        product=new Product("Oats","Grains",70,100,1,6,2020,1,1,2021);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,45);

        product=new Product("Salmon","Seafood",150,250,1,1,2020,1,2,2020);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,5);

        product=new Product("Stake","Meat",800,1000,1,3,2020,1,9,2020);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,5);

        product=new Product("Milk","Dairy",100,20,10,1,2020,25,1,2020);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,20);

        product=new Product("Cheese","Dairy",150,10,1,2,2020,15,3,2020);
        inventory.addProduct(product);
        inventory.changeNumberTo(product,50);

        int number;
        String command="";
        Scanner input=new Scanner(System.in);
        while(true){
            command=input.next();
            if(command.equals("add")){
                number=input.nextInt();
                product=inventory.getProduct(number);
                if(product!=null && inventory.decrease(product)){
                    basket.addProduct(product);
                    basket.increase(product);
                }
            }
            if(command.equals("remove")){
                number=input.nextInt();
                product=basket.getProduct(number);
                if(product!=null && basket.decrease(product)){
                    inventory.addProduct(product);
                    inventory.increase(product);
                }
            }
            if(command.equals("cart")){
                System.out.print(basket.toString());
            }
            if(command.equals("products")){
                System.out.print(inventory.toString());
            }
            if(command.equals("checkout")){
                System.out.println("It was a pleasure doing business with you.");
                return;
            }
        }
    }
}