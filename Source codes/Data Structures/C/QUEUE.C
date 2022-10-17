#include<stdio.h>
#include<conio.h>
#define MAX 5
void main()
{
	int q[MAX],rear,front,i,ele,ch;
	clrscr();
	rear=front=-1;
	while(1)
	{
		printf("\n1:Insert\n2:Delete\n3:display\n4:exit\nenter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(rear==MAX-1)
				printf("\nQueue is full\n");
				else
				{
					if(front==-1)
					front=0;
					printf("\nEnter element to insert: ");
					scanf("%d",&ele);
					rear++;
					q[rear]=ele;
				}
				break;
			case 2: if(front>rear||front==-1)
				{
					printf("\nQueue is empty\n");
					rear=front=-1;
				}
				else
				{
					ele=q[front];
					front++;
					printf("\n%d is deleted\n",ele);
				}
				break;
			case 3: if(front>rear||front==-1)
				{
					printf("\nQueue is empty\n");
					rear=front=-1;
				}
				else
				{
					printf("\nQueue\tRear");
					for(i=front;i<=rear;i++)
					{
						printf("\n------\n");
						printf("| %d |\t %d",q[i],i);
					}
					printf("\n------");
				}
				break;
			case 4: exit (0);
		}
	}
}