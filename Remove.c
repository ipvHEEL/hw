/*Иван,Иванов,4.5,2
Петр,Петров,3.2,5
Мария,Сидорова,4.8,1
Анна,Козлова,3.9,3
Дмитрий,Смирнов,2.1,8*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_STUDENTS 100

// Структура для хранения информации о студенте
struct Student {
    char name[MAX_LINE_LENGTH];
    char surname[MAX_LINE_LENGTH];
    float average_grade;
    int missed_classes;
};

int main() {
    FILE *input_file;
    FILE *output_file;
    char line[MAX_LINE_LENGTH];
    struct Student students[MAX_STUDENTS];
    int num_students = 0;
    input_file = fopen("in.txt", "r");


    // Читаем данные из файла и сохраняем их в структуру Студент
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        sscanf(line, "%s %s %f %d", students[num_students].name, students[num_students].surname,
               &students[num_students].average_grade, &students[num_students].missed_classes);
        num_students++;
    }


    fclose(input_file);

    // Открываем файл для записи списка студентов, подлежащих отчислению
    output_file = fopen("out.txt", "w");
    // Пороговые значения для отчисления (можно изменить по необходимости)
    float grade_threshold = 3.0;
    int missed_classes_threshold = 5;

    // Проверяем критерии отчисления и записываем студентов, подлежащих отчислению, в файл
    for (int i = 0; i < num_students; i++) {
        if (students[i].average_grade < grade_threshold || students[i].missed_classes > missed_classes_threshold) {
            fprintf(output_file, "%s %s\n", students[i].name, students[i].surname);
        }
    }
    fclose(output_file);

    printf("Список студентов, подлежащих отчислению, успешно записан в out.txt\n");

    return 0;
}
