#include<stdio.h>
#define MAX_BLOCKS 10
#define MAX_PROCESSES 10

void firstFit(int blockSize[],int m, int processSize[],int n);
void bestFit(int blockSize[],int m, int processSize[],int n);
void worstFit(int blockSize[],int m, int processize[],int n);

int main()
{
int blockSize[MAX_BLOCKS],processSize[MAX_PROCESSES];
int m,n,i,j,choice;
printf("Enter number of blocks:");
scanf("%d",&m);
printf("Enter the size of each block:\n");
for(i=0;i<m;i++)
{
	printf("Block %d:",i+1);
	scanf("%d",&blockSize[i]);
}
printf("Enter the number of process:");
scanf("%d",&n);
printf("Enter the size of each process:");
for(i=0;i<n;i++)
{
	printf("Process %d:",i+1);
	scanf("%d",&processSize[i]);
}
printf("\nChoose the memory allocation technique:");
printf("\n1.First Fit");
printf("\n2.Best Fit");
printf("\n3.Worst Fit");
printf("\nEnter your choice:");
scanf("%d",&choice);

switch(choice)
{
	case 1: firstFit(blockSize,m,processSize,n);
			break;
	case 2:bestFit(blockSize,m,processSize,n);
			break;
	case 3:worstFit(blockSize,m,processSize,n);
			break;
	default:
		printf("Invalid choice");
}
return 0;
}

void firstFit(int blockSize[],int m, int processSize[],int n)
{
	int i,j;
	int allocation[MAX_PROCESSES];
	for(i=0;i<n;i++)
	{
		allocation[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(blockSize[j]>=processSize[i])
			{
				allocation[i]=j;
				blockSize[j]-=processSize[i];
				break;
			}
		}
	}
	printf("\n First Fit Allocatiopn\n");
	printf("Process No.\tProcess size\t Block No.\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t",i+1,processSize[i]);
		if(allocation[i]!=-1)
		{
			printf("%d\n",allocation[i]+1);
		}
		else
		   printf("Not Allocated\n");
	}
}


void bestFit(int blockSize[],int m, int processSize[],int n)
{
	int i,j;
	int allocation[MAX_PROCESSES];
	for(i=0;i<n;i++)
	{
		allocation[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		int bestIdx=-1;
		for(j=0;j<m;j++)
		{
			if(blockSize[j]>=processSize[i])
			{
				if(bestIdx=-1||blockSize[j]<blockSize[bestIdx])
				{
					bestIdx=j;
				}
			}
		}
	
		if(bestIdx!=-1)
		{
			allocation[i]=bestIdx;
			blockSize[bestIdx]-=processSize[i];
		}
	}

	printf("\n Best Fit Allocatiopn\n");
	printf("Process No.\tProcess no\tprocess size\tBlock No.");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t",i+1,processSize[i]);
		if(allocation[i]!=-1)
		{
			printf("%d\n",allocation[i]+1);
		}
		else
		   printf("Not Allocated\n");
	}
}



void worstFit(int blockSize[],int m, int processSize[],int n)
{
	int i,j;
	int allocation[MAX_PROCESSES];
	for(i=0;i<n;i++)
	{
		allocation[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		int worstIdx=-1;
		for(j=0;j<m;j++)
		{
			if(blockSize[j]>=processSize[i])
			{
				if(worstIdx=-1||blockSize[j]<blockSize[worstIdx])
				{
					worstIdx=j;
				}
			}
	
		}
	
		if(worstIdx!=-1)
		{
			allocation[i]=worstIdx;
			blockSize[worstIdx]-=processSize[i];
		}
	}

	printf("\n Worst Fit Allocation\n");
	printf("Process No.\tProcess no\tprocess size\tBlock No.\n");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t",i+1,processSize[i]);
		if(allocation[i]!=-1)
		{
			printf("%d\n",allocation[i]+1);
		}
		else
		   printf("Not Allocated\n");
	}
}


