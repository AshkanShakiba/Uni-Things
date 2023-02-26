public class LinkedList {
    private Node head;
    private Node end;
    private int size;
    public LinkedList(){
        size=0;
        head=null;
        end=null;
    }
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
    public void addFirst(int k){
        Node node=new Node(k);
        if(size==0){
            head=node;
            end=node;
        }
        else{
            head.setPrev(node);
            node.setNext(head);
            head=node;
        }
        size++;
    }
    public void findMiddle(){
        if(size==0){
            System.out.println("-1");
            return;
        }
        if(size==1){
            System.out.println(head.getNum());
            return;
        }
        int index=0;
        Node curr=head;
        while(index<size/2-1){
            curr=curr.getNext();
            index++;
        }
        if(size%2==1) {
            curr=curr.getNext();
        }
        System.out.println(curr.getNum());
    }
    public void removeMiddle(){
        if(size==0){
            return;
        }
        if(size==1){
            head=null;
            end=null;
            size--;
            return;
        }
        int index=0;
        Node curr=head;
        while(index<size/2-1){
            curr=curr.getNext();
            index++;
        }
        if(size%2==1) {
            curr=curr.getNext();
        }
        if(curr==head){
            if(curr==end){
                head=null;
                end=null;
            }
            else{
                curr.getNext().setPrev(null);
                head=curr.getNext();
            }
        }
        else if(curr==end){
            curr.getPrev().setNext(null);
            end=curr.getPrev();
        }
        else {
            curr.getPrev().setNext(curr.getNext());
            curr.getNext().setPrev(curr.getPrev());
        }
        size--;
    }
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
    public void contains(int k){
        if(size==0){
            System.out.println("-1");
            return;
        }
        int index=0;
        Node curr=head;
        while(curr!=end){
            if(curr.getNum()==k){
                System.out.println(index);
                return;
            }
            curr=curr.getNext();
            index++;
        }
        if(curr.getNum()==k){
            System.out.println(index);
            return;
        }
        System.out.println("-1");
    }
    public void removeIndex(int i){
        if(i>=size || size==0){
            return;
        }
        int index=0;
        Node curr=head;
        while(index<i){
            curr=curr.getNext();
            index++;
        }
        if(curr==head){
            if(curr==end){
                head=null;
                end=null;
            }
            else{
                curr.getNext().setPrev(null);
                head=curr.getNext();
            }
        }
        else if(curr==end){
            curr.getPrev().setNext(null);
            end=curr.getPrev();
        }
        else {
            curr.getPrev().setNext(curr.getNext());
            curr.getNext().setPrev(curr.getPrev());
        }
        size--;
    }
}