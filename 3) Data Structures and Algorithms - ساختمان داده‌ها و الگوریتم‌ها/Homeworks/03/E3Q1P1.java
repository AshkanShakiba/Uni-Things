//// Simple Java program to print PostOrder Traversal(Iterative)
//
//import java.util.Stack;
//
//public class E3Q1P1 {
//    public static void main(String[] args) {
//        PostOrder tree = new PostOrder();
//
//        // Let us create trees shown in above diagram
//        tree.root = new Node(1);
//        tree.root.left = new Node(2);
//        tree.root.right = new Node(3);
//        tree.root.left.left = new Node(4);
//        tree.root.left.right = new Node(5);
//        tree.root.right.left = new Node(6);
//        tree.root.right.right = new Node(7);
//        System.out.println("Post order traversal of binary tree is :");
//        tree.postOrderIterative(tree.root);
//    }
//
//}
//
//// A binary tree node
//class Node {
//    int data;
//    Node left, right;
//
//    Node(int item) {
//        data = item;
//        left = right = null;
//    }
//}
//
//// create a postorder class
//class PostOrder {
//    Node root;
//
//    void postOrderIterative(Node root) {
//        int whiletrue = 0;
//        Stack<Node> stack = new Stack<>();
//        while (true) {
//            whiletrue++;
//            if(root!=null)
//                System.out.println("WHILE(true) : " + root.data);
//            else
//                System.out.println("WHILE(true) : null");
//            while (root != null) {
//                //System.out.println("WHILE(root!=null)");
//                stack.push(root);
//                stack.push(root);
//                root = root.left;
//            }
//            if (stack.empty()) {
//                break;
//            }
//            root = stack.pop();
//            if (!stack.empty() && stack.peek() == root) {
//                root = root.right;
//            } else {
//                //System.out.print(root.data + " ");
//                root = null;
//            }
//        }
//        System.out.println("***" + whiletrue + "***");
//    }
//
//    // Driver program to test above functions
//
//}
