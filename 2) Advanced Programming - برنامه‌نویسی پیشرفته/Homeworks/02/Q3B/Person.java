// Classes can't be "static"!
// we just have to mention if this class is public or private
public class Person {
    // it's not necessary, but it's better to use "firstName" instead of "FirstName" (camelCase)
    private String firstName;
    // and again, it's not necessary, but it's better to use "lastName" instead of "last_name" (camelCase)
    private String lastName;
    private int id;
    // Constructors don't have any return type, so "void" must be removed
    public Person(String firstName, String lastName, int id){
        // if we don't mention "this.", constructor won't do anything, because of same names!
        this.firstName = firstName;
        this.lastName = lastName;
        this.id = id;
    }
    public void express(){
        System.out.println("I feel neutral");
    }
    // this kind of methods, don't need to return anything!
    public void express(String state){
        System.out.println("I feel " + state + " today");
    }
    public void print(){
        // it's better to have all of them in one line
        // it's not too much important, but I think "last name" is more meaningful than "lname", so I replaced it
        System.out.println("Person{" + "name='" + firstName + '\'' + ", last name='" + lastName + '\'' + ", id=" + id + '}');
    }
}