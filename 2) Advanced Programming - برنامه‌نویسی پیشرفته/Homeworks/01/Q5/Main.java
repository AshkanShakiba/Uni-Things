import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        char o='o';
        Complex a=new Complex();
        Complex b=new Complex();
        Scanner input=new Scanner(System.in);
        a.setR(input.nextFloat());
        a.setI(input.nextFloat());
        b.setR(input.nextFloat());
        b.setI(input.nextFloat());
        while(o!='#'){
            o=input.next().charAt(0);
            switch (o){
                case '+':
                    Calculate.sum(a,b).print();
                    break;
                case '-':
                    Calculate.sub(a,b).print();
                    break;
                case '*':
                    Calculate.mul(a,b).print();
                    break;
                case '/':
                    Calculate.div(a,b).print();
                    break;
                case '#':
                    break;
                default:
                    System.out.println("Undefined");
            }
        }
    }
}