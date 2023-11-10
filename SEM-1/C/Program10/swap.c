#include <stdio.h>

void change(int *num);
void swap( int *n1, int *n2);
int main(void)
{
    int n = 100;
    int y = 200;
    printf("Before swap x:%i y:%i\n", n,y);
    swap(&n,&y);
    printf("After swap x:%i y:%i\n", n,y);
}

void change(int *num)
{
    printf("before adding value inside fn : %i\n", *num);
    *num += 100;
}

void swap( int *n1, int *n2)
{
    int buffer = *n1;
    *n1 =  *n2;
    *n2 = buffer;
}