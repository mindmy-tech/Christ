#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    // stores reg number
    long unsigned reg;
    do {
        printf("Enter the REG No :");
        scanf("%li", &reg);

        if (reg == 0)
        {
            break;
        }
        char percentage_str[10];
        printf("Enter the Attendance Percentage of %li :", reg);
        scanf("%s", &percentage_str);

        int str_len= strlen(percentage_str) - 2;
        int i = 0;
        int percentage  = 0;
        int percentage_bool = 0;
        while (percentage_str[i] != '\0')
        {
            if (percentage_str[i] >= '0' && percentage_str[i] <= '9')
            {
                int num = (percentage_str[i] - '0')* pow(10, str_len - i );
                percentage += num;
            }

            else if (percentage_str[i] == '%')
            {
                percentage_bool = 1;
                break;
            }

            else 
            {
                printf("\ntype in correct format\n");
                return 1;
            }
            i++;
        }

        if (percentage_bool == 0)
        {
            percentage  = atoi(percentage_str);
        }

        int fine;
        if (percentage >= 0 && percentage <= 100)
        {
            if (percentage >= 90)
            {
                fine = 0;
            }
            else if (percentage >= 80)
            {
                fine = 1000;
            }
            else if (percentage >= 70)
            {
                fine = 2000;
            }
            else if (percentage >= 60)
            {
                fine = 3000;
            }
            else
            {
                fine = 4000;
            }
            printf("The calculated fine for the student %li is : Rs%i\n",reg, fine); 
        }

        else
        {
            printf("Enter a Valid Percentage !");
            break;
        }
    }
    while(reg != 0);
    printf("EXIT\n");

}