/**
 * The type Card.
 */
public class Card {
    /**
     * The Color.
     */
    protected char color;
    /**
     * The Letter.
     */
// R: Red, G: Green, B: Blue, D: Dark
    protected char letter;
    // A, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, B, C, D

    /**
     * Instantiates a new Card.
     *
     * @param color  the color
     * @param letter the letter
     */
    public Card(int color,int letter){
        switch (color){
            case 1:
                this.color='R';
                break;
            case 2:
                this.color='G';
                break;
            case 3:
                this.color='B';
                break;
            case 4:
                this.color='D';
        }
        switch (letter){
            case 1:
                this.letter='A';
                break;
            case 2:
                this.letter='2';
                break;
            case 3:
                this.letter='3';
                break;
            case 4:
                this.letter='4';
                break;
            case 5:
                this.letter='5';
                break;
            case 6:
                this.letter='6';
                break;
            case 7:
                this.letter='7';
                break;
            case 8:
                this.letter='8';
                break;
            case 9:
                this.letter='9';
                break;
            case 10:
                this.letter='0';
                break;
            case 11:
                this.letter='B';
                break;
            case 12:
                this.letter='C';
                break;
            case 13:
                this.letter='D';
        }
    }

    /**
     * Get color char.
     *
     * @return the char
     */
    public char getColor(){
        return color;
    }

    /**
     * Get letter char.
     *
     * @return the char
     */
    public char getLetter(){
        return letter;
    }

    /**
     * Act.
     *
     * @param player the player
     */
    public void act(Player player){}

    /**
     * Is compatible boolean.
     *
     * @param lastCard the last card
     * @return the boolean
     */
    public boolean isCompatible(Card lastCard){
        if(letter=='B' || color==lastCard.getColor() || letter==lastCard.getLetter()){
            return true;
        }
        else{
            return false;
        }
    }

    /**
     * Is compatible boolean.
     *
     * @param color the color
     * @return the boolean
     */
    public boolean isCompatible(char color){
        if (letter=='B' || this.color==color)
            return true;
        return false;
    }

    /**
     * Get score int.
     *
     * @return the int
     */
    public int getScore(){
        if(letter=='A')
            return 11;
        if(letter=='2')
            return 2;
        if(letter=='3')
            return 3;
        if(letter=='4')
            return 4;
        if(letter=='5')
            return 5;
        if(letter=='6')
            return 6;
        if(letter=='7' && color=='D')
            return 15;
        if(letter=='7' && color!='D')
            return 10;
        if(letter=='8')
            return 8;
        if(letter=='9')
            return 9;
        if(letter=='0')
            return 10;
        if(letter=='B')
            return 12;
        if(letter=='C')
            return 12;
        if(letter=='D')
            return 13;
        return 0;
    }

    /**
     * Get letter as string string.
     *
     * @param type the type
     * @return the string
     */
    public String getLetterAsString(int type){
        String string="";
        int themeType=Main.theme.getType();
        if(type==1){
            if(themeType==2){
                if(color=='R')
                    string+="♥";
                if(color=='G')
                    string+="♦";
                if(color=='B')
                    string+="♣";
                if(color=='D')
                    string+="♠";
            }
            else{
                string+=" ";
            }
        }
        if(letter=='0'){
            string+="10";
        }
        else if(type==1){
            if(letter=='B'){
                if(themeType==2)
                    string+="J";
                else
                    string+=letter;
            }
            else if(letter=='C'){
                if(themeType==2)
                    string+="Q";
                else
                    string+=letter;
            }
            else if(letter=='D'){
                if(themeType==2)
                    string+="K";
                else
                    string+=letter;
            }
            else{
                string+=letter;
            }
            string+=" ";
        }
        else if(type==2){
            string+=" ";
            if(letter=='B'){
                if(themeType==2)
                    string+="J";
                else
                    string+=letter;
            }
            else if(letter=='C'){
                if(themeType==2)
                    string+="Q";
                else
                    string+=letter;
            }
            else if(letter=='D'){
                if(themeType==2)
                    string+="K";
                else
                    string+=letter;
            }
            else{
                string+=letter;
            }
        }
        if(type==2){
            if(themeType==2){
                if(color=='R')
                    string+="♥";
                if(color=='G')
                    string+="♦";
                if(color=='B')
                    string+="♣";
                if(color=='D')
                    string+="♠";
            }
            else{
                string+=" ";
            }
        }
        return string;
    }

    /**
     * Get color as string string.
     *
     * @return the string
     */
    public String getColorAsString(){
        switch (color){
            case 'R':
                return Main.theme.getCOLOR1();
            case 'G':
                return Main.theme.getCOLOR2();
            case 'B':
                return Main.theme.getCOLOR3();
            case 'D':
                return Main.theme.getCOLOR4();
        }
        return Graphic.RESET;
    }

    /**
     * Get card as string string.
     *
     * @return the string
     */
    public String getCardAsString(){
        String string="";
        //string+=getColorAsString();
        if(color=='R'){
            if(letter=='A')
                string="\uD83C\uDCB1";
            if(letter=='2')
                string="\uD83C\uDCB2";
            if(letter=='3')
                string="\uD83C\uDCB3";
            if(letter=='4')
                string="\uD83C\uDCB4";
            if(letter=='5')
                string="\uD83C\uDCB5";
            if(letter=='6')
                string="\uD83C\uDCB6";
            if(letter=='7')
                string="\uD83C\uDCB7";
            if(letter=='8')
                string="\uD83C\uDCB8";
            if(letter=='9')
                string="\uD83C\uDCB9";
            if(letter=='0')
                string="\uD83C\uDCBA";
            if(letter=='B')
                string="\uD83C\uDCBB";
            if(letter=='C')
                string="\uD83C\uDCBD";
            if(letter=='D')
                string="\uD83C\uDCBE";
        }
        if(color=='G'){
            if(letter=='A')
                string="\uD83C\uDCC1";
            if(letter=='2')
                string="\uD83C\uDCC2";
            if(letter=='3')
                string="\uD83C\uDCC3";
            if(letter=='4')
                string="\uD83C\uDCC4";
            if(letter=='5')
                string="\uD83C\uDCC5";
            if(letter=='6')
                string="\uD83C\uDCC6";
            if(letter=='7')
                string="\uD83C\uDCC7";
            if(letter=='8')
                string="\uD83C\uDCC8";
            if(letter=='9')
                string="\uD83C\uDCC9";
            if(letter=='0')
                string="\uD83C\uDCCA";
            if(letter=='B')
                string="\uD83C\uDCCB";
            if(letter=='C')
                string="\uD83C\uDCCD";
            if(letter=='D')
                string="\uD83C\uDCCE";
        }
        if(color=='B'){
            if(letter=='A')
                string="\uD83C\uDCD1";
            if(letter=='2')
                string="\uD83C\uDCD2";
            if(letter=='3')
                string="\uD83C\uDCD3";
            if(letter=='4')
                string="\uD83C\uDCD4";
            if(letter=='5')
                string="\uD83C\uDCD5";
            if(letter=='6')
                string="\uD83C\uDCD6";
            if(letter=='7')
                string="\uD83C\uDCD7";
            if(letter=='8')
                string="\uD83C\uDCD8";
            if(letter=='9')
                string="\uD83C\uDCD9";
            if(letter=='0')
                string="\uD83C\uDCDA";
            if(letter=='B')
                string="\uD83C\uDCDB";
            if(letter=='C')
                string="\uD83C\uDCDD";
            if(letter=='D')
                string="\uD83C\uDCDE";
        }
        if(color=='D'){
            if(letter=='A')
                string="\uD83C\uDCA1";
            if(letter=='2')
                string="\uD83C\uDCA2";
            if(letter=='3')
                string="\uD83C\uDCA3";
            if(letter=='4')
                string="\uD83C\uDCA4";
            if(letter=='5')
                string="\uD83C\uDCA5";
            if(letter=='6')
                string="\uD83C\uDCA6";
            if(letter=='7')
                string="\uD83C\uDCA7";
            if(letter=='8')
                string="\uD83C\uDCA8";
            if(letter=='9')
                string="\uD83C\uDCA9";
            if(letter=='0')
                string="\uD83C\uDCAA";
            if(letter=='B')
                string="\uD83C\uDCAB";
            if(letter=='C')
                string="\uD83C\uDCAD";
            if(letter=='D')
                string="\uD83C\uDCAE";
        }
        return string;
    }
}