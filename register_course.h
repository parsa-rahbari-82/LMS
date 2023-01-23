#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_course_to_syllabus(char *userFile)

{

    puts("These are the available courses:");
    puts("Enter the code of the course you want to take...");

    char course_to_take[10];

    scanf("%s", course_to_take);

    FILE *fp;

    fp = fopen(userFile, "r");

    // checking if the file of the student's courses exists

    //**************************************************

    if (fp == NULL)

    {

        puts("Oops... something went wrong!");

        return;
    }

    //**************************************************

    // checking if the course already exists in the syllabus

    // and also counting the overall credit of the courses that have been taken by the student

    //**************************************************

    int current_cred = 0;

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

            if (strcmp(p1, course_to_take) == 0)

            {

                puts("This course is already in your syllabus");

                return;
            }

            int cred = atoi(p3);

            current_cred += cred;
        }
    }

    fclose(fp);

    //**************************************************

    FILE *student_fp, *courses_fp;

    student_fp = fopen(userFile, "a+");

    courses_fp = fopen(COURSE_FILE_NAME, "r");

    while (!(feof(courses_fp)))

    {

        char newLine[105];

        if (fgets(newLine, 100, courses_fp))

        {

            Course newCourse;

            char *d = ",";

            char *p1 = strtok(newLine, d);

            char *p2 = strtok(NULL, d);

            char *p3 = strtok(NULL, d);

            int cred = atoi(p3);

            if (strcmp(p1, course_to_take) == 0)

            {

                // maximum amount of credit that can be taken varies...

                // Here we use "20" as a possible example

                if ((cred + current_cred) > 20)

                {

                    puts("You are not allowed to take this course because your credit will exceed the maximum amount");

                    return;
                }

                fprintf(student_fp, "%s,%s,%s", p1, p2, p3);
            }
        }
    }

    fclose(fp);
}