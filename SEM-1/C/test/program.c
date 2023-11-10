#include <stdio.h>

// Program 2

// Prototype 
int get_positive_value(void);

int main(void)
{
    printf("Enter EMPLOYEE ID Number");
    int emp_id = get_positive_value();

    printf("Enter the Monthly Income");
    int monthly_income = get_positive_value();

    int annual_income = monthly_income * 12;
    printf("Annual Income (Calculated) : %i\n", annual_income);

    int tax;
    if (annual_income > 500000)
    {
        tax = annual_income * .10;
    }

    else if (annual_income > 250000)
    {
        tax = annual_income * .05;
    }
    else 
    {
        tax = 0;
    }

    printf("Income Tax (Calculated) : %i\n", tax);
    printf("ACTUAL INCOME (After Tax Deduction) : %i \n", annual_income - tax);
}

int get_positive_value(void)
{
    int n;
    do 
    {
        printf(" :");
        scanf("%i", &n);
    }
    while (n < 0);
}