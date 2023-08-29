#include <stdio.h>
#include <stdlib.h>

// Data type
typedef struct Student
{
    long unsigned register_number;
    int marks[6];
} Student;

// Prototype
int get_positive_int(char query[], int num);
void print_details(Student *students);

// Initialize an array of students with a certain initial capacity
Student *students;
int students_capacity = 3;
int students_count = 0;

// Subjects
char subjects[6][50] = {"C Programming", "Math", "WAD", "DAS", "English", "MDC"};

int main(void)
{
    students = (Student *)malloc(students_capacity * sizeof(Student));

    if (students == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    do
    {
        int reg_num = get_positive_int("Register Number: ", 0);
        // Condition to exit
        if (reg_num == 0)
        {
            printf("EXIT\n");
            break;
        }

        Student std;
        std.register_number = reg_num;

        for (int i = 0; i < 6; i++)
        {
            printf("Score in %s: ", subjects[i]);
            int mark = get_positive_int("", 1);
            std.marks[i] = mark;
        }

        students[students_count] = std;
        students_count++;

        if (students_count >= students_capacity)
        {
            // Increment the capacity by 1
            students_capacity += 1;
            students = (Student *)realloc(students, students_capacity * sizeof(Student));

            if (students == NULL)
            {
                fprintf(stderr, "Memory reallocation failed\n");
                return 1;
            }
        }

        printf("\n");

    } 
    while (1);

    print_details(students);

    // Free allocated memory
    free(students);

    return 0;
}

void print_details(Student *students)
{
    printf("+-------------------+\n");
    printf("|REG \t| SUM\t|AVG|\n");
    for (int i = 0; i < students_count; i++)
    {
        printf("---------------------\n");
        int sum = 0, avg;
        int reg = students[i].register_number;
        for (   int j = 0; j < 6; j++)
        {
            sum += students[i].marks[j];
        }
        avg = sum / 6;
        
        printf("|%li \t|%i \t|%i | \n", reg, sum, avg);
    }
    printf("+-------------------+\n");
}

int get_positive_int(char query[], int num)
{
    int number;
    if (num == 0)
    {
        do
        {
            printf("%s", query);
            scanf("%i", &number);
        }
        while (number < 0);
    }
    else
    {
        do
        {
            printf("%s", query);
            scanf("%i", &number);
        } 
        while (number < 0 || number > 100);
    }
    return number;
}
