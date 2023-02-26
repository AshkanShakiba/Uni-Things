public class Converter {
    public static String toBinary(char c){
        String r=Integer.toBinaryString(c);
        switch (r.length()){
            case 1:
                r="0000000"+r;
                break;
            case 2:
                r="000000"+r;
                break;
            case 3:
                r="00000"+r;
                break;
            case 4:
                r="0000"+r;
                break;
            case 5:
                r="000"+r;
                break;
            case 6:
                r="00"+r;
                break;
            case 7:
                r="0"+r;
                break;
            case 8:
                r=""+r;
        }
        return r;
    }
    public static String XOR(String a,String b){
        String r="";
        int i;
        for(i=0;i<8;i++){
            r=r+xor(a.charAt(i),b.charAt(i));
        }
        return r;
    }
    private static char xor(char a,char b){
        if(a!=b) return '1';
        else return '0';
    }
}