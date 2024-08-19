#include <stdio.h>
#include <string.h>

// #define n 10
// #define 5 5

typedef struct {
    char name[50];
    char address[100];
    int marks[5];
} Student;

void inputStudents(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d\n", i + 1);
        printf("Name: ");
        getchar(); 
        fgets(students[i].name, 50, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; 
        printf("Address: ");
        fgets(students[i].address, 100, stdin);
        students[i].address[strcspn(students[i].address, "\n")] = '\0'; 
        printf("Enter marks for 5 subjects (Math, Phy, Chem, Comp, Eng): ");
        for (int j = 0; j < 5; j++) {
            scanf("%d", &students[i].marks[j]);
        }
    }
}

void failStudent(Student *students, int n) {
    printf("Students who failed in at least three subjects:\n");
    for (int i = 0; i < n; i++) {
        int failCount = 0;
        for (int j = 0; j < 5; j++) {
            if (students[i].marks[j] < 40) {
                failCount++;
            }
        }
        if (failCount >= 3) {
            printf("%s\n", students[i].name);
        }
    }
}

void maxMath(Student *students, int n) {
    int maxMarks = -1;
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (students[i].marks[0] > maxMarks) {  
            maxMarks = students[i].marks[0];
            maxIndex = i;
        }
    }
    if (maxIndex != -1) {
        printf("Student with maximum marks in Mathematics:\n");
        printf("Name: %s\n", students[maxIndex].name);
        printf("Address: %s\n", students[maxIndex].address);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", students[maxIndex].marks[j]);
        }
        printf("\n");
    }
}

void minPhy(Student *students, int n) {
    int minMarks = 101;
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (students[i].marks[1] < minMarks) {  
            minMarks = students[i].marks[1];
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        printf("Student with minimum marks in Physics:\n");
        printf("Name: %s\n", students[minIndex].name);
        printf("Address: %s\n", students[minIndex].address);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", students[minIndex].marks[j]);
        }
        printf("\n");
    }
}

void maxAvg(Student *students, int n) {
    double maxAverage = -1;
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        double total = 0;
        for (int j = 0; j < 5; j++) {
            total += students[i].marks[j];
        }
        double average = total / 5;
        if (average > maxAverage) {
            maxAverage = average;
            maxIndex = i;
        }
    }
    if (maxIndex != -1) {
        printf("Student with maximum average marks:\n");
        printf("Name: %s\n", students[maxIndex].name);
        printf("Address: %s\n", students[maxIndex].address);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", students[maxIndex].marks[j]);
        }
        printf("\n");
    }
}

void recordStudent(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        int total = 0;
        printf("Name: %s, Total Marks: ", students[i].name);
        for (int j = 0; j < 5; j++) {
            total += students[i].marks[j];
        }
        printf("%d\n", total);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student students[n];

    inputStudents(students, n);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Find students who failed in at least three subjects\n");
        printf("2. Show the record of the student with maximum marks in Mathematics\n");
        printf("3. Show the record of the student with minimum marks in Physics\n");
        printf("4. Show the record of the student with maximum average marks\n");
        printf("5. Print the record of the student with name and total marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                failStudent(students, n);
                break;
            case 2:
                maxMath(students, n);
                break;
            case 3:
                minPhy(students, n);
                break;
            case 4:
                maxAvg(students, n);
                break;
            case 5:
                recordStudent(students, n);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
