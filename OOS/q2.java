class student {
    String name;
    int marks1, marks2, marks3;

    student(String name, int marks1, int marks2, int marks3) {
        this.name = name;
        this.marks1= marks1;
        this.marks2= marks2;
        this.marks3= marks3;
    }

    int total() {
        return marks1 + marks2 + marks3;
    }

    double avg() {
        return (double)total() / 3;
    }

    void display() {
        System.out.println("Name: " +name);
        System.out.println("Total marks: " +total());
        System.out.println("Average marks: " +avg());
    }
}

class main {
    public static void main(String[] args) {
        student s1 = new student("Mehendi", 90, 85, 95);

        s1.display();
    }
}