import java.util.Stack;

public class E2Q1 {
}

class Queue {
    Stack stack1;
    Stack stack2;

    Queue(){
        stack1=new Stack();
        stack2=new Stack();
    }

    void enqueue(Object object){
        stack1.push(object);
    }

    Object dequeue(){
        if(stack1.isEmpty() && stack2.isEmpty()){
            return null; // queue is empty
        }
        else if(!stack1.isEmpty() && stack2.isEmpty()){
            while(!stack1.isEmpty()){
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }
}