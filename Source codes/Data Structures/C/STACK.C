#include<stdio.h>
#include<conio.h>
#define SIZE 5
int i,top,s[SIZE],ele,ch;
void init()
{
	top=-1;
}
int isfull()
{
	if(top==SIZE-1)
	return 1;
	else
	return 0;
}
int isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void push(int x)
{
	if(isfull())
	printf("\nStack is full");
	else
	{
		printf("\nEnter element to insert:-");
		scanf("%d",&x);
		top++;
		s[top]=x;
	}
}
void pop()
{
	if(isempty())
	printf("\nStack is empty");
	else
	{
		ele=s[top];
		top--;
		printf("\n%d is pop",ele);
	}
}
void display()
{
	if(isempty())
	printf("\nStack is empty");
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("\n%d | %d |",i,s[i],"\n");
		}
	}
}
void main()
{
	clrscr();
	init();
	while(1)
	{
		printf("\n\n1: PUSH\n2: POP\n3: DISPLAY\n4: EXIt\nENTER YOUR CHOICE:-\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push(ele);
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
		}
	}
}
