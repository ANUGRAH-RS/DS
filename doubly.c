//doubly linked list operations
#include <stdio.h>
#include <stdlib.h>
struct node 
{
int data;
struct node *left,*right;
};
void main()
{
struct node*insert(struct node*,int);
struct node*delete(struct node*,int);
struct node*search(struct node*,int);
int option,data;
struct node*dl=(struct node*)0,*ans;
do
{
printf("\n1.Insert \n");
printf("\n2.Delete \n");
printf("\n3.Search \n");
printf("\n4.Exit \n");
printf("\n option :");
scanf("%d",&option); 
switch(option)
{
case 1:printf("Enter The Data :");
      scanf("%d",&data);
      dl=insert(dl,data);
      break;
case 2:printf("Deleting Item Is:");
      scanf("%d",&data);
      dl=delete(dl,data);
      break;
case 3:printf("Search Item :");
      scanf("%d",&data);
      ans=search(dl,data);
      if(ans==(struct node*)0)
      printf("Not Found");
      else
      printf("Found");
      break;
case 4:exit(0);
}
}
while(1);
}
//Function to insert an item in doubly linked list
struct node* insert(struct node *dl,int item)
{
struct node*t;
t=(struct node *)malloc(sizeof(struct node));
t->data=item;
t->left=(struct node *)0;
t->right=dl;
if(dl!=(struct node *)0)
dl->left=t;
return t;
}
//Function to search an item in a doubly linked list  
struct node* search(struct node*dl,int item)
{
while(dl!=(struct node*)0 && dl->data!=item)
dl=dl->right;
return dl;
}
//Function to delete an item in doubly linked list
struct node *delete(struct node *dl,int item)
{
struct node*t;
t=search(dl,item);
if(t==(struct node*)0)
printf("Not Found \n");
else
{
	if(t->left==(struct node*)0 && (t->right==(struct node*)0)) 
	dl=(struct node*)0;
	else if(t->left==(struct node*)0) //first node removal
	{
	t->right->left=t->left;
	dl=dl->right;
	}
	else if(t->right==(struct node*)0) //last node removal
	t->left->right=t->right;
	else //removal of interior node
	{
	t->left->right=t->right;
	t->right->left=t->left;
	}
	free(t);
	printf("%d is deleted ",item);
}
return dl;
}
