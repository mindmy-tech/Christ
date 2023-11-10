#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char courses[][5] = {"BSC", "BCA", "BE"};
    char course_details[][500] = {
        "BSc okay! okay!\n you'll have :\n\tC Programing\n\tMath\n\tAnalog Digital Electronics\n",
        "BCA Nice Choice\n Don't You worry\n you just have \"Computer Science\"!\n",
        "BE uhhhh okayyyy\n Math\nPhysics\nChemistry\nand a little bit of computer science!\n" 
    };
    // reading the total number of bytes alocated and dividing it by 5
    // coz each course gets 5 bytes
    int no_courses = sizeof(courses) / 5;

    char first_name[12];
    char last_name[12];
    do
    {
        printf("First Name :");
        scanf("%s", &first_name);

        printf("Last Name :");
        scanf("%s", &last_name);
    }

    while (strlen(first_name) > 12 || strlen(last_name) > 12);

    char get_course[10];
    printf("Course :");
    scanf("%s", &get_course);
    for (int i = 0; i < strlen(get_course); i++)
    {
        get_course[i] = toupper(get_course[i]);
    }

    for (int i = 0; i < no_courses; i++)
    {
        if (!strcmp(get_course, courses[i]))
        {
            printf("%s", course_details[i]);
        }
    }
}