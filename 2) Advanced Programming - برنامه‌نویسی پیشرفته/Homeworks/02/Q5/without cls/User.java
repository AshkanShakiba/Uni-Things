import java.util.ArrayList;
import java.util.Iterator;

public class User {
    private String id;
    private String firstName;
    private String lastName;
    private String password;
    private ArrayList<Account> accountList;
    public User(String id,String firstName,String lastName,String password){
        this.id=id;
        this.firstName=firstName;
        this.lastName=lastName;
        this.password=password;
        accountList=new ArrayList<Account>();
    }
    public String getId(){
        return id;
    }
    public String getFirstName(){
        return firstName;
    }
    public String getLastName(){
        return lastName;
    }
    public String getPassword(){
        return password;
    }
    public Account getAccount(int index){
        if(index>=accountList.size()){
            return null;
        }
        return accountList.get(index);
    }
    public void addAccount(Account account){
        accountList.add(account);
        Main.myBank.addAccount(account);
    }
    public void removeAccount(Account account){
        accountList.remove(account);
        Main.myBank.removeAccount(account);
    }
    public int deposit(Account account, int amount){
        if(accountList.contains(account)){
            account.updateBalance(amount);
            Transaction transaction=new Transaction(-amount);
            account.addTransaction(transaction);
            System.out.println("Completed.");
            return 0;
        }
        else {
            System.out.println("This account doesn't belong to this user");
            return -1;
        }
    }
    public int withdrawal(Account account, int amount){
        if(accountList.contains(account)){
            switch (account.updateBalance(-amount)){
                case 0:
                    System.out.println("Completed.");
                    Transaction transaction=new Transaction(amount);
                    account.addTransaction(transaction);
                    break;
                case -1:
                    System.out.println("Not enough money.");
            }
            return 0;
        }
        else {
            System.out.println("This account doesn't belong to this user");
            return -1;
        }
    }
    public int transfer(Account srcAccount, Account destAccount, int amount){
        if(accountList.contains(srcAccount)){
            if(srcAccount.getBalance()>=amount){
                srcAccount.updateBalance(-amount);
                destAccount.updateBalance(amount);
                Transaction transactionSrc=new Transaction(-amount);
                srcAccount.addTransaction(transactionSrc);
                Transaction transactionDest=new Transaction(amount);
                destAccount.addTransaction(transactionDest);
                return 0;
            }
            else{
                //System.out.println("Source Account doesn't have enough stock");
                return -1;
            }
        }
        else {
            System.out.println("This account doesn't belong to this user");
            return -1;
        }
    }
    public int checkBalance(Account account){
        if(accountList.contains(account)){
            System.out.println(account.getBalance());
            return 0;
        }
        else {
            System.out.println("This account doesn't belong to this user");
            return -1;
        }
    }
    public void printAllAvailableAccounts(){
        int i;
        for(i=0;i<accountList.size();i++){
            System.out.printf("Account %d: ",i+1);
            accountList.get(i).printAccountData(1);
        }
    }
    public void printUserData(){
        System.out.printf("%s %s %s\n",firstName,lastName,id);
    }
}