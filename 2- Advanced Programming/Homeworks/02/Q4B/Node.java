public class Node {
    private int num;
    private Node next;
    private Node prev;
    public Node(int num){
        next=null;
        prev=null;
        this.num=num;
    }
    public int getNum(){
        return num;
    }
    public Node getNext(){
        return next;
    }
    public Node getPrev(){
        return prev;
    }
    public void setNext(Node next){
        this.next=next;
    }
    public void setPrev(Node prev){
        this.prev=prev;
    }
}