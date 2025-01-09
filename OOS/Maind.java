import java.util.ArrayList;
class Employee {
    private String name;
    private int id;
    private String address;
    private double salary;

    public Employee(String name, int id, String address, double salary) {
        this.name = name;
        this.id = id;
        this.address = address;
        this.salary = salary;
    }

    public double getSalary() {
        return salary;
    }

    public void displayDetails() {
        System.out.println("ID: " + id + ", Name: " + name + ", Address: " + address + ", Salary: " + salary);
    }
}

class Dept {
    private String name;
    private String location;
    private ArrayList<Employee> employees;

    public Dept(String name, String location) {
        this.name = name;
        this.location = location;
        this.employees = new ArrayList<>();
    }

    public void add(Employee employee) {
        employees.add(employee);
    }

    public void remove(int employeeId) {
        employees.removeIf(employee -> employee.getSalary() == employeeId);
    }

    public double calculateYearlyExpenditure() {
        double total = 0;
        for (Employee employee : employees) {
            total += employee.getSalary();
        }
        return total * 12;
    }

    public void displayDetails() {
        System.out.println("Department Name: " + name + ", Location: " + location);
        for (Employee employee : employees) {
            employee.displayDetails();
        }
    }
}

public class Maind {
    public static void main(String[] args) {
        Dept itDept = new Dept("Information Technology", "Salt Lake");

        Employee emp1 = new Employee("Mehendi", 101, "Belgharia", 6000);
        Employee emp2 = new Employee("Arnob", 102, "Sodepur", 7000);
        Employee emp3 = new Employee("Debodit", 103, "Kudghat", 5000);
        Employee emp4 = new Employee("Aritra", 104, "Newtown", 6500);
        Employee emp5 = new Employee("Touseef", 105, "Vizag", 7200);

        itDept.add(emp1);
        itDept.add(emp2);
        itDept.add(emp3);
        itDept.add(emp4);
        itDept.add(emp5);

        System.out.println("Department Details:");
        itDept.displayDetails();

        System.out.println("\nYearly Expenditure: " + itDept.calculateYearlyExpenditure());
    }
}
