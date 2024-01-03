//circular queue operations
#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
int que[SIZE];
int front=0,rear=0;
void main()
{
void enqueue(int);
int dequeue();
int search(int);
int option,items,ans;
do
{
printf("\n 1.Insert \n");
printf("\n 2.Delete \n");
printf("\n 3.Search \n");
printf("\n 4.Exit \n");
printf("\n Option :");
scanf("%d",&option);
switch(option)
{
	case 1: printf(" Add items:");
        scanf("%d",&items);
        enqueue(items);
        break;
        
	case 2:if(front!=rear)
	{
	items=dequeue();
        printf("Deleted item is =%d\n",items);
        }
        else
        printf("Que is Empty ");
        break;
 
	case 3: printf("item to search :");
        scanf("%d",&items);
        ans=search(items);
        if(ans!=0)
        	{
        	printf("%d found at %d position \n",items,ans);
        	}
        else
        	{
        	printf("Item Not found\n");
        	}
        break;	
           
	case 4:exit(0);        
}
}
while(1);
}
//function to insert an item 
//in circular queue
void enqueue(int items)
{
int t;
t=(rear+1)%SIZE;
if(t==front)
	{
	printf("Queue Is Full");
	exit(1);
	}
else
	{
	rear=t;
	que[rear]=items;
	}
}

//function to delete an item
int dequeue()
{
if(front==rear)
	{
	  printf("Que Is Empty");
	  exit(2);
	}
	 
	front=(front+1)%SIZE;
	return que[front];
}
//function to search an item is queue
int search(int items)
{
int t1,t2;
t1=front,t2=rear;
t1=(t1+1)%SIZE;
while(t1!=t2 && que[t1]!=items)	
{
	t1=(t1+1)%SIZE;
}
if(front==rear)
{
printf("Queue Is Empty \n");
return 0;
}
else if(que[t1]==items)
	{
	return t1;
	}
	else
	return 0;
}

