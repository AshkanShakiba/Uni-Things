import java.util.Scanner;

public class Menu {
    static int choice,amount;
    static Scanner input=new Scanner(System.in);
    public static void mainMenu() {
        Main.cls();
        System.out.println("1. Sign up\n2. Log in\n3. System Admin\n4. Exit");
        choice = input.nextInt();
        switch (choice) {
            case 1:
                signUp();
                break;
            case 2:
                logIn();
                break;
            case 3:
                systemAdminPass();
                break;
            case 4:
                System.exit(0);
                break;
            default:
                System.out.println("Invalid input, Try again");
                mainMenu();
        }
    }
    private static void enter(){

	// This method doesn't do anything in this version; to know more, you can read the "Read Me" file.

	/*
        System.out.println("Press Enter key to continue...");
        input.nextLine();
        input.nextLine();
	*/
    }
    private static void signUp(){
        Main.cls();
        String id,firstName,lastName,password;
        System.out.print("First name: ");
        firstName=input.next();
        System.out.print("Last name: ");
        lastName=input.next();
        System.out.print("ID: ");
        id=input.next();
        System.out.print("Password: ");
        password=input.next();
        User user=new User(id,firstName,lastName,password);
        if(Main.myBank.register(user)==-1){
            System.out.println("user already exists.");
            enter();
            mainMenu();
            return;
        }
        System.out.println("user created.");
        Main.user=user;
        enter();
        userMenu();
    }
    private static void logIn(){
        Main.cls();
        String id,password;
        System.out.print("ID: ");
        id=input.next();
        System.out.print("Password: ");
        password=input.next();
        User user=Main.myBank.login(id,password);
        if(user==null){
            System.out.println("user doesn't exists or password is incorrect.");
            enter();
            logIn();
            return;
        }
        Main.user=user;
        System.out.println("Logged in.");
        enter();
        userMenu();
    }
    private static void userMenu(){
        Main.cls();
        System.out.println("1. Choose account\n2. Create account\n3. Log out");
        choice=input.nextInt();
        switch (choice){
            case 1:
                choose();
                break;
            case 2:
                create();
                break;
            case 3:
                logOut();
                break;
            default:
                System.out.println("Invalid input, Try again");
                enter();
                userMenu();
        }
    }
    private static void choose(){
        Main.cls();
        if(Main.myBank.accounts.size()<1){
            System.out.println("There's not any account yet.");
            enter();
            userMenu();
            return;
        }
        Main.user.printAllAvailableAccounts();
        String s1,s2;
        s1=input.next();
        s2=input.next();
        choice=input.nextInt();
        if(!s1.equals("Account") || !s2.equals("number")){
            System.out.println("Invalid input, Try again");
            enter();
            choose();
            return;
        }
        Main.account=Main.user.getAccount(choice-1);
        if(Main.account==null){
            System.out.println("Invalid index");
            enter();
            choose();
            return;
        }
        System.out.println("Logged into account.");
        enter();
        accountMenu();
    }
    private static void create(){
        Main.cls();
        int amount;
        String id,type;
        /*
        System.out.println("Enter user's ID");
        id=input.next();
        */
        System.out.println("Enter your account's type");
        type=input.next();
        System.out.println("Enter Init amount");
        amount=input.nextInt();
        /*
        if(!Main.user.getId().equals(id)){
            System.out.println("ID is not correct, Try again");
            enter();
            create();
            return;
        }
        */
        Account account=new Account(Main.user.getId(),Main.user.getFirstName(),Main.user.getLastName(),type,amount);
        Main.user.addAccount(account);
        System.out.println("New account opened.");
        enter();
        userMenu();
    }
    private static void logOut(){
        Main.cls();
        Main.user=null;
        System.out.println("Logged out successfully");
        enter();
        mainMenu();
    }
    private static void accountMenu(){
        Main.cls();
        System.out.println("1. WithDrawal\n2. Deposit\n3. Transfer\n4. Check balance\n5. Back");
        choice=input.nextInt();
        switch (choice){
            case 1:
                withdrawal();
                break;
            case 2:
                deposit();
                break;
            case 3:
                transfer();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                Main.cls();
                Main.account=null;
                System.out.println("Logged out of account.");
                userMenu();
                break;
            default:
                System.out.println("Invalid input, Try again");
                enter();
                accountMenu();
        }
    }
    private static void withdrawal(){
        Main.cls();
        System.out.println("Enter amount");
        amount=input.nextInt();
        Main.user.withdrawal(Main.account,amount);
        enter();
        accountMenu();
    }
    private static void deposit(){
        Main.cls();
        System.out.println("Enter amount");
        amount=input.nextInt();
        Main.user.deposit(Main.account,amount);
        enter();
        accountMenu();
    }
    private static void transfer(){
        Main.cls();
        String serial;
        System.out.println("Enter destination account's serial");
        serial=input.next();
        Account account=searchAccount(serial);
        System.out.println("Enter amount");
        amount=input.nextInt();
        if(amount<=0){
            System.out.println("Amount must be more than zero, Try again");
            transfer();
            return;
        }
        if(account==null || Main.user.transfer(Main.account,account,amount)==-1){
            System.out.println("Destination account doesn't exist or there is not enough money in your account.");
        }
        else{
            System.out.println("Completed.");
        }
        enter();
        accountMenu();
    }
    private static Account searchAccount(String serial){
        int i;
        for(i=0;i<Main.myBank.accounts.size();i++){
            if(Main.myBank.accounts.get(i).getSerial().equals(serial)){
                return Main.myBank.accounts.get(i);
            }
        }
        return null;
    }
    private static void checkBalance(){
        Main.cls();
        Main.user.checkBalance(Main.account);
        enter();
        accountMenu();
    }
    private static void systemAdminPass(){
        Main.cls();
        String username,password;
        System.out.print("Username: ");
        username=input.next();
        System.out.print("Password: ");
        password=input.next();
        if(username.equals("sysadmin") && password.equals("1234")){
            System.out.println("Logged in as sysadmin.");
            systemAdmin();
        }
        else{
            System.out.println("Username or password is incorrect.");
            wrongInfo();
        }
    }
    private static void wrongInfo(){
        System.out.println("Press 1 to try again or 2 to back");
        choice=input.nextInt();
        switch (choice){
            case 1:
                systemAdminPass();
                break;
            case 2:
                mainMenu();
                break;
            default:
                System.out.println("Invalid input, Try again");
                enter();
                wrongInfo();
        }
    }
    private static void systemAdmin(){
        Main.cls();
        System.out.println("1. display users\n2. display accounts\n3. remove user\n4. remove account\n5. Back");
        choice=input.nextInt();
        switch (choice){
            case 1:
                Main.cls();
                if(Main.myBank.users.size()<1){
                    System.out.println("There's not any user yet.");
                    enter();
                    systemAdmin();
                    return;
                }
                Main.myBank.displayUsers();
                enter();
                systemAdmin();
                break;
            case 2:
                Main.cls();
                if(Main.myBank.accounts.size()<1){
                    System.out.println("There's not any account yet.");
                    enter();
                    systemAdmin();
                    return;
                }
                Main.myBank.displayAccounts();
                enter();
                systemAdmin();
                break;
            case 3:
                Main.cls();
                User user=chooseUser();
                if(user==null){
                    System.out.println("User doesn't exist.");
                }
                else{
                    Main.myBank.removeUser(user);
                    System.out.println("User removed.");
                }
                enter();
                systemAdmin();
                break;
            case 4:
                Main.cls();
                Account account=chooseAccount();
                if(account==null){
                    System.out.println("Account doesn't exist.");
                }
                else{
                    Main.myBank.removeAccount(account);
                    System.out.println("Account removed.");
                }
                enter();
                systemAdmin();
                break;
            case 5:
                mainMenu();
                break;
            default:
                System.out.println("Invalid input, Try again");
                enter();
                systemAdmin();
        }
    }
    private static User chooseUser(){
        int i;
        String id;
        System.out.println("Enter user's id");
        id=input.next();
        for(i=0;i<Main.myBank.users.size();i++){
            if(Main.myBank.users.get(i).getId().equals(id)){
                return Main.myBank.users.get(i);
            }
        }
        return null;
    }
    private static Account chooseAccount(){
        int i;
        String serial;
        System.out.println("Enter Account's serial");
        serial=input.next();
        for(i=0;i<Main.myBank.accounts.size();i++){
            if(Main.myBank.accounts.get(i).getSerial().equals(serial)){
                return Main.myBank.accounts.get(i);
            }
        }
        return null;
    }
}