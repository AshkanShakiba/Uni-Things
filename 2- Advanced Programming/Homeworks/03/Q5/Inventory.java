import java.util.HashMap;
import java.util.Iterator;

/**
 * Inventory class to manage what products are available in shop
 * @author Ashkan Shakiba
 * @version 0.0 (2020-04-23)
 */
public class Inventory {
    /**
     * A HashMap of all products and their number
     */
    protected HashMap<Product,Integer> products;

    /**
     * Constructor to make a new inventory or basket
     */
    public Inventory(){
        products=new HashMap<>();
    }

    /**
     * To add a product
     * @param product product to be added
     */
    public void addProduct(Product product){
        if(products.containsKey(product)){
            return;
        }
        products.put(product,0);
    }

    /**
     * To increase number of product
     * @param product product to be changed
     */
    public void increase(Product product){
        products.put(product, products.get(product)+1);
    }

    /**
     * To decrease number of product
     * @param product product to be changed
     * @return true if task completed, false if not
     */
    public boolean decrease(Product product){
        if(products.get(product)-1<0){
            System.out.println("stock is zero");
            return false;
        }
        products.put(product,products.get(product)-1);
        return true;
    }

    /**
     * To change number of products
     * @param product product to be changed
     * @param number the amount to be set as product's number
     * @return true if task completed, false if not
     */
    public boolean changeNumberTo(Product product,int number){
        if(number<0){
            System.out.println("Error! this change will make the stock less than zero");
            return false;
        }
        products.put(product,number);
        return true;
    }

    /**
     * To change number of products
     * @param product product to be changed
     * @param number the amount to be added to previous amount
     * @return true if task completed, false if not
     */
    public boolean changeNumberBy(Product product,int number){
        if(products.get(product)+number<0){
            System.out.println("Error! this change will make the stock less than zero");
            return false;
        }
        products.put(product,products.get(product)+number);
        return true;
    }

    /**
     * To access products
     * @param index index of product
     * @return the product
     */
    public Product getProduct(int index){
        if(index<=0 || index>products.keySet().size()){
            System.out.println("Invalid index");
            return null;
        }
        Product product;
        int iteratorIndex=1;
        Iterator<Product> iterator=products.keySet().iterator();
        product=iterator.next();
        while(iteratorIndex<index){
            product=iterator.next();
            iteratorIndex++;
        }
        return product;
    }

    /**
     * To print inventory's details
     * @return String of products' list in JSON format
     */
    @Override
    public String toString() {
        if(products.keySet().size()==0){
            return "We are out of stock.\n";
        }
        int index=1;
        String res="";
        Product product;
        Iterator<Product> iterator=products.keySet().iterator();
        while (iterator.hasNext()){
            product=iterator.next();
            res+=index+")"+product.toString()+"instock: "+products.get(product)+"\n";
            index++;
        }
        return res;
    }
}