#include<stdio.h>
#include<conio.h>
void insertion(int a[],int n);
void main()
{
	int a[10],i,n;
	clrscr();
	printf("Enter array size:\t");
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
	insertion(a,n);
	printf("\nSorted elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}
void insertion(int a[],int n)
{
	int i,j,s;
	for(i=1;i<n;i++)
	{
		s=a[i];
		for(j=i-1;j>=0 && s<a[j];j--)
		{
			if(s<a[j])
			{
				a[j+1]=a[j];
			}
		}
		a[j+1]=s;
	}
}