

#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

int placefound, ch;

struct node
{
	int data;
	struct node *next;
};
struct node *newnode, *head, *ptr, *prev;

void createlist()
{
	head = NULL;
}

void insert (int element)
{
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = element;
	newnode->next = NULL;
	if (head==NULL)
	{
		head = newnode;
	}
	else if (element < head->data)
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		ptr = head;
		placefound = 0;
		prev = NULL;
		while(ptr!=NULL && placefound==0)
		{
			if(element > (ptr->data))
			{
				prev = ptr;
				ptr = ptr->next;
			}
			else
			placefound = 1;
		}
		newnode->next = prev->next;
		prev->next = newnode;
	}
}

void display()
{
	struct node *temp;
	temp = head;
	while(temp!=NULL)
	{
		printf("\n%d",temp->data);
		temp = temp->next;
	}
}

void menu()
{
    printf("\n 1.Insert");
    printf("\n 2.Display");
    printf("\n 3.Exit");
    printf("\n Enter your choice: ");
    scanf("%d",&ch);
}

int main()
{
  	createlist();
	do
	{
		menu();
		switch(ch)
		{
			case 1:
				{
					int element;
					printf("\n Enter the element to be inserted: ");
					scanf("%d",&element);
					insert(element);
					break;
				}
			case 2:
				{
					display();
					break;
				}
		    case 3:
				{
					printf("\n Exiting..");
					return 0;
				}				
		}
	}while(ch!=3);
}
