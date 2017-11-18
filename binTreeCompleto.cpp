#include<bits/stdc++.h>
using namespace std;


int counter=1;
struct binaryTree
{
	int info;
	struct binaryTree *LEFT,*RIGHT;
};
typedef struct binaryTree NODE;


NODE *Insert(NODE*,int);
void preorder(NODE*);
void inorder(NODE*);
void postorder(NODE*);

int main()
{
	NODE *root=NULL;
	int num,choice;

	while(1)
	{
		printf("MENU:\n");
		printf("1.Insert\n2.Pre-Order traversal\n3.Inorder Traversal\n4.Post-Order Traversal\n5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("Enter your number:");
				scanf("%d",&num);
				root=Insert(root,num);
				break;
			}
			case 2:
			{
				preorder(root);
				printf("\n");
				break;
			}
			case 3:
			{
				inorder(root);
				printf("\n");
				break;
			}
			case 4:
			{
				postorder(root);
				printf("\n");
				break;
			}
			case 5:
			{
				return 0;
			}
			default:
			{
				printf("Invalid choice. Please Try again\n");
			}

		}
	}
	return 0;
}



NODE *Insert(NODE *r,int n)
{
	if(r==NULL)
	{
		r=(NODE*)malloc(sizeof(NODE));
		r->info=n;
		counter++;
	}
	else
	{
		if(counter%2==0)
		{
			r->LEFT=Insert(r->LEFT,n);
		}
		else
		{
			r->RIGHT=Insert(r->RIGHT,n);
		}
	}
	return r;
}

void preorder(NODE *r)
{
	if(r!=NULL)
	{
		printf("%d\t",r->info);
		preorder(r->LEFT);
		preorder(r->RIGHT);
	}
}

void inorder(NODE *r)
{
	if(r!=NULL)
	{
		inorder(r->LEFT);
		printf("%d\t",r->info);
		inorder(r->RIGHT);
	}
}

void postorder(NODE *r)
{
	if(r!=NULL)
	{
		postorder(r->LEFT);
		postorder(r->RIGHT);
		printf("%d\t",r->info);
	}
}