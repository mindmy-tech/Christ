#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[]= "Hello";
    char last_name [] = ", World";
    printf("the size of first_name is :%i\n", sizeof(first_name));
    strcat(first_name, last_name);

    printf("Full name : %s\n", first_name);
    printf("now size of first_name is :%i\n", sizeof(first_name));
}