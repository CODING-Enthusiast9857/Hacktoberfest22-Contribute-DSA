#include<stdio.h>
#include<conio.h>
void linear(int a[],int n,int s);
void main()
{
	int a[10],i,n,s;
	clrscr();
	printf("Enter array size:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Array elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nEnter element to search:\n");
	scanf("%d",&s);
	linear(a,n,s);
	getch();
}
void linear(int a[],int n,int s)
{
	int i,c=-1;
	for(i=0;i<n;i++)
	{
		if(a[i]==s)
		{
			c=i;
			break;
		}

	}
	if(c!=-1)
	printf("%d is found at %d position",s,c);
	else
	printf("%d is not found",s);
}