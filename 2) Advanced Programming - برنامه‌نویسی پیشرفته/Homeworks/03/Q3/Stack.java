/**
 * This is an integer Stack! a kind of data structure to save integer numbers
 * @author Ashkan Shakiba
 * @version 0.0 (4.17.2021)
 */
public class Stack {
    int index=0;
    private int[] array;

    /**
     * to make a new stack
     * @param size determines the capacity of stack
     */
    public Stack(int size){
        array=new int[size];
    }

    /**
     * to add a new number to the stack
     * @param num the new number
     */
    public void push(int num){
        if(!isFull()){
            array[index]=num;
            index++;
        }
    }

    /**
     * to remove the top number of stack
     * @return the removed number
     */
    public int pop(){
        int num=array[index-1];
        index--;
        return num;
    }

    /**
     * return the top number of stack without removing it
     * @return the top number of stack
     */
    public int peek(){
        return array[index];
    }

    /**
     * if the stack is empty or not
     * @return true if empty, false if not
     */
    public boolean isEmpty(){
        if(index==0)
            return true;
        return false;
    }

    /**
     * if the stack is full or not
     * @return true if full, false if not
     */
    public boolean isFull(){
        if(index==array.length)
            return true;
        return false;
    }

    /**
     * to copy  data from the stack to a linked list
     * @param linkedList where we want to put our data
     */
    public void stackToLinkedList(LinkedList linkedList){
        while (!isEmpty()){
            linkedList.add(pop());
        }
    }
}