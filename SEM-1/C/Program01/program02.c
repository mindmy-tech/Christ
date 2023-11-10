
/* 
Domain: Decimal 2 Binary Convertion 
*/

#include <stdio.h>

// Prototype
void dec2bin(int number);

int main(void)
{
    // [2] decimal to binary convertion 

    // Gets Number From User
    int target_num;
    printf("Number: ");
    scanf("%i", &target_num);

    // Calls dec2bin function
    dec2bin(target_num);

}

void dec2bin(int number)
{
    /* 
    I'm using char coz char uses 1 Byte
    while int uses 4 Bytes in c
    if we want we can also use bool it will be just 1 Bit  but we will have to include <bool.h> and there will be some more computation
    coz there will be if and else , so decided to use char
    int will also work fine
    */
    char values[100];
    int i = 0;

    // while the number is greater that 0 the loop keeps running
    while (number > 0)
    {
        // gets the reminder of the number / 2 and stores it in char array it will be 0 or 1 only.
        values[i] = number % 2;
        number /= 2;
        i++;
    }

    //  Goes from last element in array to first 
    for (int j = i -1 ; j >= 0; j--)
    {
        // we are using %i even if its a char coz while storing 0 or 1 it will be stored in ascii value
        // so we are converting it back to int using %i
        printf("%i", values[j]);
    }
    printf("\n");
}
