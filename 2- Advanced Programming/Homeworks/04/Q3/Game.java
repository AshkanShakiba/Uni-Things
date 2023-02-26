import java.util.ArrayList;
import java.util.Iterator;

/**
 * The type Game.
 */
public class Game {
    private int turn;
    private Card lastCard;
    private int punishment;
    private char nextColor;
    private CardSet cardSet;
    private boolean clockwise;
    private ArrayList<Player> players;


    /**
     * Instantiates a new Game.
     */
    public Game(){
        turn=0;
        punishment=0;
        nextColor='N';
        clockwise=true;
        cardSet=new CardSet();
        players=new ArrayList<>();
        lastCard=cardSet.newCard();
    }

    /**
     * Get players array list.
     *
     * @return the array list
     */
    public ArrayList<Player> getPlayers(){
        return players;
    }

    /**
     * Get next color char.
     *
     * @return the char
     */
    public char getNextColor(){
        return nextColor;
    }

    /**
     * Get punishment int.
     *
     * @return the int
     */
    public int getPunishment(){
        return punishment;
    }

    /**
     * Remove punishment.
     */
    public void removePunishment(){
        punishment=0;
    }

    /**
     * Increase punishment.
     *
     * @param amount the amount
     */
    public void increasePunishment(int amount){
        punishment+=amount;
    }

    /**
     * Set next color.
     *
     * @param color the color
     */
    public void setNextColor(char color){
        nextColor=color;
    }

    /**
     * Add users.
     *
     * @param users the users
     * @param bots  the bots
     */
    public void addUsers(int users,int bots){
        for(int i=1;i<=users;i++){
            User user=new User(i);
            players.add(user);
        }
        for(int i=users+1;i<=users+bots;i++) {
            Bot bot = new Bot(i);
            players.add(bot);
        }
    }

    /**
     * Play.
     */
    public void play(){
        boolean winner;
        Player player;
        while (true){
            player=players.get(turn);
            winner=player.move(lastCard);
            if(winner){
                break;
            }
            nextTurn();
        }
        Graphic.message("Player "+(turn+1)+" Wines!");
        scoreboard();

    }

    /**
     * Next turn.
     */
    public void nextTurn(){
        if(clockwise){
            turn++;
            if(turn>=players.size()){
                turn=0;
            }
        }
        else{
            turn--;
            if(turn<0){
                turn=players.size()-1;
            }
        }
    }

    /**
     * New card card.
     *
     * @return the card
     */
    public Card newCard(){
        return cardSet.newCard();
    }

    /**
     * Put card.
     *
     * @param card the card
     */
    public void putCard(Card card){
        cardSet.addCard(lastCard);
        lastCard=card;
    }

    /**
     * Change direction.
     */
    public void changeDirection(){
        if(clockwise==true){
            clockwise=false;
        }
        else{
            clockwise=true;
        }
    }

    /**
     * Get direction string.
     *
     * @return the string
     */
    public String getDirection(){
        if(clockwise)
            return "Clockwise";
        return "Anticlockwise";
    }

    /**
     * Scoreboard.
     */
    public void scoreboard(){
        Player player;
        Scoreboard scoreboard=new Scoreboard();
        Iterator<Player> iterator=players.iterator();
        while (iterator.hasNext()){
            player=iterator.next();
            scoreboard.addScore(player.toString(),player.getScore());
        }
        scoreboard.sort('+');
        scoreboard.print();
    }
}