/*
program for memory management using best fit algorithm
*/

#include <stdio.h>
#include <stdlib.h>

float *memory, *process;

int minimum(float process,int mUnit)
	{
		int min=-1,i;
		for(i = 0; i < mUnit; i++)
		{
			if(memory[i] >= process)
			{
				if(min==-1)
				{
					min=i;
				}
				else if(memory[i]<=memory[min])
				{
					min=i;
				}
			}
		}
		return min;	
	}
	
int main() 
{
	int i, j, pNumber, mUnit,min;
	int *alloc;
	printf("Enter the number of memory units:\n");
	scanf("%d", &mUnit);
	memory = (float *)malloc(mUnit * sizeof(float));
	for(i = 0; i < mUnit; i++)
	{
		printf("Enter the memory unit %d:", i);
		scanf("%f", &memory[i]);
	}
	printf("Enter the number of processes:");
	scanf("%d", &pNumber);
	process = (float *) malloc (pNumber * sizeof(float));
	alloc=(int *)malloc (pNumber * sizeof(int));
		for(i = 0; i < pNumber; i++)
	{
		printf("\nEnter the process memory %d:", i);
		scanf("%f", &process[i]);
	}
	printf("\n|");
	
	for(i=0;i<pNumber;i++)	//Initializing allocation array
	{
		alloc[i]=-1;
	}
		for(i=0;i<pNumber;i++)
	{
		min=minimum(process[i],mUnit);
		if(min>=0)
		{
			alloc[i]=min;
			memory[min]=memory[min]-process[i];
		}
	}
	
	printf("Allocation array is: ");
	for(i=0;i<pNumber;i++)
	{
		printf("%d ",alloc[i]);
	}
	return 0;
}

		


	
		
