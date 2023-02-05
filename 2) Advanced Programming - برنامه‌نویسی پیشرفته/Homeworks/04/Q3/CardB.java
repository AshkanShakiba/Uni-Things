/**
 * The type Card b.
 */
public class CardB extends Card{
    /**
     * Instantiates a new Card b.
     *
     * @param color the color
     */
    public CardB(int color){
        super(color,11);
    }

    @Override
    public void act(Player player){
        player.setNextColor(this);
    }
}