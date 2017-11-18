#include<stdio.h>
#define MAX 100
int Q[MAX];
int front=-1;
int rear=-1;

void insert(int);

int Delete();

void Display();

int main()
{
	int choice;
	int num;

	printf("QUEUE__________________________\n");
	while(1)
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");

		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			{
				printf("Enter element:");
				scanf("%d",&num);
				insert(num);
				break;
			}
			case 2:
			{
				num=Delete();
				if(num==-1)
				/*{
					printf("Queue is empty\n");
				}*/;
				else
				{
					printf("Successfully deleted %d from the queue\n",num);

				}
				break;
			}
			case 3:
			{
				Display();
				break;
			}
			case 4:
			{
				printf("Exiting. . . . . . . . . .\n");
				return 0;
			}
			default:
			{
				printf("Invalid choice\n");
			}
		}
	}
}

void insert(int n)
{
	if(front==-1)
	{
		front=rear=0;
		Q[front]=n;
		printf("INSERTION SUCCESSFUL\n");
		return;
	}
	if(rear==MAX-1)
	{
		printf("QUEUE IS FULL\n");
		return;
	}
	rear++;
	Q[rear]=n;
	printf("INSERTION SUCCESSFUL\n");
}

int Delete()
{
	int  i;
	if(front==-1 && rear==-1)
	{
		printf("Queue is Empty\n");
		return -1;
	}
	if(front==-1 &&front==rear)
	{
		i=Q[front];
		front=-1;
		rear=-1;
		return i;
	}
	return Q[front++];
}

void Display()
{
	int i;
	if(front==-1)
	{
		printf("QUEUE IS EMPTY\n");
		return ;
	}
	printf("QUEUE:");
	for(i=front;i<=rear;i++)
	{
		printf("%d\t",Q[i]);
	}
	printf("\n");
}
