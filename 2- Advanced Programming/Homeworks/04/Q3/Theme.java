/**
 * The type Theme.
 */
public class Theme {
    private int type;
    private String TEXT;
    private String INDEX;
    private String COLOR1;
    private String COLOR2;
    private String COLOR3;
    private String COLOR4;
    private String BACKGROUND;

    /**
     * Instantiates a new Theme.
     *
     * @param type the type
     */
// Theme Types: 1) Default  2) Classic  3) Tiny Star
    public Theme(int type) {
        if(type==1){
            TEXT=Graphic.RESET;
            INDEX=Graphic.PURPLE;
            COLOR1=Graphic.RED;
            COLOR2=Graphic.GREEN;
            COLOR3=Graphic.BLUE;
            COLOR4=Graphic.BLACK;
            BACKGROUND="";
        }
        if(type==2){
            TEXT=Graphic.RESET;
            INDEX=Graphic.BLUE;
            COLOR1=Graphic.RED;
            COLOR2=Graphic.RED;
            COLOR3=Graphic.BLACK;
            COLOR4=Graphic.BLACK;
            BACKGROUND="";
            //BACKGROUND=Graphic.WHITE_BACKGROUND;
        }
        if(type==3){
            TEXT=Graphic.RESET;
            COLOR1=Graphic.RED;
            COLOR2=Graphic.RED;
            COLOR3=Graphic.BLACK;
            COLOR4=Graphic.BLACK;
            BACKGROUND="";
            //BACKGROUND=Graphic.BLUE_BACKGROUND;
        }
        this.type=type;
    }

    /**
     * Gets type.
     *
     * @return the type
     */
    public int getType() {
        return type;
    }

    /**
     * Gets text.
     *
     * @return the text
     */
    public String getTEXT() {
        return TEXT;
    }

    /**
     * Gets index.
     *
     * @return the index
     */
    public String getINDEX() {
        return INDEX;
    }

    /**
     * Gets color 1.
     *
     * @return the color 1
     */
    public String getCOLOR1() {
        return COLOR1;
    }

    /**
     * Gets color 2.
     *
     * @return the color 2
     */
    public String getCOLOR2() {
        return COLOR2;
    }

    /**
     * Gets color 3.
     *
     * @return the color 3
     */
    public String getCOLOR3() {
        return COLOR3;
    }

    /**
     * Gets color 4.
     *
     * @return the color 4
     */
    public String getCOLOR4() {
        return COLOR4;
    }

    /**
     * Gets background.
     *
     * @return the background
     */
    public String getBACKGROUND() {
        return BACKGROUND;
    }

    /**
     * Set.
     */
    public void set(){
        System.out.print(BACKGROUND);
        System.out.print(TEXT);
    }
}