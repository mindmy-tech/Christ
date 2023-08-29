#include <stdio.h>

int main(void)
{
    // [1]

    // identifiers are the name of the variables
    // variables are like a container where you can store data 
    int number = 45;

    // as we can see this is a single comment and this does not affect the program

    /* For a multi-line comment 
    this can be use for documentaion inside the program*/

    // Constants 
    // constants can be used in situations like where the variable is used for read-only 
    // like PI Value
    const float PI = 3.14;

    // Literals are the type of data the variable is going to store 
    // like 
    int num = 66;
    long long int phone_num = 8778008956;
    float pi = 3.14;
    char letter = 'y';
    char words[] = "Hello"; 

    // Printing the values
    printf("Integer value: %d\n", num);
    printf("Float value: %f\n", pi);
    printf("Const Float value: %f\n", PI);
    printf("long long int value: %lli\n", phone_num);
    printf("Character value: %c\n", letter);
    printf("String value: %s\n", words);
}



