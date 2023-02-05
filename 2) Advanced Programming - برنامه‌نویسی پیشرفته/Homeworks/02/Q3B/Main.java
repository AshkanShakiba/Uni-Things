public class Main {
    public static void main(String[] args) {
        // last argument must be an int, not String
        Person p1 = new Person("Ted", "Mosby", 123456);
        p1.express();
        p1.express("Happy");
        p1.print();
    }
    // we can't declare a class in another class
    // each class must have a separated java file
}