/**
 * The type Score.
 */
public class Score {
    private String name;
    private int value;

    /**
     * Instantiates a new Score.
     *
     * @param name  the name
     * @param value the value
     */
    public Score(String name, int value){
        this.name=name;
        this.value=value;
    }

    /**
     * Gets value.
     *
     * @return the value
     */
    public int getValue() {
        return value;
    }

    @Override
    public String toString(){
        return name+" "+value;
    }
}