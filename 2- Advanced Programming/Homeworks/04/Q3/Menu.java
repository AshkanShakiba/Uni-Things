import java.util.Scanner;
import java.io.IOException;

/**
 * The type Menu.
 */
public class Menu{
    private static int choice;
    private static Scanner input=new Scanner(System.in);

    /**
     * Main menu.
     */
    public static void mainMenu(){
        cls();
        Graphic.message("1. Play\n2. Theme\n3. Exit");
        choice=input.nextInt();
        switch (choice){
            case 1:
                numberOfUsers();
                break;
            case 2:
                chooseTheme();
                break;
            case 3:
                System.exit(0);
                break;
            default:
                invalidInput();
                mainMenu();
        }
    }
    private static void numberOfUsers(){
        cls();
        Graphic.message("Enter number of human players\n(it must be between 1 and 5)");
        choice=input.nextInt();
        if(1<=choice && choice<=5){
            numberOfBots(choice);
        }
        else{
            invalidInput();;
            numberOfUsers();
        }
    }
    private static void numberOfBots(int numberOfUsers){
        cls();
        if(numberOfUsers==5){
            Main.game.addUsers(numberOfUsers,0);
        }
        if(numberOfUsers==4){
            Graphic.message("Enter number of bot players\n(it must be between 0 and 1)");
            choice=input.nextInt();
            if(0<=choice && choice<=1){
                Main.game.addUsers(numberOfUsers,choice);
            }
            else{
                invalidInput();
                numberOfBots(numberOfUsers);
            }
        }
        if(numberOfUsers<=3){
            Graphic.message("Enter number of bot players\n(it must be between "+(3-numberOfUsers)+" and "+(5-numberOfUsers)+")");
            choice=input.nextInt();
            if(3-numberOfUsers<=choice && choice<=5-numberOfUsers){
                Main.game.addUsers(numberOfUsers,choice);
            }
            else{
                invalidInput();
                numberOfBots(numberOfUsers);
            }
        }
    }
    private static void chooseTheme(){
        cls();
        Graphic.message("1. Default Theme\n2. Classic Theme\n3. Tiny Star Theme");
        choice=input.nextInt();
        switch (choice){
            case 1:
                Main.theme=new Theme(1);
                break;
            case 2:
                Main.theme=new Theme(2);
                break;
            case 3:
                Main.theme=new Theme(3);
                break;
            default:
                invalidInput();
                chooseTheme();
        }
        Graphic.message("Theme Changed successfully, Press Enter key to back");
        input.nextLine();
        mainMenu();
    }

    /**
     * Invalid input.
     */
    public static void invalidInput(){
        Graphic.message("Invalid input, Press Enter key to try again");
        input.nextLine();
    }

    /**
     * Cls.
     */
    public static void cls(){
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            }
            else {
                System.out.print("\033\143");
            }
        } catch (IOException | InterruptedException ex) {}

        System.out.println("---");
    }
}