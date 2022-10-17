#include<stdio.h>
#include<conio.h>
void selection(int a[],int n);
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
	selection(a,n);
	printf("\nSorted elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}
void selection(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		(
			if(a[k]>a[j])
			k=j;
		)
		if(i!=k)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
}