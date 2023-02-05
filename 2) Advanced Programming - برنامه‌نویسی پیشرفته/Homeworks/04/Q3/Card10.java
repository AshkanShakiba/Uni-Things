/**
 * The type Card 10.
 */
public class Card10 extends Card{
    /**
     * Instantiates a new Card 10.
     *
     * @param color the color
     */
    public Card10(int color){
        super(color,10);
    }

    @Override
    public void act(Player player){
        Main.game.changeDirection();
    }
}