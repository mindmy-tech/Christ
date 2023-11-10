#include <stdio.h>
#include <string.h>

int main(void)
{
    char reg[10];
    char blocked_reg[] = "2340190";
    printf("enter reg no:");
    scanf("%s", &reg);
    if (strcmp(reg, blocked_reg))
    {
        printf("Not blocked ");
    }
    else
    {
        printf("blocked ");
    }
}