class Student {
    private String name;
    private int rollNo;
    private String[] subjects;

    public Student(String name, int rollNo, String[] subjects) {
        this.name = name;
        this.rollNo = rollNo;
        this.subjects = subjects;
    }

    public String getName() {
        return name;
    }

    public int getRollNo() {
        return rollNo;
    }

    public String[] getSubjects() {
        return subjects;
    }
}

class TabulationSheet {
    private String subject;
    private int[] rollNos;
    private int[] marks;
    private int count;

    public TabulationSheet(String subject, int capacity) {
        this.subject = subject;
        rollNos = new int[capacity];
        marks = new int[capacity];
        count = 0;
    }

    public void addMarks(int rollNo, int mark) {
        if (count < rollNos.length) {
            rollNos[count] = rollNo;
            marks[count] = mark;
            count++;
        }
    }

    public int getMark(int rollNo) {
        for (int i = 0; i < count; i++) {
            if (rollNos[i] == rollNo) {
                return marks[i];
            }
        }
        return -1; 
    }

    public String getSubject() {
        return subject;
    }
}

class MarkSheet {
    private String studentName;
    private String[] subjects;
    private int[] marks;
    private int count;

    public MarkSheet(String studentName, int subjectCount) {
        this.studentName = studentName;
        subjects = new String[subjectCount];
        marks = new int[subjectCount];
        count = 0;
    }

    public void addMarks(String subject, int mark) {
        if (count < subjects.length) {
            subjects[count] = subject;
            marks[count] = mark;
            count++;
        }
    }

    public void printMarkSheet() {
        System.out.println("Marksheet for: " + studentName);
        for (int i = 0; i < count; i++) {
            System.out.println(subjects[i] + ": " + marks[i]);
        }
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        String[] subjects = {"Math", "Physics", "Chemistry", "Biology", "English"};

        Student[] students = {
            new Student("Mehendi", 101, subjects),
            new Student("Rishika", 102, subjects),
            new Student("Prama", 103, subjects)
        };

        TabulationSheet[] tabSheets = new TabulationSheet[subjects.length];
        for (int i = 0; i < subjects.length; i++) {
            tabSheets[i] = new TabulationSheet(subjects[i], students.length);
        }

        int[][] marksData = {
            {82, 90, 95},
            {70, 88, 90},
            {78, 84, 92},
            {92, 95, 98},
            {88, 99, 89}
        };

        for (int i = 0; i < subjects.length; i++) {
            for (int j = 0; j < students.length; j++) {
                tabSheets[i].addMarks(students[j].getRollNo(), marksData[i][j]);
            }
        }

        MarkSheet[] markSheets = new MarkSheet[students.length];
        for (int i = 0; i < students.length; i++) {
            markSheets[i] = new MarkSheet(students[i].getName(), subjects.length);
            for (TabulationSheet tabSheet : tabSheets) {
                markSheets[i].addMarks(tabSheet.getSubject(), tabSheet.getMark(students[i].getRollNo()));
            }
        }

        for (MarkSheet markSheet : markSheets) {
            markSheet.printMarkSheet();
        }
    }
}