import java.util.ArrayList;
import java.util.Iterator;

/**
 * The type Graphic.
 */
public class Graphic {
    /**
     * The constant RESET.
     */
    public static final String RESET = "\u001B[0m";
    /**
     * The constant BLACK.
     */
    public static final String BLACK = "\u001B[30m";
    /**
     * The constant WHITE.
     */
    public static final String WHITE = "\u001B[37m";
    /**
     * The constant RED.
     */
    public static final String RED = "\u001B[31m";
    /**
     * The constant YELLOW.
     */
    public static final String YELLOW = "\u001B[33m";
    /**
     * The constant GREEN.
     */
    public static final String GREEN = "\u001B[32m";
    /**
     * The constant CYAN.
     */
    public static final String CYAN = "\u001B[36m";
    /**
     * The constant BLUE.
     */
    public static final String BLUE = "\u001B[34m";
    /**
     * The constant PURPLE.
     */
    public static final String PURPLE = "\u001B[35m";

    /**
     * The constant BLACK_BACKGROUND.
     */
    public static final String BLACK_BACKGROUND = "\u001B[40m";
    /**
     * The constant WHITE_BACKGROUND.
     */
    public static final String WHITE_BACKGROUND = "\u001B[47m";
    /**
     * The constant RED_BACKGROUND.
     */
    public static final String RED_BACKGROUND = "\u001B[41m";
    /**
     * The constant YELLOW_BACKGROUND.
     */
    public static final String YELLOW_BACKGROUND = "\u001B[43m";
    /**
     * The constant GREEN_BACKGROUND.
     */
    public static final String GREEN_BACKGROUND = "\u001B[42m";
    /**
     * The constant CYAN_BACKGROUND.
     */
    public static final String CYAN_BACKGROUND = "\u001B[46m";
    /**
     * The constant BLUE_BACKGROUND.
     */
    public static final String BLUE_BACKGROUND = "\u001B[44m";
    /**
     * The constant PURPLE_BACKGROUND.
     */
    public static final String PURPLE_BACKGROUND = "\u001B[45m";

    /**
     * Message.
     *
     * @param message the message
     */
    public static void message(String message){
        System.out.println(message);
    }

    /**
     * Delayed message.
     *
     * @param message the message
     */
    public static void delayedMessage(String message){
        System.out.println(message);
        //Thread.sleep(1000);
    }

    /**
     * Show.
     *
     * @param player   the player
     * @param lastCard the last card
     */
    public static void show(Player player,Card lastCard){
        Menu.cls();
        Main.theme.set();
        printCard(lastCard);
        if(Main.game.getNextColor()!='N'){
            Graphic.message("Next Color: "+colorToString(Main.game.getNextColor()));
        }
        if(Main.game.getPunishment()!=0){
            Graphic.message("Punishment: "+Main.game.getPunishment());
        }
        if(Main.theme.getType()==1)
            printCards1(player.getCards());
        if(Main.theme.getType()==2){
            printCards2(player.getCards());
        }
        if(Main.theme.getType()==3){
            printCards3(player.getCards());
        }
        Graphic.message(player.toString());
        Graphic.message(Main.game.getDirection());
    }
    private static void printCard(Card card){
        if(Main.theme.getType()==3){
            Graphic.message(card.getColorAsString()+card.getCardAsString());
            return;
        }
        String string=card.getColorAsString();
        string+="╔═══════╕\n";
        string+="║"+card.getLetterAsString(1)+"    │\n";
        string+="║       │\n";
        string+="║    "+card.getLetterAsString(2)+"│\n";
        string+="╙───────┘\n";
        string+=Main.theme.getTEXT();

        Graphic.message(string);
    }
    private static void printCards1(ArrayList<Card> cards){
        String string="";
        Iterator<Card> iterator;
        Card card=new Card(0,0);

        iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+="╔═══";
        }
        string+="════╕\n";

        iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+="║"+card.getLetterAsString(1);
        }
        string+="    │\n";

        iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+="║   ";
        }
        string+="    │\n";

        iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+="║   ";
        }
        string+=" "+card.getLetterAsString(2)+"│\n";

        iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+="╙───";
        }
        string+="────┘\n";
        string+=PURPLE;
        int index=1;

        iterator=cards.iterator();
        while (iterator.hasNext()){
            iterator.next();
            string+="  "+index+" ";
            index++;
        }
        string+="\n";
        string+=Main.theme.getTEXT();

        Graphic.message(string);
    }

    private static void printCards2(ArrayList<Card> cards){
        Card card;
        int index=1;
        String string="";
        Iterator<Card> iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+="╔═══════╕\n";
            string+="║"+card.getLetterAsString(1)+"    │\n";
            string+="║       │\n";
            string+="║    "+card.getLetterAsString(2)+"│\n";
            string+="╙───────┘ "+Main.theme.getINDEX()+index+"\n";
            index++;
        }
        string+=Main.theme.getTEXT();

        Graphic.message(string);
    }

    private static void printCards3(ArrayList<Card> cards){
        Card card;
        int index=1;
        String string="";
        Iterator<Card> iterator=cards.iterator();
        while (iterator.hasNext()){
            card=iterator.next();
            string+=card.getColorAsString();
            string+=index+") ";
            string+=card.getCardAsString();
            string+="  ";
            index++;
        }
        string+=Main.theme.getTEXT();

        Graphic.message(string);
    }

    private static String colorToString(char color){
        if(Main.theme.getType()==1){
            switch (color){
                case 'R':
                    return "Red";
                case 'G':
                    return "Green";
                case 'B':
                    return "Blue";
                case 'D':
                    return "Black";
            }
        }
        else {
            switch (color){
                case 'R':
                    return "♥Heart♥";
                case 'G':
                    return "♦Diamond♦";
                case 'B':
                    return "♣Club♣";
                case 'D':
                    return "♠Spade♠";
            }
        }
        return "";
    }
}