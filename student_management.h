#include "stdio.h"
#include "string.h"

const char *STUDENTS_FILE_NAME = "C:\\Users\\parsa\\Desktop\\Data\\students.txt";
typedef struct
{
    char first_name[100];
    char last_name[100];
    char student_id[10];
    char field[100];
} Student;

void add_student(int i)
{
    char first_name[100], last_name[100], student_id[10], field[100];

    printf("Enter your first name: ");
    scanf("%s", first_name);
    printf("Enter your last name: ");
    scanf("%s", last_name);
    printf("Enter your student id: ");
    scanf("%s", student_id);
    printf("Enter your field: ");
    scanf("%s", field);

    Student student = {first_name, last_name, student_id, field};
    Student students[1000];
    students[i] = student;
    FILE *fp;
    fp = fopen(STUDENTS_FILE_NAME, "a");
    fprintf(fp, "%s , %s , %s , %s\n", first_name, last_name, student_id, field);
    fclose(fp);
    create_student_course_file(student_id);
}

void read_students_data(char *STUDENTS_FILE_NAME)
{
    FILE *fp;
    fp = fopen(STUDENTS_FILE_NAME, "r");

    char first_name[100], last_name[100], student_id[10], field[100];

    fscanf(fp, "%s , %s , %s , %s", first_name, last_name, student_id, field);

    while (!feof(fp))
    {
        printf("%s %s %s %s\n", first_name, last_name, student_id, field);
        fscanf(fp, "%s , %s , %s , %s", first_name, last_name, student_id, field);
    }

    fclose(fp);
}

void delete_student_data(char STUDENT_ID[10], char *STUDENTS_FILE_NAME)
{

    FILE *fp, *cfp;
    char first_name[100], last_name[100], student_id[10], field[100];

    fp = fopen(STUDENTS_FILE_NAME, "r+");
    cfp = fopen("C:\\Users\\parsa\\Desktop\\Data\\copy.txt", "w");
    fscanf(fp, "%s , %s , %s , %s", first_name, last_name, student_id, field);

    while (!feof(fp))
    {

        if (strcmp(STUDENT_ID, student_id) != 0)
        {
            fprintf(cfp, "%s , %s , %s , %s\n", first_name, last_name, student_id, field);
        }

        fscanf(fp, "%s , %s , %s , %s", first_name, last_name, student_id, field);
    }
    fclose(fp);
    fclose(cfp);
    remove(STUDENTS_FILE_NAME);
    rename("C:\\Users\\parsa\\Desktop\\Data\\copy.txt", STUDENTS_FILE_NAME);
    char file_name[150];
    snprintf(file_name, sizeof(file_name), "C:\\Users\\parsa\\Desktop\\Data\\%s.txt", STUDENT_ID);
    remove(file_name);
}

void create_student_course_file(char student_id[10])
{

    char file_name[150];
    snprintf(file_name, sizeof(file_name), "C:\\Users\\parsa\\Desktop\\Data\\%s.txt", student_id);
    fclose(fopen(file_name, "a"));
}