#include<stdio.h>
#include<conio.h>
#define MAX 5
int cq[MAX],rear,front,i,ele,counter;
void cqinit()
{
	front=rear=-1;
	counter=0;
}
void cqinsert()
{
	if(counter==MAX)
	printf("\nCircular queue is full\n");
	else
	{
		if(front==-1)
		front=0;
		printf("\nEnter element to insert:");
		scanf("%d",&ele);
		rear=(rear+1)%MAX;
		cq[rear]=ele;
		counter++;
	}
}
void cqdel()
{
	if(counter==0)
	printf("\nCircular queue is empty\n");
	else
	{
		ele=cq[front];
		front=(front+1)%MAX;
		printf("\n%d is deleted\n",ele);
		counter--;
		/*if(front==rear)
		front=rear=-1;*/
	}
}
void display()
{
	if(counter==0)
	printf("\nCircular queue is empty\n");
	else
	{
		printf("\n--------------------------\n");
		for(i=front;i!=rear;i=(i+1)%MAX)
		{
			printf("| %d ",cq[i]);
		}
		printf("| %d |",cq[i]);
		printf("\n--------------------------\n");
	}
}
void main()
{
	int ch;
	clrscr();
	cqinit();
	while(1)
	{
		printf("\n1 : CQinsert\t\t2 : CQdel\t3 : CQdisplay\t\t4 : Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:cqinsert(); break;
			case 2:cqdel(); break;
			case 3:display(); break;
			case 4:exit(0);
		}
	}
}