import java.util.ArrayList;
import java.util.Random;

/**
 * The type Card set.
 */
public class CardSet {
    private ArrayList<Card> cards;
    private Random random;

    /**
     * Instantiates a new Card set.
     */
    public CardSet(){
        cards=new ArrayList<>();
        random=new Random();
        int i,j;
        for(i=1;i<=4;i++){
            for(j=1;j<=13;j++){
                Card card;
                if(j==1){
                    card=new CardA(i);
                }
                else if(j==2){
                    card=new Card2(i);
                }
                else if(j==7){
                    card=new Card7(i);
                }
                else if(j==8){
                    card=new Card8(i);
                }
                else if(j==10){
                    card=new Card10(i);
                }
                else if(j==11){
                    card=new CardB(i);
                }
                else{
                    card=new Card(i,j);
                }
                cards.add(card);
            }
        }
    }

    /**
     * New card card.
     *
     * @return the card
     */
    public Card newCard(){
        Card card=cards.get(random.nextInt(cards.size()));
        cards.remove(card);
        return card;
    }

    /**
     * Add card.
     *
     * @param card the card
     */
    public void addCard(Card card){
        cards.add(card);
    }
}