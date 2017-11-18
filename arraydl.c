#include<stdio.h>
int main()
{
	int A[1000];
	int N,i,k;

	printf("Enter the size of the array:");

	scanf("%d",&N);

	for(i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}

	printf("Enter the position to delete:");
	scanf("%d",&k);

	for(i=k;i<=N;i++)
	{
		A[i]=A[i+1];
	}
	N-=1;
	printf("New Array:");
	for(i=1;i<=N;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");

	return 0;
}