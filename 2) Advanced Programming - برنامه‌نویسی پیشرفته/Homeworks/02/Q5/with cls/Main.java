import java.io.IOException;

public class Main {
    public static User user;
    public static Account account;
    public static BankingSystem myBank=new BankingSystem();
    public static void main(String[] args){
        Menu.mainMenu();
    }
    public static void cls(){
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            }
            else {
                System.out.print("\033\143");
            }
        } catch (IOException | InterruptedException ex) {}
    }
}