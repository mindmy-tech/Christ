#include <stdio.h>
#include <conio.h>
#include <string.h>

int main(void)
{
    char courses[][5] = {"BSc", "BCA","BE"};
    // reading the total number of bytes alocated and dividing it by 5 
    // coz each course gets 5 bytes
    int no_courses =  sizeof(courses)/5;

    char first_name[12];
    printf("Name :");
    // gets(first_name);
    scanf("%s", &first_name);

    printf("%s %i\n", first_name, strlen(first_name));



}