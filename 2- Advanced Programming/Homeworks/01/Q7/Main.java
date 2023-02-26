import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int i, j;
        String s1, s2, tmp;
        Scanner input = new Scanner(System.in);
        s1 = input.next();
        s2 = input.next();
        if (s1.length() == s2.length()) {
            if (s1.equals(s2)) {
                System.out.println("False");
            } else {
                for (i = 0; i < s1.length(); i++) {
                    tmp = s1;
                    tmp = tmp.replace(tmp.charAt(i), s2.charAt(i));
                    if (tmp.equals(s2)) {
                        System.out.println("True");
                        break;
                    }
                    if (i == s1.length() - 1) {
                        System.out.println("False");
                    }
                }
            }
        } else if (s1.length() - s2.length() == 1) {
            for (i = 0; i < s1.length(); i++) {
                tmp = "";
                for (j = 0; j < s1.length(); j++) {
                    if (j != i) {
                        tmp = tmp + s1.charAt(j);
                    }
                }
                if (tmp.equals(s2)) {
                    System.out.println("True");
                    break;
                }
                if (i == s1.length() - 1) {
                    System.out.println("False");
                }
            }
        } else if (s2.length() - s1.length() == 1) {
            for (i = 0; i < s2.length(); i++) {
                tmp = "";
                for (j = 0; j < s2.length(); j++) {
                    if (j != i) {
                        tmp = tmp + s2.charAt(j);
                    }
                }
                if (tmp.equals(s1)) {
                    System.out.println("True");
                    break;
                }
                if (i == s2.length() - 1) {
                    System.out.println("False");
                }
            }
        } else {
            System.out.println("False");
        }
    }
}