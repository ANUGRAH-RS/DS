#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
void main()
{
struct node*sp=(struct node*)0; //empty stack
struct node*push(struct node*,int);
struct node*pop(struct node*,int *);
int search(struct node*,int); 
int option,item,ans;
do
{
printf("1.PUSH\n");
printf("2.POP\n");
printf("3.SEARCH\n");
printf("4.EXIT\n");
printf("option:");
scanf("%d",&option);
switch(option)
{
case 1:printf("Enter Your Data :");
       scanf("%d",&item);
       sp=push(sp,item);
       break;
case 2:if(sp==(struct node*)0)
	printf("Empty Stack \n");
	else
	{
	sp=pop(sp,&item);
       printf("popped item=%d\n",item);
       }
       break;
case 3:printf("Search The Data :");     
       scanf("%d",&item);
       ans=search(sp,item);
       if(ans!=0)
          printf("Found\n");
       else
          printf("Not Found \n");
       break;
case 4:exit(0);
}
}
while(1);
}
//Function to push an itemin
//linked stack
struct node*push(struct node*sp,int data)     
{
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->data=data;
t->next=sp;
return t;
}
//Function to pop an element
struct node*pop(struct node*sp,int *data)
{
struct node*t=sp;
if(sp!=(struct node*)0)
{
*data=sp->data;										
sp=sp->next;
free(t);
}
return sp;
}
//Function to search an item
int search(struct node*sp,int item)
{
while(sp!=(struct node*)0 && sp->data!=item)
sp=sp->next;
if(sp==(struct node*)0)
return 0;
else
return 1;
}

