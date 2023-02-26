/**
 * The type Card 8.
 */
public class Card8 extends Card{
    /**
     * Instantiates a new Card 8.
     *
     * @param color the color
     */
    public Card8(int color){
        super(color,8);
    }

    @Override
    public void act(Player player){
        player.move(this);
    }
}