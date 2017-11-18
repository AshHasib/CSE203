#include<stdio.h>
#define MAX 5

int S[MAX];
int top=-1;

void push(int);
int pop();
void Display();

int main()
{
	int choice,num;

	printf("__________STACK_________\n");
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			{
				printf("\nEnter a number:");
				scanf("%d",&num);
				push(num);
				break;
			}
			case 2:
			{
				num=pop();
				if(num==-9999)
				{
					printf("POP OPERATION FAILED\n");
				}
				else
				{
					printf("\nSuccessfully popped %d form the stack\n",num);
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
				return 0;
			}
			default:
			{
				printf("INVALID CHOICE\n");
				break;
			}

		}
	}

	return 0;
}


void push(int N)
{
	if(top==MAX-1)
	{
		printf("STACK FULL\n");
		return ;
	}
	top++;
	S[top]=N;
	
	printf("PUSH OPERATION SUCCESSFUL\n");
}

int pop()
{
	if(top==-1)
		return -9999;
	else
		return S[top--];
}
void Display()
{
	int i;
	if(top==-1)
	{
		printf("STACK EMPTY\n");
		return ;
	}
	printf("STACK:");
	for(i=top;i>=0;i--)
	{
		printf("%d\t",S[i]);
	}
	printf("\n");
}