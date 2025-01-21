class Employee {
    private String name;
    private int id;
    private String address;
    private float salary;

    public Employee(String name, int id, String address, float salary) {
        this.name = name;
        this.id = id;
        this.address = address;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public int getId() {
        return id;
    }

    public String getAddress() {
        return address;
    }

    public float getSalary() {
        return salary;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void setSalary(float salary) {
        this.salary = salary;
    }

    public void display() {
        System.out.println("ID: " + id + ", Name: " + name + ", Address: " + address + ", Salary: " + salary);
    }
}

class Dept {
    private String name;
    private String location;
    private Employee[] employees;
    private int count;

    public Dept(String name, String location, int maxEmployees) {
        this.name = name;
        this.location = location;
        this.employees = new Employee[maxEmployees];
        this.count = 0;
    }

    public void add(Employee emp) {
        if (count < employees.length) {
            employees[count++] = emp;
            System.out.println("Employee added: " + emp.getName());
        } else {
            System.out.println("Cannot add more employees, department is full.");
        }
    }

    public void remove(int id) {
        for (int i = 0; i < count; i++) {
            if (employees[i].getId() == id) {
                employees[i] = employees[--count];
                employees[count] = null;
                System.out.println("Employee with ID " + id + " removed.");
                return;
            }
        }
        System.out.println("Employee with ID " + id + " not found.");
    }

    public float calExpenditure() {
        float expenditure = 0;
        for (int i = 0; i < count; i++) {
            expenditure += employees[i].getSalary() * 12; 
        }
        return expenditure;
    }

    public void details() {
        System.out.println("Department Name: " + name);
        System.out.println("Location: " + location);
        System.out.println("Employees:");
        for (int i = 0; i < count; i++) {
            employees[i].display();
        }
        System.out.println("Yearly Expenditure: " + calExpenditure());
    }
}

class Main {
    public static void main(String args[]) {
        Dept itDept = new Dept("Information Technology", "Jadavpur University, Salt Lake", 10);

        itDept.add(new Employee("Mehendi", 101, "Belgharia", 25000.0f));
        itDept.add(new Employee("Debodit", 102, "Kudghat", 30000.0f));
        itDept.add(new Employee("Aritra", 103, "Newtown", 20000.0f));
        itDept.add(new Employee("Arnob", 104, "Sodepur", 40000.0f));
        itDept.add(new Employee("Touseef", 105, "Sukantanagar", 35000.0f));

        itDept.details();

        itDept.remove(102);

        System.out.println("\nAfter Removing an Employee:");
        itDept.details();
    }
}
