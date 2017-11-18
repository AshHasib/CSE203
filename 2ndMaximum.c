#include<stdio.h>

int main() {

    int A[1000];
    int N,i,m1,m2;

    printf("Enter size:");
    scanf("%d",&N);

    printf("Enter elements:");
    for(i=0;i<N;i++) {
        scanf("%d",&A[i]);
    }

    m1=A[0];
    m2=A[0];

    for(i=0;i<N;i++) {
        if(A[i]>m1) {
            m2=m1;
            m1=A[i];

        }
        if((A[i]>m2)&&(A[i]<m1)) {
            m2=A[i];
        }
    }
    printf("1st maximum:%d\n",m1);
    printf("2nd maximum:%d\n",m2);

    return 0;
}
