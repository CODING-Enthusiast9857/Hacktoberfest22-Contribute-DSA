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

void ibeg();  
void iend();  
void irand();  
void dbeg();  
void dend();  
void drand(); 
void elem();
void skipelem();
void display();  
void search();  

void main()
{
    int ch;
    menu();
    printf("Enter desired Choice");
    scanf("%d",&ch);
    while(ch)
    {
    switch(ch)
    {
            case 1:
            ibeg();  
            break;  
            case 2:  
            iend();  
            break;  
            case 3:  
            irand();  
            break;  
            case 4:  
            dbeg();  
            break;  
            case 5:  
            dend();  
            break;  
            case 6:  
            drand();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:
            elem();
            break;
            case 10:
            skipelem();
            break;
            case 11:  
            exit(0);  
            break;  
            default:  
            printf("Invalid choice");  
    }    
    printf("Enter desired Choice");
    scanf("%d",&ch);
    }
}

void menu()
{
    printf("\n1. Insert at beginning\n2. Insert at the end\n3. Insert at random position\n4. Delete at beginning\n5. Delete at the end\n6. Delete at random position\n7. Search for an element\n8. Display elements\n9. Elements before and after a given position\n10.Element after skipping certain nodes\n11. Exit\n\n");
}
    
void ibeg()
{
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        head->link=head->prev=head;
    }
    else
    {
        newnode->link=head;
        newnode->prev=head->prev;
        head->prev->link=newnode;
        head->prev=newnode;
        
        head=newnode;
        
    }
    printf("Element inserted\n");
   
}

void iend()
{
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->link=newnode->prev=head;
    }
    else
    {
        temp=head;
        while(temp->link!=head)
        {
            temp=temp->link;
        }
        newnode->link=head;
        newnode->prev=temp;
        head->prev=newnode;
        temp->link=newnode;
    }
    printf("Element inserted\n");
}

void irand()
{
    temp=head;
    int loc;
    int i=0;
    newnode=(struct Node *)malloc(sizeof(struct Node)); 
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&loc);
        while(i<loc-1)
        {
            temp=temp->link;
            i++;
            if(temp==head)
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

void dbeg()
{
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        struct Node *del,*temp,*pre;
        del=temp=head;
        while(temp->link!=head)
        temp=temp->link;
        temp->link=head->link;
        head=head->link;
        head->prev=temp;
        free(del);
        del=NULL;
        printf("Element deleted\n");
    }
}

void dend()
{
    
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        struct Node *del,*pre;
        temp=head;
        while(temp->link!=head)
        {
            pre=temp;
            temp=temp->link;
        }
        del=temp;
        pre->link=head;
        head->prev=pre;
        free(del);
        del=NULL;
        printf("Element deleted\n");
    }
}

void drand()
{
    struct Node *del,*d;
    temp=head;
    int loc,i;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&loc);
        for(i=0;i<(loc);i++)
        {
            if(temp->link==head)
            {
                printf("Empty list");
                main();
            }
            del=temp;
            temp=temp->link;
        }
        del->link=temp->link;
        temp->prev=del;
        d=temp;
        free(d);
        d=NULL;
        printf("Element deleted\n");
    }
}

void search()
{
    temp=head;
    int element,i,count;
    count=i=0;
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
                count++;
                break;
            }
            temp=temp->link;
        }while(temp!=head);
        
        if(count>0)
        {
            printf("Element found at position %d\n",i);
        }
        else printf("Not found\n");

    }    
}

void display()
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
            printf("%d ",temp->data);
            temp=temp->link;
        }while(temp!=head);
        printf("\n");
    }
    
}

void elem()
{
    struct Node * previous, *next;
    temp=head;
    int i=1;
    int loc;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&loc);
        while(i<loc)
        {
            temp=temp->link;
            i++;
            if(temp->link==head)
            {
                printf("Empty list");
                main();
            }
        }
        next=temp->link;
        previous=temp->prev;
        printf("%d %d\n",previous->data,next->data);
    }
}

void skipelem()
{
    temp=head;
    int i=0;
    int loc;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        scanf("%d",&loc);
        while(i<loc)
        {
            temp=temp->link;
            i++;
        }
        printf("%d",temp->data);
    }
}