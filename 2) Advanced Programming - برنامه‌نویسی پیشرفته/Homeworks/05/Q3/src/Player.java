import java.util.ArrayList;
import java.util.Iterator;

/**
 * The type Player.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Player implements Publisher{
    private ArrayList<Subscriber> subscribers;
    private String firstName;
    private String lastName;
    private String id;
    private int age;

    /**
     * Instantiates a new Player.
     *
     * @param firstName the first name of player
     * @param lastName  the last name of player
     * @param id        the id of player
     * @param age       the age of player
     */
    public Player(String firstName,String lastName,String id,int age){
        subscribers=new ArrayList<>();
        this.firstName=firstName;
        this.lastName=lastName;
        this.id=id;
        this.age=age;
    }

    /**
     * Subscribe the player.
     *
     * @param subscriber the subscriber who subscribes
     */
    public void subscribe(Subscriber subscriber){
        subscribers.add(subscriber);
    }

    public void notifySubscribers(Notification notification){
        Iterator<Subscriber> iterator=subscribers.iterator();
        while (iterator.hasNext()){
            iterator.next().update(notification);
        }
    }
}