#include<stdio.h>
#include<stdlib.h>

struct Node *head = NULL;
struct Node *newnode,*temp;

struct Node
{
    int data;
    struct Node *link;
    struct Node *prev;
};

void IAB();
void IAE();
void IAR();
void DAB();
void DAE();
void DAR();
void SAE();
void DE();
void EASCN();

void main(void)
{
    menu();
    int choice;
    printf("Enter desired Choice");
    scanf("%d",&choice);
    while(choice)
    {
    switch(choice)
    {
        case 1: IAB();break;
        case 2: IAE();break;
        case 3: IAR();break;
        case 4: DAB();break;
        case 5: DAE();break;
        case 6: DAR();break;
        case 7: SAE();break;
        case 8: DE();break;
        case 9: EASCN();break;
        case 10:exit(0);break;
        default: printf("Invalid Choice!\n");
    }
    menu();
    printf("Enter desired Choice");
    scanf("%d",&choice);
    }
    
}

void menu()
{
    printf("\n1. Insert at beginning\n2. Insert at the end\n3. Insert at random position\n4. Delete at beginning\n5. Delete at the end\n6. Delete at random position\n7. Search for an element\n8. Display elements\n9. Element after skipping certain nodes\n10. Exit\n\n");
}

void IAB()
{
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->link=newnode->prev=NULL;
    }
    else
    {
        newnode->link=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
        
    }
    printf("Element inserted\n");
   
}

void IAE()
{
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->link=newnode->prev=NULL;
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        newnode->link=NULL;
        newnode->prev=temp;
        temp->link=newnode;
    }
    printf("Element inserted\n");
}

void IAR()
{
    temp=head;
    int index;
    int i=0;
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&index);
        while(i<index-1)
        {
            temp=temp->link;
            i++;
            if(temp==NULL)
            {
                printf("Empty list\n");
                main();
            }
        }
        scanf("%d",&newnode->data);
        newnode->link=temp->link;
        newnode->prev=temp;
        temp->link=newnode;
        printf("Element inserted\n");
    }
   
}

void DAB()
{
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        struct Node *del;
        del=head;
        head=head->link;
        head->prev=NULL;
        free(del);
        printf("Element deleted\n");
    }
}

void DAE()
{
    
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        struct Node *del,*pre;
        temp=head;
        while(temp->link!=NULL)
        {
            pre=temp;
            temp=temp->link;
        }
        del=temp;
        pre->link=NULL;
        free(del);
        printf("Element deleted\n");
    }
}

void DAR()
{
    struct Node *del,*d;
    temp=head;
    int index,i;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&index);
        for(i=0;i<(index);i++)
        {
            if(temp->link==NULL){printf("Empty list");main();}
            del=temp;
            temp=temp->link;
        }
        del->link=temp->link;
        d=temp;
        free(d);
        printf("Element deleted\n");
    }
}

void SAE()
{
    temp=head;
    int element,i,count;count=i=0;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&element);
        do
        {
            i++;
            if(temp->data==element)
            {
                count++;break;
            }
            temp=temp->link;
        }while(temp!=NULL);
        
        if(count>0)
        {
            printf("Element found at position %d\n",i);
        }
        else printf("Not found\n");

    }    
}

void DE()
{
    temp=head;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        do
        {
            printf("%d ",temp->data);temp=temp->link;
        }while(temp!=NULL);
        printf("\n");
        
    }
    
}

void EASCN()
{
    struct Node * previous, *next;
    temp=head;
    int i=1;int index;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&index);
        while(i<index)
        {
            temp=temp->link;
            i++;
            if(temp->link==NULL){printf("Empty list");main();}
        }
        next=temp->link;previous=temp->prev;
        printf("%d %d\n",previous->data,next->data);
    }
}