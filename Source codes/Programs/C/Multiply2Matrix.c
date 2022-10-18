#include<stdio.h>
int main ()
{ 
int matrices[10][10],transpose[10][10];
int i,j,rows,columns;


printf("ENTER THE VALUE OF ROWS AND COLUMNS : \n");
scanf("%d %d",&rows,&columns);
	
	
printf("ENTER THE ELEMENTS OF THE MATRICS : \n");
for(i=0;i<rows;i++)
for(j=0;j<columns;j++)
scanf ("%d",&matrices[i][j]);
  

printf("TRANSPOSE OF THE MATRICES : \n");
for (i=0;i<columns;i++)
{
for (j=0;j<rows;j++)
{
	transpose[j][i]=matrices[i][j];
printf("% d \t",transpose[i][j]);
if(j==rows-1)

printf("\n");
}
}
return 0;
}
