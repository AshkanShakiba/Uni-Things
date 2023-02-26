/**
 * The main class to run the program.
 *
 * @author Ashkan Shakiba
 * @version 5/14/2021
 */
public class Main {
    /**
     * Main method to run.
     *
     * @param args System arguments
     */
    public static void main(String[] args){
        // Clubs
        Club MCI=new Club("Manchester City F.C.");
        Club PSG=new Club("Paris Saint-Germain F.C.");
        Club CHE=new Club("Chelsea F.C.");
        Club RMA=new Club("Real Madrid CF");

        // Players
        Player hazard=new Player("Eden","Hazard","0050",30);
        Player deBruyne=new Player("Kevin","De Bruyne","0017",29);
        Player neymar=new Player("Neymar","JR","0010",29);
        Player kante=new Player("N'Golo","Kanté","0007",30);
        Player ramos=new Player("Sergio","Ramos","0004",35);

        // Dates
        Date may4=new Date(2020,5,4); //MCI-PSG
        Date may5=new Date(2020,5,5); //CHE-RMA
        Date may29=new Date(2020,5,29); //MCI-CHE

        //Matches
        Match semiFinal1=new Match(may4,MCI,PSG);
        Match semiFinal2=new Match(may5,CHE,RMA);
        Match finalMatch=new Match(may29,MCI,CHE);

        // Followers
        Follower abbas=new Follower("Abbas Bou Azar");
        Follower ashkan=new Follower("Ashkan Shakiba");
        Follower bachchan=new Follower("Amitabh Bachchan");
        Follower russell=new Follower("Russell Crowe");
        Follower kambiz=new Follower("Kambiz Kazemi");

        // Notifications
        Notification notification0=new Notification(NotificationType.playersNews,"Hazard's Transfer","Eden Hazard signed a contract with Real Madrid until 30 June 2024 for a reported fee of €100 million, which could rise to €146.1 million due to additional fees, on a deal worth £400,000 per week.");
        Notification notification1=new Notification(NotificationType.clubNews,"European Super League","Real Madrid president Florentino Perez says the 12 clubs that agreed to join a new European Super League have \"binding contracts\" and \"cannot leave\".");
        Notification notification2=new Notification(NotificationType.playersNews,"Mbappe's injury","Kylian Mbappe injury doubt ahead of Champions League semi-final second-leg against Man City.");
        Notification notification3=new Notification(NotificationType.upcomingMatchesNews,"Final Match","Man City will face Chelsea in Uefa Champions Leauge's final match on May 29.");
        Notification notification4=new Notification(NotificationType.upcomingMatchesNews,"Final Match","Chelsea will face Man City in Uefa Champions Leauge's final match on May 29.");
        Notification notification5=new Notification(NotificationType.upcomingMatchesNews,"Final match's stadium","The final will be held at the Estádio do Dragão, home of FC Porto.");

        // Subscribing Clubs
        MCI.subscribe(abbas);
        PSG.subscribe(NotificationType.playersNews,ashkan);
        CHE.subscribe(NotificationType.upcomingMatchesNews,bachchan);
        RMA.subscribe(NotificationType.clubNews,russell);

        // Subscribing Players
        hazard.subscribe(kambiz);

        // Contract players
        CHE.contract(hazard);
        MCI.contract(deBruyne);
        PSG.contract(neymar);
        CHE.contract(kante);
        RMA.contract(ramos);

        // Hazard's transfer
        CHE.revocation(hazard);
        RMA.contract(hazard);
        // Notifying subscribers
        RMA.notifySubscribers(hazard,notification0);

        // European Super League
        // Notifying subscribers
        RMA.notifySubscribers(notification1);

        // Planning semi-final
        MCI.setSchedule(semiFinal1);
        PSG.setSchedule(semiFinal1);
        CHE.setSchedule(semiFinal2);
        RMA.setSchedule(semiFinal2);
        // Notifying subscribers
        PSG.notifySubscribers(notification2);

        // Passing semi-final
        MCI.pass(semiFinal1);
        PSG.pass(semiFinal1);
        CHE.pass(semiFinal2);
        RMA.pass(semiFinal2);

        // Planning final
        MCI.setSchedule(finalMatch);
        CHE.setSchedule(finalMatch);
        // Notifying subscribers
        MCI.notifySubscribers(notification3);
        CHE.notifySubscribers(notification4);

        // Changing the stadium
        // Notifying subscribers
        MCI.notifySubscribers(notification5);
        CHE.notifySubscribers(notification5);
    }
}