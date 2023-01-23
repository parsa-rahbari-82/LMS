#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include <string.h>
#include "menu.h"

const *PROFILE_FILE_NAME = "C:\\Users\\parsa\\Desktop\\Data\\auth.txt";

enum Role
{
    STUDENT = 1,
    INSTRUCTOR,
    MANAGER
};

typedef struct

{

    int user_type;

    char user_id[10];

    char user_pass[50];

} User;

int UserVerified(int accountType, char accountId[], char accountPass[])

{

    FILE *fp;

    fp = fopen(PROFILE_FILE_NAME, "r");

    if (fp == NULL)

    {

        puts("unable to open the file...");

        return -1;
    }

    while (!feof(fp))

    {

        User loggingUser;

        char newLine[100];

        fgets(newLine, 100, fp);

        char *p1 = strtok(newLine, ", ");

        char *p2 = strtok(NULL, ", ");

        char *p3 = strtok(NULL, "\n ");

        if ((atoi(p1) == accountType) && (strcmp(p2, accountId) == 0) && (strcmp(p3, accountPass) == 0))

        {

            fclose(fp);

            return 0;
        }
    }

    fclose(fp);

    return 1;
}

void HandleUser()

{

    puts("What type is your account?");

    puts("'1' : Student");

    puts("'2' : Instructor");

    puts("'3' : Manager");

    User user;

    scanf("%d", &user.user_type);

    puts("Please Enter your ID");

    scanf("%s", user.user_id);

    puts("Please Enter your password");

    int i = 0;

    char c;

    while ((i < 49))

    {

        c = getch();

        if (c == '\r')

        {

            printf("\n");

            break;
        }

        if (c != ' ')

        {

            user.user_pass[i] = c;

            i++;

            printf("*");
        }
    }

    user.user_pass[i] = '\0';

    if (UserVerified(user.user_type, user.user_id, user.user_pass) == 0)

    {

        switch (user.user_type)

        {

        case STUDENT:

            handle_student();

            break;

        case INSTRUCTOR:

            handle_instructor();

            break;

        case MANAGER:

            handle_manager();

            break;
        }
    }

    else

    {

        puts("Sorry, Wrong information!");

        puts("Please try again...");

        HandleUser();
    }
}

int main()

{

    HandleUser();
}