import java.util.Date;

public class Transaction {
    private int amount;
    private Date date;
    public Transaction(int amount){
        date=new Date();
        this.amount=amount;
    }
    public void print(){
        System.out.printf("amount = %d $\n%s",amount,date.toString());
    }
}