/**
 * The type Follower.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Follower implements Subscriber{
    private String name;

    /**
     * Instantiates a new Follower.
     *
     * @param name the name of follower
     */
    public Follower(String name){
        this.name=name;
    }

    /**
     * To send a notification for the follower
     *
     * @param notification the notification
     */
    @Override
    public void update(Notification notification){
        UserInterface.Message("\uD83D\uDC64 "+name+":");
        UserInterface.Message(notification.toString());
    }
}