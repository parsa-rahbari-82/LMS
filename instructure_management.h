#include "stdio.h"
#include "string.h"

const char *INSTRUCTORS_FILE_NAME = "C:\\Users\\parsa\\Desktop\\Data\\instructors.txt";
typedef struct
{
    char first_name[100];
    char last_name[100];
    char title[100];
    char field[100];
} Instrucor;

void add_instructor(int i)
{

    char first_name[100], last_name[100], title[100], field[100];

    printf("Enter first name: ");
    fgets(first_name, 100, stdin);
    printf("Enter last name: ");
    fgets(last_name, 100, stdin);
    printf("Enter title: ");
    fgets(title, 100, stdin);
    printf("Enter field: ");
    fgets(field, 100, stdin);

    title[strlen(title) - 1] = '\0';
    first_name[strlen(first_name) - 1] = '\0';
    last_name[strlen(last_name) - 1] = '\0';
    field[strlen(field) - 1] = '\0';

    Instrucor instructor = {first_name, last_name, title, field};
    Instrucor instructors[1000];
    instructors[i] = instructor;
    FILE *fp;
    fp = fopen(INSTRUCTORS_FILE_NAME, "a");
    fprintf(fp, "%s , %s , %s , %s\n", first_name, last_name, title, field);
    printf("%s , %s , %s , %s\n", first_name, last_name, title, field);
    fclose(fp);
}

void read_instructors_data(char *INSTRUCTORS_FILE_NAME)
{
    FILE *fp;
    fp = fopen(INSTRUCTORS_FILE_NAME, "r");

    char res[400];

    fgets(res, 400, fp);

    while (!feof(fp))
    {
        printf(res);
        fgets(res, 400, fp);
    }

    fclose(fp);
}
