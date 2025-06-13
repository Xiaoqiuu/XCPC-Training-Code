public class Car extends Vehicle {
    int passengerCount;

    public Car() {
        super();
    }

    public Car(int wheels, double weight) {
        super(wheels, weight);
        this.passengerCount = passengerCount;
    }

    void displayInfo() {
        super.displayInfo();
        System.out.println("Passenger Count: " + passengerCount);
    }
}