import java.util.ArrayList;
import java.util.Iterator;

public class BankingSystem {
    public ArrayList<User> users;
    public ArrayList<Account> accounts;
    public BankingSystem(){
        users=new ArrayList<User>();
        accounts=new ArrayList<Account>();
    }
    public int register(User user){
        int i;
        for(i=0;i<users.size();i++){
            if(users.get(i).getId().equals(user.getId())){
                return -1;
            }
        }
        addUser(user);
        return 0;
    }
    public User login(String id, String password){
        int i;
        for(i=0;i<users.size();i++){
            if(users.get(i).getId().equals(id)){
                if(users.get(i).getPassword().equals(password)){
                    return users.get(i);
                }
                else{
                    //System.out.println("Password is incorrect");
                    return null;
                }
            }
        }
        //System.out.println("User not found");
        return null;
    }
    public void addUser(User user){
        users.add(user);
    }
    public void removeUser(User user){

        Iterator it=accounts.iterator();
        while(it.hasNext()){
            Account account= (Account) it.next();
            if(account.getId().equals(user.getId())){
                //accounts.remove(account);
                it.remove();
            }
        }

        users.remove(user);
    }
    public void displayUsers(){
        int i;
        for(i=0;i<users.size();i++){
            System.out.printf("User %d: ",i+1);
            users.get(i).printUserData();
        }
    }
    public void addAccount(Account account){
        accounts.add(account);
    }
    public void removeAccount(Account account){
        accounts.remove(account);
    }
    public void displayAccounts(){
        int i;
        for(i=0;i<accounts.size();i++){
            System.out.printf("Account %d: ",i+1);
            accounts.get(i).printAccountData(2);
        }
    }
    public Account findAccount(String serial){
        int i;
        for(i=0;i<accounts.size();i++){
            if(accounts.get(i).getSerial().equals(serial)){
                return accounts.get(i);
            }
        }
        System.out.println("User not found");
        return null;
    }
}