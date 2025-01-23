class Person {
    int age;
    double weight;
    double height;
    String dateOfBirth;
    String address;

    Person(int age, double weight, double height, String dateOfBirth, String address) {
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }

    public void printDetails() {
        System.out.println("  - Age: " + age);
        System.out.println("  - Weight: " + weight + " kg");
        System.out.println("  - Height: " + height + " m");
        System.out.println("  - Date of Birth: " + dateOfBirth);
        System.out.println("  - Address: " + address);
    }
}

class Employee extends Person {
    double salary;
    String dateOfJoining;
    int experience;

    public Employee(int age, double weight, double height, String dateOfBirth, String address,
                    double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("  - Salary: " + salary);
        System.out.println("  - Date of Joining: " + dateOfJoining);
        System.out.println("  - Experience: " + experience + " years");
    }
}

class Student extends Person {
    String roll;
    String[] listOfSubjects;
    int[] marks;

    public Student(int age, double weight, double height, String dateOfBirth, String address,
                   String roll, String[] listOfSubjects, int[] marks) {
        super(age, weight, height, dateOfBirth, address);
        this.roll = roll;
        this.listOfSubjects = listOfSubjects;
        this.marks = marks;
    }

    public String calculateGrade() {
        double average = 0;
        for (int mark : marks) {
            average += mark;
        }
        average /= marks.length;
        if (average >= 90) return "A";
        else if (average >= 75) return "B";
        else if (average >= 50) return "C";
        else return "F";
    }

    public void printDetails() {
        System.out.println("Student Details ");
        super.printDetails();
        System.out.println("  - Roll Number: " + roll);
        System.out.println("  - Grade: " + calculateGrade());
        System.out.println();
    }
}

class Technician extends Employee {
    public Technician(int age, double weight, double height, String dateOfBirth, String address,
                      double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
    }

    public void printDetails() {
        System.out.println("Technician Details: ");
        super.printDetails();
        System.out.println("  - Technician ready for technical tasks.");
        System.out.println();
    }
}

class Professor extends Employee {
    private final String[] courses;
    private String[] advisees = new String[0];

    public Professor(int age, double weight, double height, String dateOfBirth, String address,
                     double salary, String dateOfJoining, int experience, String[] courses) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
        this.courses = courses;
    }

    public void addAdvisee(String adviseeName) {
        String[] newAdvisees = new String[advisees.length + 1];
        System.arraycopy(advisees, 0, newAdvisees, 0, advisees.length);
        newAdvisees[advisees.length] = adviseeName;
        advisees = newAdvisees;
    }

    public void removeAdvisee(String adviseeName) {
        int index = -1;
        for (int i = 0; i < advisees.length; i++) {
            if (advisees[i].equals(adviseeName)) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            String[] newAdvisees = new String[advisees.length - 1];
            for (int i = 0, j = 0; i < advisees.length; i++) {
                if (i != index) {
                    newAdvisees[j++] = advisees[i];
                }
            }
            advisees = newAdvisees;
        }
    }

    public void printDetails() {
        System.out.println("Professor Details: ");
        super.printDetails();
        System.out.print("  - Courses: ");
        for (String course : courses) {
            System.out.print(course + " ");
        }
        System.out.println();
        System.out.print("  - Advisees: ");
        for (String advisee : advisees) {
            System.out.print(advisee + " ");
        }
        System.out.println("\n");
    }
}

class Main {
    public static void main(String[] args) {

        String[] subjects = {"Math", "Physics", "Chemistry"};
        int[] marks = {85, 90, 78};
        Student student = new Student(20, 62, 1.65, "17/05/2004", "Maidan", "1094", subjects, marks);
        student.printDetails();

        Technician technician = new Technician(30, 70, 1.80, "15/05/2001", "Central", 35000, "01/06/2017", 8);
        technician.printDetails();

        String[] courses = {"Web Development", "AI/ML"};
        Professor professor = new Professor(45, 80, 1.85, "10/02/1996", "Esplanade", 55000, "01/01/2015", 10, courses);
        professor.addAdvisee("Mehendi");
        professor.addAdvisee("Anwesha");
        professor.printDetails();

        professor.removeAdvisee("Mehendi");
        System.out.println("After Advisee Removal: ");
        professor.printDetails();
    }
}
