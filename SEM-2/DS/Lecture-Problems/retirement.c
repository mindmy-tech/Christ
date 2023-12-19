#include <stdio.h>


int main(void)
{
    int age = 24;
    long int bank_balance = 0;
    int monthly = 10000;
    int upto = 36;
    for (age = 0; age < upto; age++)
    {
        for(int m = 1; m <= 12; m++)
        {
            bank_balance += monthly;
            int intrest = bank_balance * 0.01;
            bank_balance += intrest;
        }
    }
    printf("YOu will retire with %li", bank_balance);
}