#include <stdio.h>
int main()
{
int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
int p, r, i, j, process, count;
count = 0;

// read no of processes(p0,p1,p2,p3)
printf("Enter the no of processes : ");
scanf("%d", &p);

//read no of resources (A,B,C,D)
printf("\n\nEnter the no of resources : ");
scanf("%d", &r);

//read alloc (for p processes and r resources)
printf("\n\nEnter the allocation for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ",i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &alloc[i][j]);	
}

//read max (for p processes and r resources)
printf("\n\nEnter the Max Matrix for each process : ");
for(i = 0; i < p; i++)
{
	printf("\nFor process %d : ", i + 1);
	for(j = 0; j < r; j++)
		scanf("%d", &Max[i][j]);
}

//read avail (for p processes and r resources)
printf("\n\nEnter the Available Resources : ");
for(i = 0; i < r; i++)
		scanf("%d", &avail[i]);	

//calc need (for p processes and r resources)
for(i = 0; i < p; i++)
	for(j = 0; j < r; j++)
		need[i][j] = Max[i][j] - alloc[i][j];

// set all completed proccesses as 0
for(i = 0; i< p; i++)
	completed[i] = 0;

// do while count !=process & process!=-1	
do
{
	// process no i will be assigned to 'process' variable .So initialized as -1
	process = -1;

	// for each process p , if completion of p is 0 ,set process to i
	for(i = 0; i < p; i++)
	{
		if(completed[i] == 0)
		{
			process = i ;

			//for each resource r , if need > avail (process not selected),set process -1
			for(j = 0; j < r; j++)
			{

				if(need[i][j] > avail[j])
				{
					process = -1;
					break;
				}
			}
		}
		// break loop if selected (process!=-1)
		if(process != -1)
			break;
	}

	// if selected 
	if(process != -1)
	{
		//print 'process +1 selected' (if p=3 ; i=0,1,2,3 ; if i = 2 selected ,3rd process is selected)
		printf("\nProcess %d runs to completion!", process + 1);

		// process stored to safe sequence matrix
		safeSequence[count] = process + 1;
		count++;

		//for each resource r , 
		for(j = 0; j < r; j++)
		{
			//new alloc = alloc +avail (not i but selected i which is 'process')
			avail[j] += alloc[process][j];
			// alloc & max = 0 ,completion of 'process' =1
 			alloc[process][j] = 0;
			Max[process][j] = 0;
			completed[process] = 1;
		}
	}
}while(count != p && process != -1);

// if all process selected ,ie count ==p
if(count == p)
{
	// print safe state
	printf("\nThe system is in a safe state!!\n");
	// print safe sequence [i]
	printf("Safe Sequence : < ");
	for( i = 0; i < p; i++)
		printf("%d  ", safeSequence[i]);
	printf(">\n");
}

// else print unsafe
else
	printf("\nThe system is in an unsafe state!!");
}