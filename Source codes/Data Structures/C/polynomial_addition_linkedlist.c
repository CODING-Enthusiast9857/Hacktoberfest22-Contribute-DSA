#include<stdio.h>
#include<stdlib.h>

struct linked_list{
    int power;
    int coef;
    struct linked_list *next;
};
typedef struct linked_list node;

void create(node *listhead){
    int c;
    //taking struct members
    printf("Enter the power of variable:");
    scanf("%d",&listhead->power);
    printf("Enter the coeficient of variable:");
    scanf("%d",&listhead->coef);
    //checking condition 
    printf("Enter 1 if this node is the last node else 0:");
    scanf("%d",&c);
    if(c==1) listhead->next == NULL;
    else{
        listhead->next = (node *)malloc(sizeof(node));
        //creating next node
        create(listhead->next);
    }
    return;
}

void copy(node *listhead1,node *listhead3){
    //copying struct members
    listhead3->power = listhead1->power;
    listhead3->coef = listhead1->coef;
    //checking condition
    if(listhead1->next == NULL) listhead3->next = NULL;
    else{
        listhead3->next = (node *)malloc(sizeof(node));
        //creating next node
        copy(listhead1->next,listhead3->next);
    }
    return;
}

int find(int lh2p,int lh2c,node *lh3){
    int c;
    if(lh3->power == lh2p){
        lh3->coef += lh2c;
        return 1;
    }
    else{
        if(lh3->next == NULL) return 0;
        else c = find(lh2p,lh2c,lh3->next);
    }
    return(c);
}

node *insert(int lh2p,int lh2c,node *lh3){
    node *new;
    new = (node *)malloc(sizeof(node));
    new->power = lh2p;
    new->coef = lh2c;
    new->next = lh3;
    lh3 = new;
    return(lh3);
}

node *add(node *listhead2,node *listhead3){
    int c;
    c = find(listhead2->power,listhead2->coef,listhead3);
    if(c==1){
        if(listhead2->next == NULL) return(listhead3);
        else add(listhead2->next,listhead3);
    }
    else{
        listhead3 = insert(listhead2->power,listhead2->coef,listhead3);
        if(listhead2->next == NULL) return(listhead3);
        else add(listhead2->next,listhead3);
    }
}

void print(node *listhead3){
    if(listhead3->next != NULL){
        printf("Coefficient:%d,Power:%d-->",listhead3->coef,listhead3->power);
        if((listhead3->next)->next == NULL) printf("Coefficient:%d,Power:%d",(listhead3->next)->coef,(listhead3->next)->power);
        print(listhead3->next);
    }
    return;
}

int main(){
    node *head1;
    node *head2;
    node *head3;
    head1 = (node *)malloc(sizeof(node));
    head2 = (node *)malloc(sizeof(node));
    head3 = (node *)malloc(sizeof(node));
    //creating the first list
    printf("Enter the first list:\n");
    create(head1);
    //creating the second list
    printf("Enter the second list:\n");
    create(head2);
    //copy list1 to list3
    copy(head1,head3);
    //addition of list3 & list2
    head3 = add(head2,head3);
    //printing the result
    print(head3);
    //freeing up the space
    free(head1);
    free(head2);
    free(head3);
    return 0;
}