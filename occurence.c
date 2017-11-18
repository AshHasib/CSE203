#include<stdio.h>

int main() {
    int A[1000];
    int N,i,key,count=0;

    printf("Enter size:");
    scanf("%d",&N);

    printf("Enter elements:");
    for(i=0;i<N;i++) {
        scanf("%d",&A[i]);
    }
    printf("Enter key:");
    scanf("%d",&key);

    for(i=0;i<N;i++){
        if(A[i]==key)
            count++;
    }
    if(count==0) {
        printf("This number does not exist in the array\n");
    }
    else if(count==1){
        printf("%d is in the array for 1 time\n",key);
    }
    else {
        printf("%d is in the array for %d times\n",key,count);
    }
}
