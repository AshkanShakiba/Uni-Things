import java.util.Scanner;

/**
 * The main class of program to run it
 * @author Ashkan Shakiba
 * @version 0.0 (4.17.2021)
 */
public class Main {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        String string=scanner.nextLine();
        Scanner input=new Scanner(string);
        LinkedList linkedList=new LinkedList();
        Stack stack=new Stack(100);
        while(input.hasNextInt()) {
            linkedList.add(input.nextInt());
        }
        linkedList.linkedListToStack(stack);
        LinkedList reverseLinkedList=new LinkedList();
        stack.stackToLinkedList(reverseLinkedList);
        reverseLinkedList.print();
    }
}