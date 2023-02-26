import java.util.ArrayList;
import java.util.Iterator;
import java.util.UUID;

public class Account {
    private UUID serial;
    private String id;
    private String firstName;
    private String lastName;
    private String type;
    private int balance;
    private ArrayList<Transaction> transactions;
    public Account(String id,String firstName,String lastName,String type,int balance){
        this.id=id;
        this.firstName=firstName;
        this.lastName=lastName;
        this.type=type;
        this.balance=balance;
        serial=UUID.randomUUID();
        transactions=new ArrayList<Transaction>();
    }
    public String getSerial(){
        return serial.toString();
    }
    public String getId(){
        return id;
    }
    public int getBalance(){
        return balance;
    }
    public int updateBalance(int amount){
        if(balance+amount>=0){
            balance+=amount;
            return 0;
        }
        else{
            return -1;
        }
    }
    public void addTransaction(Transaction transaction){
        transactions.add(transaction);
    }
    public void printTransactions(){
        Iterator<Transaction> it=transactions.iterator();
        while (it.hasNext()){
            it.next().print();
        }
    }
    public void printAccountData(int mode){
        if(mode==1) {
            System.out.printf("%s, %s, %s %s, %d\n", serial.toString(), id, firstName, lastName, balance);
        }
        if(mode==2){
            System.out.printf("%s, %s, %d\n", serial.toString(), type, balance);
        }
    }
}