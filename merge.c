#include<stdio.h>
void main()
{
void readarray(int[],int);
void printarray(int[],int);
void sortarray(int[],int);
void merge(int[],int[],int[],int,int);
int ar1[100],ar2[100],ar3[100],m,n;
printf("No of elements on array [1-100] :");
scanf("%d",&m);
printf("Enter the elements of first array :\n");
readarray(ar1,m);
printf("No of elements of second array  :");
scanf("%d",&n);
printf("Enter the element of the second array :\n");
readarray(ar2,n);
printf("\n");
sortarray(ar1,m);
sortarray(ar2,n);
printarray(ar1,m);
printarray(ar2,n);
merge(ar1,ar2,ar3,m,n);
printf("Then merged array is :\n");
printarray(ar3,m+n);
}
//function to readarray
void readarray(int x[],int n)
{
int i;
for(i=0;i<n;i++)
scanf("%d",&x[i]);
}
//function to sortarray
void sortarray(int a[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
for(j=1+i;j<n;j++)
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
//function to printarray
void printarray(int x[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d\t",x[i]);
printf("\t");
printf("\n");
}
//function to mergearray
void merge(int ar1[],int ar2[],int ar3[],int m,int n)
{
int i,j,k;
i=j=k=0;
while((i<m)&&(j<n))
if(ar1[i]<ar2[j])
ar3[k++]=ar1[i++];
else
ar3[k++]=ar2[j++];
while(i<m)
ar3[k++]=ar1[i++];
while(j<n)
ar3[k++]=ar2[j++];
return;
}

