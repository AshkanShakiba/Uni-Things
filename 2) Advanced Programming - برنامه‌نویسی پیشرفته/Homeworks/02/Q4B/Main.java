import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int number;
        String command="";
        Scanner input=new Scanner(System.in);
        LinkedList linkedList=new LinkedList();
        ArrayList<String> output=new ArrayList<String>();
        while(!command.equals("finish")){
            command=input.next();
            if(command.equals("add")){
                number=input.nextInt();
                linkedList.add(number);
            }
            if(command.equals("addFirst")){
                number=input.nextInt();
                linkedList.addFirst(number);
            }
            if(command.equals("findMiddle")){
                linkedList.findMiddle();
            }
            if(command.equals("removeMiddle")){
                linkedList.removeMiddle();
            }
            if(command.equals("print")){
                linkedList.print();
            }
            if(command.equals("contains")){
                number=input.nextInt();
                linkedList.contains(number);
            }
            if(command.equals("removeIndex")){
                number=input.nextInt();
                linkedList.removeIndex(number);
            }
        }
    }
}