#include<stdio.h>

int main()
{
    int A[1000];
    int N,i,max;
    printf("Enter size:");
    scanf("%d",&N);

    printf("Enter elements:");
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    max=A[0];

    for(i=0;i<N;i++) {
        if(A[i]>max) {
            max=A[i];
        }
    }
    printf("MAXIMUM NUMBER IN THE ARRAY IS:%d\n",max);

    return 0;
}
