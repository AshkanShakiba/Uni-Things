/**
 * The type Match.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Match {
    private Date date;
    private Club home;
    private Club away;

    /**
     * Instantiates a new Match.
     *
     * @param date the date of match
     * @param home the home club of match
     * @param away the away club of match
     */
    public Match(Date date,Club home,Club away){
        this.date=date;
        this.home=home;
        this.away=away;
    }
}