public class Student {
    public String name;
    public int rollNumber;

    public void setDetails(String n, int roll) {
        name = n;
        rollNumber = roll;
    }

    public void displayDetails() {
        System.out.println("Name : " + name);
        System.out.println("Roll Number : " + rollNumber);
    }
}