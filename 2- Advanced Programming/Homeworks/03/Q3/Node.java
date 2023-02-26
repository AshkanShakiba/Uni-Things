/**
 * This class only has been designed to be used in LinkedList class and doesn't have any other usage
 * @author Ashkan Shakiba
 * @version 0.0 (4.17.2021)
 */
public class Node {
    private int num;
    private Node next;
    private Node prev;

    /**
     * to make a new node in linked list
     * @param num amount of the node
     */
    public Node(int num){
        next=null;
        prev=null;
        this.num=num;
    }

    /**
     * @return the amount of node
     */
    public int getNum(){
        return num;
    }

    /**
     * @return the next node in the list
     */
    public Node getNext(){
        return next;
    }

    /**
     * @return the previous node in the list
     */
    public Node getPrev(){
        return prev;
    }

    /**
     * to set the next node of list
     * @param next the next one
     */
    public void setNext(Node next){
        this.next=next;
    }

    /**
     * to set the previous node of list
     * @param prev the previous one
     */
    public void setPrev(Node prev){
        this.prev=prev;
    }
}