/**
 * The type Main.
 */
public class Main {
    /**
     * The constant game.
     */
    public static Game game=new Game();
    /**
     * The constant theme.
     */
    public static Theme theme=new Theme(1);

    /**
     * Main.
     *
     * @param args the args
     */
    public static void main(String[] args){
        Menu.mainMenu();
        game.play();
    }
}