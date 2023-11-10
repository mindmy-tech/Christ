#include <stdio.h>
int main(void) 	
{
	int citycode[5];
	int temp[5][4];
	int i,j,k;
	
	for(i=0;i<5;i++)
	{
	    printf("\nENTER CODE OF THE CITY: ");
	    scanf("%d",&citycode[i]);
	    for(j=0; j<4;j++)
	    { 

            printf("ENTER THE TEMPERATURE OF %d FOR WEEK %d: ",citycode[i],j);
            scanf("%d",&temp[i][j]);
	    }
        
    }		
}