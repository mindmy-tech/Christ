#include <stdio.h>
#include <stdbool.h>
bool isPrime(int n1);
int main(void)
{
    int n1, n2;
    printf("Enter the lower bound value: ");
    scanf("%i",&n1);
    printf("Enter the upper bound value: ");
    scanf("%i",&n2);

    int FLAGS = 0;
    for (int i = n1; i < n2; i++) 
    {
        if (isPrime(i))
        {
            FLAGS ++;
            continue;
        }
    }
    printf("There are Totally %i Prime numbers in the interval [%i,%i]\n",FLAGS,n1,n2);
}

bool isPrime(int n1)
{
    int i = 2;
    while (true)
    {
        if (n1 == 0 || n1 == 1)
        {
            break;
        }

        else if (n1 == i)
        {
            return true;
        }

        else if (n1 % i == 0)
        {
            break;
        }
        else 
        {
            i++;
        }

    }
    return false;
}