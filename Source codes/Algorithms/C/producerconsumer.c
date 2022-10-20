#include<stdio.h>
#include<stdlib.h>
 
int mutex=1,fill=0,empty=3,x=0;
 
int main()
{
int n;
void producer();
void consumer();
int wait(int);
int signal(int);

//print available options  & read choice
printf("\n1.Producer\n2.Consumer\n3.Exit");
while(1)
{
printf("\nEnter your choice:");
scanf("%d",&n);
//menu driven producer consumer
switch(n)
{

//case 1:mutex availability = true & empty space !=0  [PRODUCER]
case 1: if((mutex==1)&&(empty!=0))
producer();
else
printf("Buffer is full!!");
break;

//case 2:mutex availability = true & filled space !=0  [CONSUMER]
case 2: if((mutex==1)&&(fill!=0))
consumer();
else
printf("Buffer is empty!!");
break;

//case 3:exit and break
case 3:
exit(0);
break;
}
}
return 0;
}
 
// wait function decrements semaphore 
int wait(int s)
{
return (--s);
}
 
//signal function increments semaphore
int signal(int s)
{
return(++s);
}

// In producer function , -mutex , +fill , -empty , +mutex  (where wait perform decrement(-) & signal perform increment(+))
void producer()
{
mutex=wait(mutex);
fill=signal(fill);
empty=wait(empty);
x++;
printf("\nProducer produces the item %d",x);
mutex=signal(mutex);
}

// In consumer function , -mutex , -fill , +empty , +mutex  (where wait perform decrement(-) & signal perform increment(+))
void consumer()
{
mutex=wait(mutex);
fill=wait(fill);
empty=signal(empty);
printf("\nConsumer consumes item %d",x);
x--;
mutex=signal(mutex);
}
