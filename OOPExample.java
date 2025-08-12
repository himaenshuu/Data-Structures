public class OOPExample {

    public static void main(String[] args) {
        // Creating an object of the Dog class
        Dog myDog = new Dog("Buddy", "Golden Retriever");

        // Calling methods on the Dog object
        myDog.bark();
        myDog.displayInfo();

        // Creating an object of the Circle class
        Circle myCircle = new Circle(5.0);

        // Calling methods on the Circle object
        System.out.println("Circle Area: " + myCircle.calculateArea());
        System.out.println("Circle Circumference: " + myCircle.calculateCircumference());
    }
}

// Class representing a Dog (Encapsulation and Abstraction)
class Dog {
    // Instance variables (Encapsulation)
    private String name;
    private String breed;

    // Constructor
    public Dog(String name, String breed) {
        this.name = name;
        this.breed = breed;
    }

    // Method (Behavior)
    public void bark() {
        System.out.println("Woof!");
    }

    // Method to display dog information
    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Breed: " + breed);
    }

    //Getter methods (Encapsulation best practice)
    public String getName() {
      return name;
    }

    public String getBreed(){
      return breed;
    }
}

// Class representing a Circle (Encapsulation and Abstraction)
class Circle {
    // Instance variable
    private double radius;

    // Constructor
    public Circle(double radius) {
        this.radius = radius;
    }

    // Method to calculate area
    public double calculateArea() {
        return Math.PI * radius * radius;
    }

    // Method to calculate circumference
    public double calculateCircumference() {
        return 2 * Math.PI * radius;
    }

    //Getter and setter example
    public double getRadius(){
      return radius;
    }

    public void setRadius(double radius){
      this.radius = radius;
    }
}
