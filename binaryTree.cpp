#include<bits/stdc++.h>

using namespace std;

struct binTree{
    int info;
    struct binTree *LEFT,*RIGHT;
};
typedef struct binTree node;

node *Insert(node*,int);
void display(node*);

int counter=1;


int main() {
    node *root=NULL;
    int num,choice;

    while(1) {
        printf("1.Insert\n2.Display\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                printf("Enter an element:");
                scanf("%d",&num);
                root=Insert(root,num);
                break;
            }
            case 2: {
                display(root);
                break;
            }
            case 3: {
                return 0;
            }
            default: {
                printf("Invalid choice ,please try again\n");
            }
        }
    }
}

node *Insert(node *r,int n) {
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->LEFT=r->RIGHT=NULL;
        r->info=n;
        counter++;
    }
    else {
        if(counter%2==0) {
            r->LEFT=Insert(r->LEFT,n);
        }
        else {
            r->RIGHT=Insert(r->RIGHT,n);
        }
    }
    return r;
}

void display(node *r) {
    if(r->LEFT!=NULL){
        display(r->LEFT);
    }
    printf("%d\n",r->info);

    if(r->RIGHT!=NULL) {
        display(r->RIGHT);
    }
}
