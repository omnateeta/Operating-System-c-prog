//Develop a c program to simulate producer consumer problem using semaphores,classical problem solver..
#include<stdio.h>
int main()
{
	int buffer[10],bufsize,in,out,producer,consumer;
	int choice=0;
	in=0;
	out=0;
	bufsize=10;
	while(choice!=3)
	{
		printf("\n1.producer,\t2.consume,\t3.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(((in+1)%bufsize)==out)
					printf("Buffer is full");
					else
					{
						printf("Enter the value:");
						scanf("%d",&producer);
						buffer[in]=producer;
						in=(in+1)%bufsize;
					}
					break;
			case 2:if(in==out)
					printf("Buffer is empty");
				   else
				   {
				   	consumer=buffer[out];
				   	printf("\n The consumed value is %d\n",consumer
					   );
				   	out=(out+1)%bufsize;
					   }	
					   break;
		}
	}
}
