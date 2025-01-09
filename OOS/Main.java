class Student {
    private String name;
    private double marks1, marks2, marks3;

    public Student(String name, double marks1, double marks2, double marks3) {
        this.name = name;
        this.marks1 = marks1;
        this.marks2 = marks2;
        this.marks3 = marks3;
    }

    public double totalMarks() {
        return marks1 + marks2 + marks3;
    }

    public double averageMarks() {
        return totalMarks() / 3;
    }

    public void displayStudentDetails() {
        System.out.println("Student Name: " + name);
        System.out.println("Total Marks: " + totalMarks());
        System.out.println("Average Marks: " + averageMarks());
    }
}

public class Main {
    public static void main(String[] args) {
        Student student1 = new Student("Mehendi Sil", 85.5, 92.0, 78.5);

        student1.displayStudentDetails();

        Student student2 = new Student("Anwesha Saha", 88.0, 79.5, 91.0);

        student2.displayStudentDetails();
    }
}
