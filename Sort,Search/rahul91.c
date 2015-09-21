//BUBBLE SORT

#include<stdio.h>
main()
{
 int a[5],n,i,j,temp;
 printf("enter no of elements of an array"); 
 scanf("%d",&n);
 printf("enter elements of an array");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);

 for(i=0;i<n;i++)
   for(j=0;j<n-i-1;j++)
     if(a[j]>a[j+1])
     {
       temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
     }
 
 printf("sorted array is \n");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);
 getch();
}
 
 


