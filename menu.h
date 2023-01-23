#include "stdio.h"
#include "string.h"
// #include "authentication.h"
#include "student_management.h"
#include "instructure_management.h"
#include "course_management.h"

void handle_student()
{
}

void handle_instructor()
{
}

void handle_manager()
{

    puts("Which actions do you want to do?: ");
    printf(
        "0 - Add Student\n"
        "1 - Add Instructor\n"
        "2 - Add Course\n"
        "3 - Delete Student\n"
        "4 - Delete Course\n"
        "5 - Read Students Infos\n"
        "6 - Read Courses Infos\n"
        "7 - Read Instructors Infos\n");

    int action;
    scanf("%d", &action);
    handle_manager_action(action);
}

void handle_manager_action(int action)
{
    enum Actions
    {
        AddStudent,
        AddInstructor,
        AddCourse,
        DeleteStudent,
        DeleteCourse,
        ReadStudentsInfos,
        ReadCoursesInfos,
        ReadInstructorsInfos,
    };

    switch (action)
    {
    case AddStudent:
        // add student

        printf("Add The Student:\n");
        int i = 0;

        int want_to_repeat = 1;
        while (i < 1000 && want_to_repeat)
        {
            add_student(i);
            i++;
            puts("Do you want to do this one more time? (yes = 1 , no = 0)");
            scanf("%d", &want_to_repeat);
        }

        break;

    case AddInstructor:
        // add instructor

        printf("Add Instructor: \n");
        int j = 0;

        int want_to_continue = 1;
        while (j < 1000 && want_to_continue)
        {
            getchar();
            add_instructor(j);
            j++;
            puts("Do you want to do this one more time? (yes = 1 , no = 0)");
            scanf("%d", &want_to_continue);
        }

        break;
    case AddCourse:
        // add course
        getchar();
        addCourses();

        break;
    case DeleteStudent:
        // delete student
        puts("Enter student id which you want to delete: ");
        char student_id[10];
        scanf("%s", student_id);
        delete_student_data(student_id, STUDENTS_FILE_NAME);
        // delete_user_profile(role, "student");
        break;

    case DeleteCourse:
        // delete course
        deleteCourses();
        break;

    case ReadStudentsInfos:
        // read students infos
        puts("Students Infos: ");
        read_students_data(STUDENTS_FILE_NAME);
        break;

    case ReadCoursesInfos:
        // read courses infos
        readCourses();
        break;

    case ReadInstructorsInfos:
        // read instructors infos
        read_instructors_data(INSTRUCTORS_FILE_NAME);
        break;
    default:

        puts("Invalid Input!");
        break;
    }
}