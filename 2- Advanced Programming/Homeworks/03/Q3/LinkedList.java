/**
 * This is an integer Linked List! a kind of data structure to save integer numbers
 * @author Ashkan Shakiba
 * @version 0.0 (4.17.2021)
 */
public class LinkedList {
    private Node head;
    private Node end;
    private int size;

    /**
     * to make a new linked list
     */
    public LinkedList(){
        size=0;
        head=null;
        end=null;
    }

    /**
     * add a new number to the end of list
     * @param k new number
     */
    public void add(int k){
        Node node=new Node(k);
        if(size==0){
            head=node;
            end=node;
        }
        else{
            end.setNext(node);
            node.setPrev(end);
            end=node;
        }
        size++;
    }

    /**
     * print list's data
     */
    public void print(){
        if(head==null){
            System.out.println();
        }
        else{
            Node curr=head;
            while(curr!=end){
                System.out.print(curr.getNum()+" ");
                curr=curr.getNext();
            }
            System.out.println(curr.getNum());
        }
    }

    /**
     * to copy  data from the linked list to stack
     * @param stack where we want to put our data
     */
    public void linkedListToStack(Stack stack){
        if(size>0) {
            Node curr = head;
            while (curr != end) {
                stack.push(curr.getNum());
                curr = curr.getNext();
            }
            stack.push(curr.getNum());
        }
    }
}