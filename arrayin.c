#include<stdio.h>
int main()
{
	int A[1000];
	int N;
	int i,k,p;
	printf("Enter size of the array:");
	scanf("%d",&N);

	printf("Enter elements:");
	for(i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("Enter new value:");
	scanf("%d",&k);

	printf("Enter posiition:");
	scanf("%d",&p);

	for(i=N;i>=p;i--)
	{
		A[i+1]=A[i];
	}
	N+=1;
	A[p]=k;
	printf("New Array:");
	for(i=1;i<=N;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");

	return 0;
}