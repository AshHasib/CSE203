#include<bits/stdc++.h>

using namespace std;

struct binarySearchTree
{
	int info;
	struct binarySearchTree *LEFT,*RIGHT;
};

typedef struct binarySearchTree NODE;

NODE *Insert(NODE*,int);
void Search(NODE*,int);
bool Delete(NODE*,int);
void Display(NODE*);

int main()
{
	int num,choice;
	bool flag;
	int element;
	NODE *root=NULL;

	while(1)
	{
		printf("Menu:\n");
		printf("1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			{
				printf("Enter the number you want to insert:");
				scanf("%d",&element);
				root=Insert(root,element);
				//printf("Insertion successful!!!\n");
				break;
			}
			case 2:
			{
				printf("Enter the number to be searched:");
				scanf("%d",&num);
				Search(root,num);
				break;
			}
			case 3:
			{
				printf("Enter the number to be deleted:");
				scanf("%d",&num);
				flag=Delete(root,num);

				if(flag==true)
				{
					printf("Element %d deleted from the tree\n",num);
				}
				else
				{
					printf("Element does not exist\n");
				}
				break;
			}
			case 4:
			{
				Display(root);
				break;
			}
			case 5:
			{
				printf("Exitting. . . . .  . . \n");
				return 0;
			}
			default:
			{
				printf("Invalid choice. Try again\n");
			}
		}
	}
	return 0;
}

NODE* Insert(NODE *r,int n)
{
	if(r==NULL)
	{
		r=(NODE*)malloc(sizeof(NODE));
		r->LEFT=NULL;
		r->RIGHT=NULL;
		r->info=n;
		printf("Operation successful!!!\n");
	}
	else if(n<r->info)
	{
		r->LEFT=Insert(r->LEFT,n);
	}
	else if(n>r->info)
	{
		r->RIGHT=Insert(r->RIGHT,n);
	}
	else if(r->info==n)
	{
		printf("Operation failed. Duplicate Entry\n");
	}
	return r;
}

void Search(NODE* r,int n)
{
	if(r==NULL)
	{
		printf("The number does not exist\n");
	}
	else if(r->info==n)
	{
		printf("The number exists in the tree\n");
	}
	else if(n<r->info)
	{
		Search(r->LEFT,n);
	}
	else if(n>r->info)
	{
		Search(r->RIGHT,n);
	}

}


bool Delete(NODE* r,int n)
{
	NODE *PTR;
	if(r==NULL)
	{
		return false;
	}
	else if(n<r->info)
	{
		return (Delete(r->LEFT,n));
	}
	else if(n>r->info)
	{
		return (Delete(r->RIGHT,n));
	}
	else
	{
		if(r->LEFT==NULL)
		{
			PTR=r;
			r=r->RIGHT;
			free(PTR);
			return true;
		}
		else if(r->RIGHT==NULL)
		{
			PTR=r;
			r=r->LEFT;
			free(PTR);
			return true;
		}
		else
		{
			PTR=r->LEFT;
			while(PTR->RIGHT!=NULL)
			{
				PTR=PTR->RIGHT;
			}
			r->info=PTR->info;
			return (Delete(r->LEFT,PTR->info));
		}

	}
}

void Display(NODE *r)
{
	if(r->LEFT!=NULL)
	{
		Display(r->LEFT);
	}
	printf("%d\n",r->info);
	if(r->RIGHT!=NULL)
	{
		Display(r->RIGHT);
	}
}