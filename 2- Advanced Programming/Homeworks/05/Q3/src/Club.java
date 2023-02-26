import java.util.ArrayList;
import java.util.Iterator;

/**
 * The type Club.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Club implements Publisher{
    private String name;
    private ArrayList<Player> players;
    private ArrayList<Match> upcomingMatches;
    private ArrayList<Subscriber> clubNewsSubscribers;
    private ArrayList<Subscriber> playersNewsSubscribers;
    private ArrayList<Subscriber> upcomingMatchesNewsSubscribers;

    /**
     * Instantiates a new Club.
     *
     * @param name the name of club
     */
    public Club(String name){
        this.name=name;
        players=new ArrayList<>();
        upcomingMatches=new ArrayList<>();
        clubNewsSubscribers=new ArrayList<>();
        playersNewsSubscribers=new ArrayList<>();
        upcomingMatchesNewsSubscribers=new ArrayList<>();
    }

    /**
     * Contract with new players.
     *
     * @param player the player
     */
    public void contract(Player player){
        players.add(player);
    }

    /**
     * Revocation of players' contract.
     *
     * @param player the player
     */
    public void revocation(Player player){
        players.remove(player);
    }

    /**
     * Set schedule of matches.
     *
     * @param match the match
     */
    public void setSchedule(Match match){
        upcomingMatches.add(match);
    }

    /**
     * Pass matches.
     *
     * @param match the match
     */
    public void pass(Match match){
        upcomingMatches.remove(match);
    }

    /**
     * Subscribe all channels of club.
     *
     * @param subscriber the subscriber who subscribes
     */
    public void subscribe(Subscriber subscriber){
        clubNewsSubscribers.add(subscriber);
        playersNewsSubscribers.add(subscriber);
        upcomingMatchesNewsSubscribers.add(subscriber);
    }

    /**
     * Subscribe a specified channel of club.
     *
     * @param type       the type of subscribed news
     * @param subscriber the subscriber who subscribes
     */
    public void subscribe(NotificationType type,Subscriber subscriber){
        if(type==NotificationType.clubNews)
            clubNewsSubscribers.add(subscriber);
        if(type==NotificationType.playersNews)
            playersNewsSubscribers.add(subscriber);
        if(type==NotificationType.upcomingMatchesNews)
            upcomingMatchesNewsSubscribers.add(subscriber);
    }

    /**
     * Notify subscribers.
     *
     * @param notification the notification
     */
    @Override
    public void notifySubscribers(Notification notification){
        Iterator<Subscriber> iterator;
        if(notification.isClubNews()){
            iterator=clubNewsSubscribers.iterator();
            while (iterator.hasNext()){
                iterator.next().update(notification);
            }
        }
        if(notification.isPlayersNews()){
            iterator=playersNewsSubscribers.iterator();
            while (iterator.hasNext()){
                iterator.next().update(notification);
            }
        }
        if(notification.isUpcomingMatchesNews()){
            iterator=upcomingMatchesNewsSubscribers.iterator();
            while (iterator.hasNext()){
                iterator.next().update(notification);
            }
        }
    }

    /**
     * Notify subscribers of a player.
     *
     * @param player       the player
     * @param notification the notification
     */
    public void notifySubscribers(Player player,Notification notification){
        player.notifySubscribers(notification);
    }
}
