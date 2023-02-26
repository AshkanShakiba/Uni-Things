import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int i;
        String key;
        String str;
        Scanner input=new Scanner(System.in);
        key=input.next();
        str=input.next();
        for(i=0;i<str.length();i++){
            System.out.print(Converter.XOR(key,Converter.toBinary(str.charAt(i)))+" ");
        }
    }
}