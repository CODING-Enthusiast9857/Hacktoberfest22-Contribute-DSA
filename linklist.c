#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL;
void create(int A[],int n){
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }}
    void Display(struct Node *p){
        while(p){
            printf("%d ",p->data);
            p=p->next;
 }}
void insertNumber(struct Node *p,int pos,int x,int n){
    struct Node *q;
    if(pos<0|| pos>n) return;
    q=(struct Node*)malloc(sizeof(struct Node));
    q->data=x;
    if(pos==0){
        q->next=first;
        first=q;
    }
    else{
        for(int i=0;i<n-1;i++)  p=p->next;
        q->next=p->next;
        p->next=q;
    }
}

int deleteNumber(struct Node *p,int pos,int n){
    struct Node *q;
    int x=-1;
    if(pos<1||pos>n) return -1;
    if(pos==1){
        q=first;
        x=q->data;
    first=first->next;
    free(q);
    return x;
    }
    else{
        for(int i=0;i<pos-1;i++){
        q=p;
        p=p->next;}
        q->next=p->next;
       x=p->data;
        free(p);
        return x;
    }
}
/*void insertLast(struct Node *p,int x){
    int *Newnode;
    Newnode=(struct Node*)malloc(sizeof(struct Node));
 struct Node *last;
 Newnode->data=x;
 Newnode->next=NULL;
 if(first==NULL) first=last=Newnode;
 else{
    while(p)
    last=last->next;
    last->next=t;
    last=t;
 }   
}*/
void checkDuplicate(struct Node *p){
    struct Node *q=p->next;
    while(q!=NULL){
        if(p->data==q->data){
        p->next=q->next;
        free(q);
        q=p->next;}
        else{
        p=q;
        q=q->next;
        }
    }
}


int main(){
int A[10];
printf("Enter the length of the elements\n");
int n;
scanf("%d",&n);
for(int i=0;i<n;i++) scanf("%d",&A[i]);
create(A,n);
Display(first);
//int pos,x;
//printf("\nEnter the position and value to be print\n");
//scanf("%d%d",&pos,&x);
//insertNumber(first,pos,x,n);
//Display(first);
printf("\nEnter the position where you want to delte\n");
int delpos;
scanf("%d",&delpos);
deleteNumber(first,delpos,n);
//printf("Deleted number is %d\n",);
// printf("Newnode-");
// int y;
// scanf("%d",&y);
//insertLast(first,y);
Display(first);
//printf("\nCheck duplicate elements\n");
//checkDuplicate(first);
//Display(first);
return 0;
}
    