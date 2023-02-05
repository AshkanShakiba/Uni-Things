import java.time.LocalDate;

/**
 * Product class to manage shop's products
 * @author Ashkan Shakiba
 * @version 0.0 (2020-04-23)
 */
public class Product {
    /**
     * Name of product
     */
    private String name;
    /**
     * Type of product
     */
    private String category;
    /**
     * Weight  of product
     */
    private double weight;
    /**
     * Price of product
     */
    private double price;
    /**
     * Production date of product
     */
    private LocalDate manufacture;
    /**
     * Expiration date of product
     */
    private LocalDate expiration;

    /**
     * Constructor to make a new product
     * @param name Name of product
     * @param category Type of product
     * @param weight Weight  of product
     * @param price Price of product
     * @param mDay Day of production date of product
     * @param mMonth Month of production date of product
     * @param mYear Year of production date of product
     * @param eDay Day of expiration date of product
     * @param eMonth Month of expiration date of product
     * @param eYear Year of expiration date of product
     */
    public Product(String name,String category,int weight,int price,int mDay,int mMonth,int mYear,int eDay,int eMonth,int eYear){
        this.name=name;
        this.category=category;
        this.weight=weight;
        this.price=price;
        manufacture=LocalDate.of(mYear,mMonth,mDay);
        expiration=LocalDate.of(eYear,eMonth,eDay);
    }

    /**
     * To print product's details
     * @return String of product's details in JSON format
     */
    @Override
    public String toString() {
        String res="";
        res+="{\n";
        res+="\t\"Product\": {\n";
        res+="\t\t\"NAME\": \""+name+"\",\n";
        res+="\t\t\"CATEGORY\": \""+category+"\",\n";
        res+="\t\t\"WEIGHT\": \""+weight+"\",\n";
        res+="\t\t\"PRICE\": \""+price+"\",\n";
        res+="\t\t\"MANUFACTURE_DATE\": "+manufacture+",\n";
        res+="\t\t\"EXPIRATION_DATE\": "+expiration+"\n";
        res+="\t}\n";
        res+="}";
        return res;
    }
}