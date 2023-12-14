#include <stdio.h>
int factorial(int n);

int main(void) {


    int n = 1;
    int police, theif;
    do {
        n++;
        police = n * 23;
        theif = factorial(n);
    }
    while(!(police == theif));
    printf("Days :%i", n);

}


int factorial(int n)
{
    if ( n == 1)
    {
        return  1;
    }

    else {
        return n + factorial(n -1);
    }
}

