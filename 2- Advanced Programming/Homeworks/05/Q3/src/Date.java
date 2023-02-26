/**
 * The type Date.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Date {
    private int year;
    private int month;
    private int day;

    /**
     * Instantiates a new Date.
     *
     * @param year  the year
     * @param month the month
     * @param day   the day
     */
    public Date(int year,int month,int day){
        this.year=year;
        this.month=month;
        this.day=day;
    }

    /**
     * To get details as String
     *
     * @return the String
     */
    @Override
    public String toString(){
        String date="";
        date+=year+"/";
        if(month<10)
            date+="0";
        date+=month+"/";
        if(day<10)
            date+="0";
        date+=day;
        return date;
    }
}