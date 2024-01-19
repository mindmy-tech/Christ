#include <stdio.h>

void insert(int a[100],int high,int pos , int element , int n);

int main(void)
{
	int a[100],n,i,pos,element;
		
	printf("Number of elements: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Element %d: ",i);
		scanf("%d",&a[i]);
	}
	
	printf("Element to be added: ");
	scanf("%d",&element);
	printf("Position: ");
	scanf("%d",&pos);
	
	insert(a,n-1,pos,element,n);
	
}

void insert(int a[100],int high,int pos , int element , int n)
{
	int i;
	{
		a[i+1]=a[i];
		i =i-1;
	}
	a[pos]=element;
	n = n+1;
	
	int x;
	printf("Array");
	for(x=0;x<n;x++)
	{
		printf(" %d",a[x]);
	}
}