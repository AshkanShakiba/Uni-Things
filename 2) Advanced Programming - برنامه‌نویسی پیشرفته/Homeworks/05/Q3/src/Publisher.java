/**
 * The interface of Publishers.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public interface Publisher {
    /**
     * Notify subscribers.
     *
     * @param notification the notification
     */
    public void notifySubscribers(Notification notification);
}