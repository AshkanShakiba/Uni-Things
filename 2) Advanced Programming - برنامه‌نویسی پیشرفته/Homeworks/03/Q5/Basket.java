import java.util.Iterator;

/**
 * Basket class to manage user's cart
 * This class extends Inventory class and uses its field and methods
 * @author Ashkan Shakiba
 * @version 0.0 (2020-04-23)
 */
public class Basket extends Inventory{
    /**
     * To print basket's details
     * @return String of products' list in JSON format
     */
    @Override
    public String toString() {
        if(products.keySet().size()==0){
            return "List is empty.\n";
        }
        int index=1;
        String res="Itemsincart:\n";
        Product product;
        Iterator<Product> iterator=products.keySet().iterator();
        while (iterator.hasNext()){
            product=iterator.next();
            res+=index+")"+product.toString()+"incart: "+products.get(product)+"\n";
            index++;
        }
        return res;
    }
}