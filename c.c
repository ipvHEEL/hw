#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 1000
#define MAX_SUBJECTS 1000

typedef struct {
    int id;
    char group[10];
    char name[50];
} Student;

typedef struct {
    int id;
    char subject[50];
    int marks[5];
    int count;
} Session;

int main() {
    // Чтение информации о студентах
    FILE *students_file = fopen("Students.txt", "r");

    Student students[MAX_STUDENTS];
    int student_count = 0;
    while (fscanf(students_file, "%d;%9[^;];%49[^\n]", &students[student_count].id, students[student_count].group, students[student_count].name) == 3) {
        student_count++;
    }
    fclose(students_file);

    // Чтение информации об оценках студентов
    FILE *session_file = fopen("Session.txt", "r");

    Session sessions[MAX_SUBJECTS];
    int session_count = 0;
    while (fscanf(session_file, "%d;%49[^;];%d %d %d %d %d", &sessions[session_count].id, sessions[session_count].subject,
                                                &sessions[session_count].marks[0], &sessions[session_count].marks[1],
                                                &sessions[session_count].marks[2], &sessions[session_count].marks[3],
                                                &sessions[session_count].marks[4]) == 7) {
        sessions[session_count].count = 5;
        session_count++;
    }
    fclose(session_file);

    // Вывод полученных данных для проверки
    printf("Студенты:\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d %s %s\n", students[i].id, students[i].group, students[i].name);
    }

    printf("\nОценки:\n");
    for (int i = 0; i < session_count; i++) {
        printf("%d %s ", sessions[i].id, sessions[i].subject);
        for (int j = 0; j < sessions[i].count; j++) {
            printf("%d ", sessions[i].marks[j]);
        }
        printf("\n");
    }

    return 0;
}
