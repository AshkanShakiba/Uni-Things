/**
 * The type Card 2.
 */
public class Card2 extends Card{
    /**
     * Instantiates a new Card 2.
     *
     * @param color the color
     */
    public Card2(int color){
        super(color,2);
    }

    @Override
    public void act(Player player){
        player.giveCard(this);
    }
}