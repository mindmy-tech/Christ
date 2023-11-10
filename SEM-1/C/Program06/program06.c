#include <stdio.h>
#include <string.h>


int main(void)
{
    const int no_citys = 2;
    const int no_days = 3;
    char days[][100] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    char citys[][100] = {"Bangalore", "Chennai", "Kochi", "Kolkata", "Delhi", "Goa", "Pondycherry", "Pune"};
    char data_vault[no_citys][no_days][10];
    for (int i = 0; i < no_days; i++)
    {
        for (int j = 0; j< no_citys;j++)
        {
            char buffer[100];
            printf("What the weather at %s on  %s :",citys[j], days[i]);
            fgets(data_vault[j][i], 100, stdin);
            char *newline = strchr(data_vault[j][i], '\n');
            if (newline != NULL) {
                *newline = '\0'; 
            }
        }
    }
    printf("+==========================+\n");
    printf("|Days\t |City\t  |Weather  |\n");
    printf("+==========================+\n");

    for (int i = 0; i < no_days; i++)
    {
        for (int j = 0; j < no_citys ; j++)
        {
            printf("\n|%s\t |%s\t |%s\t |\n",days[i], citys[j],data_vault[j][i]);
        }
    }
}

