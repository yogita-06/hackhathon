#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
typedef struct Student {
    int id;
    char name[50];
    int maths, science, english;
    char department[50];
    struct Student *next; // Pointer for linked list
} Student;

Student *head = NULL; // Head pointer for linked list

// Function to add a new student record
void addStudent() {
    Student *newStudent = (Student *)malloc(sizeof(Student)); // Memory allocation

    printf("Enter Student ID: ");
    scanf("%d", &newStudent->id);
    printf("Enter Name: ");
    scanf(" %[^\n]", newStudent->name); // Read full name including spaces
    printf("Enter Maths Marks: ");
    scanf("%d", &newStudent->maths);
    printf("Enter Science Marks: ");
    scanf("%d", &newStudent->science);
    printf("Enter English Marks: ");
    scanf("%d", &newStudent->english);
    printf("Enter Department: ");
    scanf(" %[^\n]", newStudent->department);

    newStudent->next = head; // Insert at the beginning
    head = newStudent;

    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }
    Student *temp = head;
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("\nID: %d\nName: %s\nMaths: %d\nScience: %d\nEnglish: %d\nDepartment: %s\n",
               temp->id, temp->name, temp->maths, temp->science, temp->english, temp->department);
        temp = temp->next;
    }
}

// Function to search a student by ID
void searchStudent() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    Student *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nStudent Found:\nID: %d\nName: %s\nMaths: %d\nScience: %d\nEnglish: %d\nDepartment: %s\n",
                   temp->id, temp->name, temp->maths, temp->science, temp->english, temp->department);
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to delete a student record by ID
void deleteStudent() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    
    Student *temp = head, *prev = NULL;
    
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) { // Deleting the first node
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    
    free(temp); // Free memory
    printf("Student record deleted successfully.\n");
}

// Function to update a student's details
void updateStudent() {
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    Student *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Enter new Maths Marks: ");
            scanf("%d", &temp->maths);
            printf("Enter new Science Marks: ");
            scanf("%d", &temp->science);
            printf("Enter new English Marks: ");
            scanf("%d", &temp->english);
            printf("Enter new Department: ");
            scanf(" %[^\n]", temp->department);
            printf("Student details updated successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to find the student with the highest marks
void highestMarks() {
    if (head == NULL) {
        printf("No records available.\n");
        return;
    }

    Student *temp = head, *topper = head;
    int highest = head->maths + head->science + head->english;

    while (temp != NULL) {
        int totalMarks = temp->maths + temp->science + temp->english;
        if (totalMarks > highest) {
            highest = totalMarks;
            topper = temp;
        }
        temp = temp->next;
    }

    printf("\nStudent with Highest Marks:\nID: %d\nName: %s\nTotal Marks: %d\n",
           topper->id, topper->name, highest);
}

// Function to count the total number of students
void countStudents() {
    int count = 0;
    Student *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of students: %d\n", count);
}

// Function to reverse the student list
void reverseList() {
    Student *prev = NULL, *current = head, *next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    printf("Student list reversed successfully!\n");
}

// Function to calculate the average marks of all students
void averageMarks() {
    if (head == NULL) {
        printf("No records found.\n");
        return;
    }

    Student *temp = head;
    int totalMarks = 0, count = 0;

    while (temp != NULL) {
        totalMarks += temp->maths + temp->science + temp->english;
        count++;
        temp = temp->next;
    }

    printf("Average Marks of all students: %.2f\n", (float)totalMarks / (3 * count));
}

// Function to display menu options
void menu() {
    int choice;
    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n");
        printf("5. Update Student\n6. Find Highest Marks\n7. Count Students\n");
        printf("8. Reverse List\n9. Average Marks\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: highestMarks(); break;
            case 7: countStudents(); break;
            case 8: reverseList(); break;
            case 9: averageMarks(); break;
            case 10: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

// Main function to start the program
int main() {
    menu();
    return 0;
}
