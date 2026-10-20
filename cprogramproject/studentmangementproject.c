#include<stdio.h>
#include<stdlib.h>
#define MAX_STUDENTS 100
struct Student {
    int roll;
    char name[100];
    int age;
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0;
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void saveTofile();
void loadTofile();
void sortStudents();
void topperStudent();
void averageMarks();
void totalStudents();
int main() {
    int choice;
    loadTofile();
    while(1)
    {
        printf("\n=====student management system=====\n");
        printf("1. Add Student\n");
        printf("2. display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Save to File\n");
        printf("7. Sort Students\n");
        printf("8. Find Topper\n");
        printf("9. Calculate Average Marks\n");
        printf("10. Total Students\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                saveTofile();
                printf("Student data saved to file successfully!\n");
                break;
            case 7:
                sortStudents();
                break;
            case 8:
                topperStudent();
                break;
            case 9:
                averageMarks();
                break;
            case 10:
                totalStudents();
                break;
            case 11:
                saveTofile();
                printf("Thank you for using the Student Management System.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
void addStudent() {
    printf("\nEnter student roll number; ");
    scanf("%d", &students[count].roll);
    printf("Enter student name: ");
    scanf("%s", students[count].name);
    printf("student age :");
    scanf("%d", &students[count].age);
printf("Enter student marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully!\n");
}
void displayStudents() {
    int i;
    if(count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\n----List of Students----\n");
    for(int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number:%d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }
}
void searchStudent() {
    int roll, found = 0;
    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);
    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            printf("Student found:\n");
            printf("Roll Number: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}
void updateStudent() {
    int roll, found = 0;
    printf("\nEnter roll number to update: ");
    scanf("%d", &roll);
    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new age: ");
            scanf("%d", &students[i].age);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}
void deleteStudent() {
    int roll, found = 0;
    printf("\nEnter roll number to delete: ");
    scanf("%d", &roll);
    for(int i = 0; i < count; i++) {
        if(students[i].roll == roll) {
            for(int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student with roll number %d not found.\n", roll);
    }
}
void saveTofile() {
    FILE *file = fopen("students.txt", "w");
    if(file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        fprintf(file, "%d %s %d %.2f\n", students[i].roll, students[i].name, students[i].age, students[i].marks);
    }
    fclose(file);
    printf("Student data saved to students.txt successfully!\n");
}
void loadTofile() {
    FILE *file = fopen("students.txt", "r");
    if(file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    count = 0;
    while(fscanf(file, "%d %s %d %f", &students[count].roll, students[count].name, &students[count].age, &students[count].marks) == 4) {
        count++;
        if(count >= MAX_STUDENTS) {
            printf("Maximum student limit reached. Some students may not be loaded.\n");
            break;
        }
    }
    fclose(file);
    printf("Student data loaded from students.txt successfully!\n");
}
void sortStudents() {
    if(count == 0) {
        printf("No students to sort.\n");
        return;
    }
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(students[j].roll > students[j + 1].roll) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by roll number successfully!\n");
}
void topperStudent() {
    if(count == 0) {
        printf("No students available to find the topper.\n");
        return;
    }
    int topperIndex = 0;
    for(int i = 1; i < count; i++) {
        if(students[i].marks > students[topperIndex].marks) {
            topperIndex = i;
        }
    }
    printf("Topper Student:\n");
    printf("Roll Number: %d\n", students[topperIndex].roll);
    printf("Name: %s\n", students[topperIndex].name);
    printf("Age: %d\n", students[topperIndex].age);
    printf("Marks: %.2f\n", students[topperIndex].marks);
}

void averageMarks() {
    if(count == 0) {
        printf("No students available to calculate average marks.\n");
        return;
    }
    float total = 0;
    for(int i = 0; i < count; i++) {
        total += students[i].marks;
    }
    float average = total / count;
    printf("Average Marks: %.2f\n", average);
}

void totalStudents() {
    printf("Total Students: %d\n", count);
}
