//import java.util.ArrayList;
//import java.util.Scanner;
//
//public class E3Q2 {
//    static Scanner scanner = new Scanner(System.in);
//
//    public static void main(String[] args) {
//        ArrayList<Integer> books = new ArrayList<>();
//        while (scanner.hasNextInt()) {
//            books.add(scanner.nextInt());
//        }
//        Tree tree = new Tree();
//        insertBST(tree, books, 0, books.size() - 1);
//        tree.print(books.get(books.size() - 1));
//    }
//
//    static void insertBST(Tree tree, ArrayList<Integer> books, int start, int end) {
//        if (start > end) return;
//        int midBookIndex = start + (int) Math.floor((end - start) / 2.0);
//        tree.insert(books.get(midBookIndex));
//        insertBST(tree, books, start, midBookIndex - 1);
//        insertBST(tree, books, midBookIndex + 1, end);
//    }
//}
//
//class Tree {
//    Node root;
//
//    Tree() {
//        root = null;
//    }
//
//    void print(int maxNumber) {
//        ArrayList<Node> nodes = new ArrayList<>();
//        if (root == null) return;
//        nodes.add(root);
//        Node node;
//        while (nodes.size() > 0) {
//            node = nodes.get(0);
//            nodes.remove(node);
//            if (node != null) {
//                if (node.value >= maxNumber) {
//                    System.out.println(node.value);
//                    return;
//                }
//                nodes.add(node.leftChild);
//                nodes.add(node.rightChild);
//                System.out.print(node.value + " ");
//            } else {
//                System.out.print("null ");
//            }
//        }
//    }
//
//    void insert(int value) {
//        if (root == null) {
//            root = new Node(value, null);
//        } else {
//            insert(root, value);
//        }
//    }
//
//    void insert(Node rootLikeNode, int value) {
//        if (value < rootLikeNode.value) {
//            if (rootLikeNode.leftChild != null)
//                insert(rootLikeNode.leftChild, value);
//            else
//                rootLikeNode.leftChild = new Node(value, rootLikeNode);
//        } else if (rootLikeNode.value < value) {
//            if (rootLikeNode.rightChild != null)
//                insert(rootLikeNode.rightChild, value);
//            else
//                rootLikeNode.rightChild = new Node(value, rootLikeNode);
//        }
//    }
//}
//
//class Node {
//    int value;
//    Node parent;
//    Node leftChild;
//    Node rightChild;
//
//    Node(int value, Node parent) {
//        this(value, parent, null, null);
//    }
//
//    Node(int value, Node parent, Node leftChild, Node rightChild) {
//        this.value = value;
//        this.parent = parent;
//        this.leftChild = leftChild;
//        this.rightChild = rightChild;
//    }
//}