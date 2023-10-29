#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for student information
typedef struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student* next;
} Student;

// Function to add a new student to the linked list
void addStudent(Student** head, int studentNumber, const char* name, int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->studentNumber = studentNumber;
    strncpy(newStudent->name, name, sizeof(newStudent->name));
    newStudent->age = age;
    newStudent->next = *head;
    *head = newStudent;
}

// Function to print student information and count students
void printStudentsAndCount(Student* head) {
    int studentCount = 0;
    Student* current = head;

    while (current != NULL) {
        studentCount++;
        printf("%d - %s %d %d\n", studentCount, current->name, current->age, current->studentNumber);
        current = current->next;
    }

    printf("Total students: %d\n", studentCount);
}

// Function to find and print the record with the longest name
void printStudentWithLongestName(Student* head) {
    Student* current = head;
    char longestName[50];
    int longestNameLength = 0;

    while (current != NULL) {
        int nameLength = strlen(current->name);
        if (nameLength > longestNameLength) {
            longestNameLength = nameLength;
            strncpy(longestName, current->name, sizeof(longestName));
        }
        current = current->next;
    }

    if (longestNameLength > 0) {
        printf("The longest name in the list: %s\n", longestName);
        printf("Length: %d\n", longestNameLength);
    } else {
        printf("No names found in the list.\n");
    }
}

int main() {
    // Define the head of the linked list
    Student* head = NULL;

    // Add students to the linked list
    addStudent(&head, 201, "Saliha", 27);
    addStudent(&head, 203, "Ece", 19);
    addStudent(&head, 205, "John", 22);
    addStudent(&head, 207, "Abdurrahmangazi", 30);

    // Print student information and count students
    printStudentsAndCount(head);

    // Find and print the record with the longest name
    printStudentWithLongestName(head);

    // Free the allocated memory for the linked list
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
