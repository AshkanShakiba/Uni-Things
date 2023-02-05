/**
 * The type Notification.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Notification {
    private String title;
    private String context;
    private NotificationType type;

    /**
     * Instantiates a new Notification.
     *
     * @param type    the type of notification
     * @param title   the title of notification
     * @param context the context of notification
     */
    public Notification(NotificationType type,String title,String context){
        this.type=type;
        this.title=title;
        this.context=context;
    }

    /**
     * To check if the notification is a club news.
     *
     * @return true if it is, false if not
     */
    public boolean isClubNews(){
        if(type==NotificationType.clubNews)
            return true;
        return false;
    }

    /**
     * To check if the notification is a players news.
     *
     * @return true if it is, false if not
     */
    public boolean isPlayersNews(){
        if(type==NotificationType.playersNews)
            return true;
        return false;
    }

    /**
     * To check if the notification is a upcoming matches news.
     *
     * @return true if it is, false if not
     */
    public boolean isUpcomingMatchesNews(){
        if(type==NotificationType.upcomingMatchesNews)
            return true;
        return false;
    }

    /**
     * To get the notification as String
     *
     * @return the String
     */
    @Override
    public String toString(){
        return "◈ "+title+"\n   "+context;
    }
}