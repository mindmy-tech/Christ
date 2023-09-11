#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[] = "Yo !";
    printf("the length of \"%s\" is : %i\n", string, strlen(string));

    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    printf("the length of \"%s\" is : %i\n", string, i);
    
}