//HEAP SORT
#include<stdio.h>

void heap(int a[],int n)
{
     int i,j,k,item;
     for(k=1;k<n;k++)
     {
                     item=a[k];
                     i=k;
                     j=(i-1)/2;   //parent of i

                     while(i>0 && item>a[j])
                     {
                               a[i]=a[j];
                               i=j;
                               j=(i-1)/2;
                     }
                     a[i]=item;
     }
}

void adjust(int a[],int n)
{
     int i,j,item;
     j=0;   //parent
     item=a[j];
     i=2*j+1;   //child

     while(i<=n-1)
     {
                  if(i+1<=n-1)
                  {
                              if(a[i]<a[i+1])
                              i++;
                  }
                  if(item<a[i])
                  {
                               a[j]=a[i];
                               j=i;
                               i=2*j+1;
                  }
                  else
     break;
     }
     a[j]=item;
}

void sort(int a[],int n)
{
     int i,t;
     heap(a,n);
     for(i=n-1;i>0;i--)
     {
                       t=a[0];
                       a[0]=a[i];
                       a[i]=t;

                       adjust(a,i);
     }
}

main()
{
    int a[40],n,temp,i;

    printf("enter no. of elements\n");
    scanf("%d",&n);

    printf("enter the elements to be sorted\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    sort(a,n);

    printf("the sorted array is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}



