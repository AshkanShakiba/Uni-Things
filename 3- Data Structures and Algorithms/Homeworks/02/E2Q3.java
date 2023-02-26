//import java.io.BufferedReader;
//import java.io.IOException;
//import java.io.InputStreamReader;
//import java.util.StringTokenizer;
//
//public class E2Q3 {
//    static ConsoleScanner input = new ConsoleScanner();
//
//    public static void main(String[] args) {
//        int q, i, n;
//        String command;
//        Queue queue = new Queue();
//
//        q = input.nextInt();
//        for (i = 0; i < q; i++) {
//            command = input.next();
//            if (command.equals("front")) {
//                n = queue.front_command();
//                if (n < 0) {
//                    System.out.println("No job :)");
//                } else {
//                    System.out.println(n);
//                }
//            } else if (command.equals("back")) {
//                n = queue.back_command();
//                if (n < 0) {
//                    System.out.println("No job :)");
//                } else {
//                    System.out.println(n);
//                }
//            } else if (command.equals("reverse")) {
//                queue.reverse();
//            } else if (command.equals("to_front")) {
//                n = input.nextInt();
//                if (queue.size < 50000) {
//                    queue.to_front_command(n);
//                } else {
//                    System.out.println("No more space :(");
//                }
//            } else if (command.equals("push_back")) {
//                n = input.nextInt();
//                if (queue.size < 50000) {
//                    queue.push_back_command(n);
//                } else {
//                    System.out.println("No more space :(");
//                }
//            } else {
//                System.out.println("Invalid Input, Try again...");
//                i--;
//            }
//            // queue.print();
//        }
//    }
//}
//
//class Queue {
//    int size;
//    Node head;
//    Node end;
//    boolean isReversed;
//
//    Queue() {
//        size = 0;
//        head = null;
//        end = null;
//        isReversed = false;
//    }
//
//    int front_command() {
//        if (isReversed)
//            return back();
//        return front();
//    }
//
//    int back_command() {
//        if (isReversed)
//            return front();
//        return back();
//    }
//
//    void to_front_command(int value) {
//        if (isReversed)
//            push_back(value);
//        else
//            to_front(value);
//    }
//
//    void push_back_command(int value) {
//        if (isReversed)
//            to_front(value);
//        else
//            push_back(value);
//    }
//
//    int front() {
//        int value;
//        if (size == 0) {
//            return -1;
//        }
//        size--;
//        value = head.value;
//        if (size == 0) {
//            head = end = null;
//        } else {
//            head = head.next;
//            if (head != null)
//                head.prev = null;
//        }
//        return value;
//    }
//
//    int back() {
//        int value;
//        if (size == 0) {
//            return -1;
//        }
//        size--;
//        value = end.value;
//        if (size == 0) {
//            head = end = null;
//        } else {
//            end = end.prev;
//            if (end != null)
//                end.next = null;
//        }
//        return value;
//    }
//
//    void reverse() {
//        isReversed = !isReversed;
//    }
//
//    void to_front(int value) {
//        Node node;
//        if (head == null) {
//            node = new Node(value, null, null);
//            head = end = node;
//        } else {
//            node = new Node(value, null, head);
//            head.prev = node;
//            head = node;
//        }
//        size++;
//    }
//
//    void push_back(int value) {
//        Node node;
//        if (end == null) {
//            node = new Node(value, null, null);
//            head = end = node;
//        } else {
//            node = new Node(value, end, null);
//            end.next = node;
//            end = node;
//        }
//        size++;
//    }
//
//    void print() {
//        Node node = head;
//        System.out.print("[");
//        for (int i = 0; i < size - 1; i++) {
//            System.out.print(node.value + ", ");
//            node = node.next;
//        }
//        if (node != null) {
//            System.out.print(node.value);
//        }
//        System.out.print("] -> head: ");
//        if (head != null) {
//            System.out.print(head.value);
//        } else {
//            System.out.print("null");
//        }
//        System.out.print(", end: ");
//        if (end != null) {
//            System.out.println(end.value);
//        } else {
//            System.out.println("null");
//        }
//    }
//}
//
//class Node {
//    int value;
//    Node prev;
//    Node next;
//
//    Node(int value, Node prev, Node next) {
//        this.value = value;
//        this.prev = prev;
//        this.next = next;
//    }
//}
//
//class ConsoleScanner {
//    BufferedReader bufferedReader;
//    StringTokenizer stringTokenizer;
//
//    public ConsoleScanner() {
//        bufferedReader = new BufferedReader(new InputStreamReader(System.in));
//    }
//
//    String next() {
//        while (stringTokenizer == null || !stringTokenizer.hasMoreElements()) {
//            try {
//                stringTokenizer = new StringTokenizer(bufferedReader.readLine());
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//        }
//        return stringTokenizer.nextToken();
//    }
//
//    int nextInt() {
//        return Integer.parseInt(next());
//    }
//
//    long nextLong() {
//        return Long.parseLong(next());
//    }
//
//    double nextDouble() {
//        return Double.parseDouble(next());
//    }
//
//    String nextLine() {
//        String string = "";
//        try {
//            string = bufferedReader.readLine();
//        } catch (IOException e) {
//            e.printStackTrace();
//        }
//        return string;
//    }
//}