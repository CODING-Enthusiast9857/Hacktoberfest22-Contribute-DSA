#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	int priority;
	struct Node* next;
};

void insert(struct Node** head,char d,int p)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=(int)d;
	node->priority=p;
	node->next=NULL;
	if(*head==NULL){
		*head=node;
	}
	else{
		struct Node* start=*head;
		if((*head)->priority>p){
			node->next=(*head);
			(*head)=node;
		}
		else{
			while(start->next!=NULL && start->next->priority < p){
				start=start->next;
			}
			node->next=start->next;
			start->next=node;
		}
	}
}
int peek(struct Node** head)
{
	return (*head)->data;
}

void delete(struct Node** head)
{
	struct Node* temp = *head;
	(*head) = (*head)->next;
	//print temp.data
	free(temp);
}


int isEmpty(struct Node** head)
{
	return (*head) == NULL;
}
int main()
{
    int n,p;
    char d;
    struct Node* head=NULL;
    printf("Enter no of tasks: ");
    scanf("%d",&n);
    printf("Enter %d tasks in order - <data><space><priority>\n",n);
    for(int i=0;i<n;i++){
        printf("task %d: ",i+1);
		fflush(stdin);
        scanf("%c %d",&d,&p);
        insert(&head,d,p);
    }
    printf("\n");
	while (!isEmpty(&head)) {
		printf("%c >> ", peek(&head));
		delete(&head);
	}
	printf("NULL \n");

	return 0;
}
