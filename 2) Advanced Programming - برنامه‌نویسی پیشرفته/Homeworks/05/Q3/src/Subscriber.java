/**
 * The interface of Subscribers.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public interface Subscriber {
    /**
     * Update the feed of subscriber.
     *
     * @param notification the notification
     */
    public void update(Notification notification);
}