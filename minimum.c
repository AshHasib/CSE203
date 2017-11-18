#include<stdio.h>

int main() {
    int A[1000];
    int N,i,min;

    printf("Enter size:");
    scanf("%d",&N);

    printf("Enter elements:");
    for(i=0;i<N;i++) {
        scanf("%d",&A[i]);
    }

    min=A[0];

    for(i=0;i<N;i++){
        if(A[i]<min) {
            min=A[i];
        }
    }
    printf("Minimum number in the array:%d\n",min);

    return 0;
}
