import java.util.ArrayList;
import java.util.Iterator;

/**
 * The type Scoreboard.
 */
public class Scoreboard {
    private ArrayList<Score> scores;

    /**
     * Instantiates a new Scoreboard.
     */
    public Scoreboard(){
        scores=new ArrayList<>();
    }

    /**
     * Add score.
     *
     * @param score the score
     */
    public void addScore(Score score){
        scores.add(score);
    }

    /**
     * Add score.
     *
     * @param name  the name
     * @param value the value
     */
    public void addScore(String name,int value){
        addScore(new Score(name,value));
    }

    /**
     * Sort.
     *
     * @param type the type
     */
    public void sort(char type){
        int i, j;
        Score temp;
        if(type=='+'){
            for (i = 0; i < scores.size()-1; i++)
                for (j = 0; j < scores.size()-i-1; j++)
                    if (scores.get(j).getValue() > scores.get(j+1).getValue()){
                        temp=scores.get(j);
                        scores.set(j,scores.get(j+1));
                        scores.set(j+1,temp);
                    }
        }
        if(type=='-'){
            for (i = 0; i < scores.size()-1; i++)
                for (j = 0; j < scores.size()-i-1; j++)
                    if (scores.get(j).getValue() < scores.get(j+1).getValue()){
                        temp=scores.get(j);
                        scores.set(j,scores.get(j+1));
                        scores.set(j+1,temp);
                    }
        }
    }

    /**
     * Print.
     */
    public void print(){
        Iterator<Score> iterator=scores.iterator();
        while (iterator.hasNext()){
            System.out.println(iterator.next().toString());
        }
    }
}