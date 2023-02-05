import java.util.ArrayList;
import java.util.Iterator;

/**
 * The type Player.
 */
abstract public class Player {
    /**
     * The Number.
     */
    protected int number;
    /**
     * The Cards.
     */
    protected ArrayList<Card> cards;

    /**
     * Instantiates a new Player.
     *
     * @param number the number
     */
    protected Player(int number){
        this.number=number;
        cards=new ArrayList<>();
        for(int i=0;i<7;i++){
            cards.add(Main.game.newCard());
        }
    }

    /**
     * Get number int.
     *
     * @return the int
     */
    public int getNumber(){
        return number;
    }

    /**
     * Get cards array list.
     *
     * @return the array list
     */
    public ArrayList<Card> getCards(){
        return cards;
    }

    /**
     * Cards to string string.
     *
     * @return the string
     */
    public String cardsToString(){
        int index=1;
        String res="";
        Iterator<Card> iterator=cards.iterator();
        while (iterator.hasNext()){
            res+=" "+index+iterator.next().toString();
            index++;
        }
        return res;
    }

    /**
     * Add card.
     *
     * @param card the card
     */
    public void addCard(Card card){
        cards.add(card);
    }

    /**
     * Remove card.
     *
     * @param card the card
     */
    public void removeCard(Card card){
        cards.remove(card);
    }

    /**
     * Can move boolean.
     *
     * @param lastCard the last card
     * @return the boolean
     */
    protected boolean canMove(Card lastCard){
        Card card;
        Iterator<Card> iterator=cards.iterator();
        while(iterator.hasNext()){
            card=iterator.next();
            if(card.isCompatible(lastCard)){
                return true;
            }
        }
        return false;
    }

    /**
     * Can move boolean.
     *
     * @param color the color
     * @return the boolean
     */
    protected boolean canMove(char color){
        Card card;
        Iterator<Card> iterator=cards.iterator();
        while(iterator.hasNext()){
            card=iterator.next();
            if(card.isCompatible(color)){
                return true;
            }
        }
        return false;
    }

    /**
     * Can move boolean.
     *
     * @return the boolean
     */
    protected boolean canMove(){
        Card card;
        Iterator<Card> iterator=cards.iterator();
        while(iterator.hasNext()){
            card=iterator.next();
            if(card.getLetter()=='7'){
                return true;
            }
        }
        return false;
    }

    /**
     * Get score int.
     *
     * @return the int
     */
    public int getScore(){
        int score=0;
        Card card;
        Iterator<Card> iterator=cards.iterator();
        while (iterator.hasNext()){
            score+=iterator.next().getScore();
        }
        return score;
    }

    /**
     * Move boolean.
     *
     * @param lastCard the last card
     * @return the boolean
     */
    abstract public boolean move(Card lastCard);

    /**
     * Give card.
     *
     * @param lastCard the last card
     */
    abstract public void giveCard(Card lastCard);

    /**
     * Sets next color.
     *
     * @param lastCard the last card
     */
    abstract public void setNextColor(Card lastCard);
}