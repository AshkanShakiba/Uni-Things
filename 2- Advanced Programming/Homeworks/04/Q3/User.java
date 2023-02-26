import java.util.Random;
import java.util.Scanner;

/**
 * The type User.
 */
public class User extends Player{

    /**
     * Instantiates a new User.
     *
     * @param number the number
     */
    public User(int number){
        super(number);
    }

    @Override
    public boolean move(Card lastCard){
        char nextColor=Main.game.getNextColor();
        Scanner input=new Scanner(System.in);
        if(nextColor=='N'){
            int punishment=Main.game.getPunishment();
            if(punishment==0){
                if(canMove(lastCard)){
                    Card card=chooseCard(lastCard);
                    while(!card.isCompatible(lastCard)){
                        Graphic.message("You can't select this card, Press Enter key to try again");
                        input.nextLine();
                        card=chooseCard(lastCard);
                    }
                    removeCard(card);
                    Main.game.putCard(card);
                    if(cards.size()==0){
                        return true;
                    }
                    card.act(this);
                }
                else{
                    Graphic.show(this,lastCard);
                    Graphic.message("You don't have any choice, Press Enter key to collect a new card");
                    input.nextLine();
                    addCard(Main.game.newCard());
                    if(canMove(lastCard)){
                        move(lastCard);
                    }
                    else {
                        Graphic.show(this,lastCard);
                        Graphic.message("Press Enter key to continue");
                        input.nextLine();
                    }
                }
            }
            else{
                if(canMove()){
                    Card card=chooseCard(lastCard);
                    while(card.getLetter()!='7'){
                        Graphic.message("You can't select this card, Press Enter key to try again");
                        input.nextLine();
                        card=chooseCard(lastCard);
                    }
                    removeCard(card);
                    Main.game.putCard(card);
                    if(cards.size()==0){
                        return true;
                    }
                    card.act(this);
                }
                else{
                    Graphic.show(this,lastCard);
                    Graphic.message("You don't have any choice, Press Enter key to collect new cards");
                    input.nextLine();
                    for(int i=0;i<punishment;i++){
                        addCard(Main.game.newCard());
                    }
                    Main.game.removePunishment();
                    Graphic.show(this,lastCard);
                    Graphic.message("Press Enter key to continue");
                    input.nextLine();
                }
            }
        }
        else {
            if(canMove(nextColor)){
                Card card=chooseCard(lastCard);
                while(!card.isCompatible(nextColor)){
                    Graphic.message("You can't select this card, Press Enter key to try again");
                    input.nextLine();
                    card=chooseCard(lastCard);
                }
                removeCard(card);
                Main.game.putCard(card);
                if(cards.size()==0){
                    return true;
                }
                Main.game.setNextColor('N');
                card.act(this);
            }
            else{
                Graphic.show(this,lastCard);
                Graphic.message("You don't have any choice, Press Enter key to collect a new card");
                input.nextLine();
                addCard(Main.game.newCard());
                if(canMove(nextColor)){
                    move(lastCard);
                }
                else {
                    Graphic.show(this,lastCard);
                    Graphic.message("Press Enter key to continue");
                    input.nextLine();
                }
            }
        }
        return false;
    }

    private Card chooseCard(Card lastCard){
        Graphic.show(this,lastCard);
        Graphic.message("Select a card by its index");
        Scanner input=new Scanner(System.in);
        int choice=input.nextInt();
        if(1<=choice && choice<=cards.size()){
            return cards.get(choice-1);
        }
        else {
            Menu.invalidInput();
            return chooseCard(lastCard);
        }
    }

    @Override
    public void giveCard(Card lastCard){
        Graphic.show(this,lastCard);
        Graphic.message("Enter a player's number to give a card");
        Scanner input=new Scanner(System.in);
        int choice=input.nextInt();
        if(1<=choice && choice<Main.game.getPlayers().size() && choice!=number){
            Random random=new Random();
            Card card=cards.get(random.nextInt(cards.size()));
            removeCard(card);
            Main.game.getPlayers().get(choice-1).addCard(card);
        }
        else {
            Graphic.message("Invalid input, Press Enter to Try again");
            input.nextLine();
            giveCard(lastCard);
        }
    }

    @Override
    public void setNextColor(Card lastCard){
        Graphic.show(this,lastCard);
        Scanner input=new Scanner(System.in);
        Graphic.message("Choose next color\n1. Red\n2. Green\n3. Blue\n4. Black");
        int choice=input.nextInt();
        if(choice==1){
            Main.game.setNextColor('R');
        }
        else if(choice==2){
            Main.game.setNextColor('G');
        }
        else if(choice==3){
            Main.game.setNextColor('B');
        }
        else if(choice==4){
            Main.game.setNextColor('D');
        }
        else{
            Graphic.message("Invalid Input, Press Enter to try again");
            input.nextLine();
            setNextColor(lastCard);
        }
    }

    @Override
    public String toString(){
        return "Player "+number;
    }
}