/**
 * The type Card a.
 */
public class CardA extends Card{
    /**
     * Instantiates a new Card a.
     *
     * @param color the color
     */
    public CardA(int color){
        super(color,1);
    }

    @Override
    public void act(Player player){
        Main.game.nextTurn();
    }
}