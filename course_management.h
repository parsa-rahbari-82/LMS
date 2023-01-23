#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *COURSE_FILE_NAME = "C:\\Users\\parsa\\Desktop\\Data\\courses.txt";

typedef struct

{

    char course_code[10];

    char course_name[50];

    unsigned int course_credit;

} Course;

void addCourses();

void readCourses();

void deleteCourses();

void addCourses()

{

    Course courses_to_add[100];

    char continueAdding = 'y';

    int i = 0;

    do

    {

        Course newCourse;

        puts("What is the course's code?");

        fgets(newCourse.course_code, 10, stdin);

        sscanf(newCourse.course_code, "%s\n", newCourse.course_code);

        puts("What is the course's name?");

        fgets(newCourse.course_name, 50, stdin);

        int L = strlen(newCourse.course_name);

        newCourse.course_name[L - 1] = '\0';

        puts("What is the course's credit?");

        scanf("%u", &newCourse.course_credit);

        courses_to_add[i] = newCourse;

        i++;

        // printf("%s\n%s\n%d\n", newCourse.course_code, newCourse.course_name, newCourse.course_credit);

        printf("Do you want to continue adding? ('y' to continue)\n");

        scanf("\n%c", &continueAdding);

        fflush(stdin);

    }

    while ((continueAdding == 'y') && (i < 100));

    //*****************************************************

    FILE *fp;

    fp = fopen(COURSE_FILE_NAME, "a+");

    for (int j = 0; j < i; j++)

    {

        fprintf(fp, "%s, %s, %u\n", courses_to_add[j].course_code, courses_to_add[j].course_name, courses_to_add[j].course_credit);
    }

    fclose(fp);

    //*****************************************************
}

void readCourses()

{

    FILE *fp;

    fp = fopen(COURSE_FILE_NAME, "r");

    int i = 0;

    while (!(feof(fp)))

    {

        char newLine[105];

        if (fgets(newLine, 100, fp))

        {

            Course newCourse;

            char *d = ",";

            char *p1 = strtok(newLine, d);

            char *p2 = strtok(NULL, d);

            char *p3 = strtok(NULL, d);

            strcpy(newCourse.course_code, p1);

            strcpy(newCourse.course_name, p2);

            printf("%s,%s,%s", newCourse.course_code, newCourse.course_name, p3);
        }
    }

    fclose(fp);
}

void deleteCourses()

{

    printf("What course do you want to delete?\n");

    printf("Enter the course code of the course you want to delete.\n");

    char course_to_delete[10];

    scanf("%s", course_to_delete);

    FILE *cfp, *fp;

    cfp = fopen("C:\\Users\\parsa\\Desktop\\Data\\copy.txt", "w");

    fp = fopen(COURSE_FILE_NAME, "r");

    while (!(feof(fp)))

    {

        char newLine[105];

        if (fgets(newLine, 100, fp))

        {

            Course newCourse;

            char *d = ",";

            char *p1 = strtok(newLine, d);

            char *p2 = strtok(NULL, d);

            char *p3 = strtok(NULL, d);

            strcpy(newCourse.course_code, p1);

            strcpy(newCourse.course_name, p2);

            if (strcmp(newCourse.course_code, course_to_delete))

            {

                fprintf(cfp, "%s,%s,%s", newCourse.course_code, newCourse.course_name, p3);
            }
        }
    }

    fclose(fp);
    fclose(cfp);

    remove(COURSE_FILE_NAME);

    rename("C:\\Users\\parsa\\Desktop\\Data\\copy.txt", COURSE_FILE_NAME);
}