import java.util.Random;

/**
 * The type Bot.
 */
public class Bot extends Player{

    /**
     * Instantiates a new Bot.
     *
     * @param number the number
     */
    public Bot(int number){
        super(number);
    }

    @Override
    public boolean move(Card lastCard){
        char nextColor=Main.game.getNextColor();
        if(nextColor=='N'){
            int punishment=Main.game.getPunishment();
            if(punishment==0){
                if(canMove(lastCard)){
                    Card card=chooseCard();
                    while(!card.isCompatible(lastCard)){
                        card=chooseCard();
                    }
                    removeCard(card);
                    Main.game.putCard(card);
                    if(cards.size()==0){
                        Graphic.delayedMessage(toString()+" played its turn");
                        return true;
                    }
                    card.act(this);
                }
                else{
                    addCard(Main.game.newCard());
                    if(canMove(lastCard)){
                        move(lastCard);
                    }
                }
            }
            else{
                if(canMove()){
                    Card card=chooseCard();
                    while(card.getLetter()!='7'){
                        card=chooseCard();
                    }
                    removeCard(card);
                    Main.game.putCard(card);
                    if(cards.size()==0){
                        Graphic.delayedMessage(toString()+" played its turn");
                        return true;
                    }
                    card.act(this);
                }
                else{
                    for(int i=0;i<punishment;i++){
                        addCard(Main.game.newCard());
                    }
                    Main.game.removePunishment();
                }
            }
        }
        else {
            if(canMove(nextColor)){
                Card card=chooseCard();
                while(!card.isCompatible(nextColor)){
                    card=chooseCard();
                }
                removeCard(card);
                Main.game.putCard(card);
                if(cards.size()==0){
                    Graphic.delayedMessage(toString()+" played its turn");
                    return true;
                }
                Main.game.setNextColor('N');
                card.act(this);
            }
            else{
                addCard(Main.game.newCard());
                if(canMove(nextColor)){
                    move(lastCard);
                }
            }
        }
        Graphic.delayedMessage(toString()+" played its turn");
        return false;
    }


    private Card chooseCard(){
        Random random=new Random();
        int choice=random.nextInt(cards.size());
        return cards.get(choice);
    }

    @Override
    public void giveCard(Card lastCard){
        Random random=new Random();
        int choice=random.nextInt(Main.game.getPlayers().size());
        if(choice!=number){
            Card card=cards.get(random.nextInt(cards.size()));
            removeCard(card);
            Main.game.getPlayers().get(choice).addCard(card);
        }
        else {
            giveCard(lastCard);
        }
    }

    @Override
    public void setNextColor(Card lastCard){
        Random random=new Random();
        int choice=random.nextInt(4)+1;
        if(choice==1){
            Main.game.setNextColor('R');
        }
        if(choice==2){
            Main.game.setNextColor('G');
        }
        if(choice==3){
            Main.game.setNextColor('B');
        }
        if(choice==4){
            Main.game.setNextColor('D');
        }
    }

    @Override
    public String toString(){
        return "Player "+number+"(Bot)";
    }
}