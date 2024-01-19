#include <stdio.h> 
 
void del(int a[], int high,int pos,int num);

int main ()  
{  
    int a[50];  
    int pos, i, num;

    printf (" \n Enter the number of elements :  ");  
    scanf (" %d", &num);  
    printf (" \n Enter elements in array: \n ", num);  
    for (i = 0; i < num; i++ )  
    {   printf (" elements = ", i);  
        scanf (" %d", &a[i]);  
    }  
    printf( " Position you want to delete:  ");  
    scanf (" %d", &pos); 
     
     
     del(a,num-1,pos,num);
      
}

void del(int a[], int high,int pos,int num)
{
	int i = pos-1;
	        for(;i <high; i++)  
        {  
            a[i] = a[i+1];   
        }  
        num = num - 1;
        
	int j;	
	for(j=0;j<num;j++)
	{
		printf("%d",a[j]);
	}

}