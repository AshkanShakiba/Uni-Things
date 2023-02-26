/**
 * The type Card 7.
 */
public class Card7 extends Card{
    /**
     * Instantiates a new Card 7.
     *
     * @param color the color
     */
    public Card7(int color){
        super(color,7);
    }

    @Override
    public void act(Player player){
        if(color=='D'){
            Main.game.increasePunishment(4);
        }
        else {
            Main.game.increasePunishment(2);
        }
    }
}