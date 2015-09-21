LINEAR SEARCH


#include<stdio.h>
main()
{
int i,j=0,m,n,a[20];
printf("linear search....\n");
printf("size of array...\n");
scanf("%d",&m);
printf("enter the nos....\n");
for(i=0;i<m;i++)
scanf("%d",&a[i]);
printf("enter d element 2 b searchd...\n");
scanf("%d",&n);
for(i=0;i<m;i++)
{
if(a[i]==n)
{
j++;
printf("found...\n");
break;
}
}
if(j==0)
printf("not found....\n");
}



