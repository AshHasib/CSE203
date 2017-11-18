#include<bits/stdc++.h>
//This is an implementation of a singly Linked List
using namespace std;

struct node
{
	int info;
	struct node *next;
};
typedef struct node NODE;

void Insert(int);
int Delete(int);
void Display();
NODE *Search(int);
NODE *FIRST=NULL;
NODE *LAST=NULL;
int main()
{
	int num1,num2;
	int choice;
	NODE *loc;


	while(1)
	{
		printf("MENU:\n");
		printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		
		switch(choice)
		{
			case 1:
			{
				printf("Enter a number:");
				scanf("%d",&num1);
				Insert(num1);
				break;
			}


			case 2:
			{
				printf("Enter the element you want to delete from the list:");
				scanf("%d",&num1);
				num2=Delete(num1);
				if(num2==-999)
				{
					printf("Element not present in the list\n");
				}
				else
				{
					printf("Successfully deleted %d from the list\n",num2);
				}
				break;
			}


			case 3:
			{
				printf("Enter the element to be searched:");
				scanf("%d",&num1);
				loc=Search(num1);
				if(loc==NULL)
				{
					printf("%d is not present in the list\n",num1);
				}
				else
				{
					printf("%d is present in the list\n",num1);
				}
				break;
			}


			case 4:
			{
				Display();
				break;
			}


			case 5:
			{
				return 0;
			}


			default:
			{
				printf("invalid input,please try again\n");
			}
		}
	}
}

void Insert(int num)
{
	NODE *ptr=(NODE*)malloc(sizeof(NODE));
	ptr->info=num;

	if(FIRST==NULL)
	{
		FIRST=LAST=ptr;ptr->next=NULL;
	}
	else
	{
		LAST->next=ptr;
		ptr->next=NULL;
		LAST=ptr;
	}
}


int Delete(int num)
{
	NODE *LOC,*TMP;
	int i=num;

	LOC=Search(i);

	if(LOC==NULL)
	{
		return -999;
	}
	if(LOC==FIRST)
	{
		if(FIRST==LAST)
		{
			FIRST=LAST=NULL;
		}
		else
		{
			FIRST=FIRST->next;
			return num;
		}
	}
	for(TMP==FIRST;TMP->next!=LOC;TMP=TMP->next); //updating the TMP pointer

	TMP->next=LOC->next;
	if(LOC==LAST)
	{
		LAST=TMP;
		return (LOC->info);
	}
}


NODE *Search(int num)
{
	NODE *PTR;

	for(PTR==FIRST;PTR!=LAST;PTR=PTR->next)
	{
		if(PTR->info==num)
		{
			return PTR;
		}
	}
	if(LAST->info==num)
	{
		return LAST;
	}
	else return NULL;
}

void Display()
{
	NODE *PTR;

	if(FIRST==NULL)
	{
		printf("Empty List!!!\n");
		return;
	}
	printf("Linked List Elements:");
	if(FIRST==LAST)
	{
		printf("%d\n",LAST->info);
		return;
	}
	for(PTR=FIRST;PTR!=LAST;PTR=PTR->next)
	{
		printf("%d\t",PTR->info);
	}
	printf("%d\n",LAST->info);

}