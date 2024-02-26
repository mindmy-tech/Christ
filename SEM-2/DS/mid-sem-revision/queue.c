#include<stdio.h>
#include<conio.h>

#define MAX 5


int ch;

struct queue
{
	int a[MAX];
	int rear;
}q;



void enqueue(int);
void dequeue();
void display();
int main()
{
	int ele;
	q.rear=-1;
	do
	{

		printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice :");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				{   
				    printf("Enter element to be inserted\n");
					scanf("%d",&ele);
					enqueue(ele);
					break;
				}
			
			case 2:
				{
					dequeue();
					break;
				}
			case 3:
				{ 
					display();
					break;
				}
			case 4:
				{
					printf("\nExiting...");
					break;					
				}
		} 
	}while(ch!=4);
}

void enqueue(int ele)
{
	if(q.rear==MAX-1)
	printf("Error overflow\n");
	else
	{
		q.rear++;
		q.a[q.rear] = ele;
	}
}
void dequeue()
{
	int i;
	if(q.rear==-1)
	printf("Error, underflow\n");
	else
	{   
	   for(i=0;i<q.rear;i++)
		    q.a[i] = q.a[i+1];
	    q.rear--;
	}
}
void display()
{
	if(q.rear==-1)
	printf("\nNo elements in queue\n");
	printf("\nElements in the queue:\n");
	int i;
	for(i=0;i<=q.rear;i++)
	printf("%d \n",q.a[i]);
}

