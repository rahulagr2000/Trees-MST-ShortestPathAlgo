//SELECTION SORT


#include<stdio.h>
main()
{
 int a[10],n,i,j,temp,pos,min;
 printf("enter no of elements of an array");
 scanf("%d",&n);
 printf("enter elements of an array");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 for(i=0;i<n;i++)
 {
  min=a[i];
  pos=i;
   for(j=i+1;j<n;j++)
   {
    if(min>a[j])
    {
     min=a[j];
     pos=j;
    }
   }
  temp=a[i];
  a[i]=a[pos];
  a[pos]=temp;
 }
 printf("sorted array is \n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
getch();
}

