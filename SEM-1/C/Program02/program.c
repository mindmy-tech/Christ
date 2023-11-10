#include<stdio.h>

int main(void)
{
    int phonecalls_made;
    printf("Enter The Number of Phone calls Made: ");
    scanf("%i", &phonecalls_made);

    float base_fee = 100;
    if (phonecalls_made > 200)
    {
        base_fee = base_fee + phonecalls_made*2.75;
    }

    else if (phonecalls_made > 150) 
    {
        base_fee = base_fee+ phonecalls_made*2.25;
    }

    else if (phonecalls_made > 100) 
    {
        base_fee = base_fee+ phonecalls_made*2;
    }
    
    else if (phonecalls_made > 50) 
    {
        base_fee = base_fee+ phonecalls_made*1.25;
    }
    printf("Your Phone Bill : %.2f", base_fee);
}