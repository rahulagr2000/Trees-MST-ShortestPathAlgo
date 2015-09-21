//MERGE SORT

#include<stdio.h>
const int MAX=100;

void sort(int a[], int low, int mid, int high)
{
     int i=low;
     int j=mid+1;
     int k=low;
     int c[MAX];

     while(i<=mid && j<=high)
     {
                  if(a[i]<a[j])
                  {
                               c[k]=a[i];
                               i=i+1;
                               k=k+1;
                   }
                   else
                   {
                            c[k]=a[j];
                               j=j+1;
                               k=k+1;
                   }
     }
     while(i<=mid)
     c[k++]=a[i++];

     while(j<=high)
     c[k++]=a[j++];

     for(i=low;i<=high;i++)
     a[i]=c[i];
}

void merge(int a[],int low,int high)
{
     int mid;
     if(low<high)
     {
                 mid=(low+high)/2;
                 merge(a,low,mid);
                 merge(a,mid+1,high);
                 sort(a,low,mid,high);
     }
}

main()
{
    int a[MAX],n,i;
    printf("enter the no. of elements\n");
    scanf("%d",&n);

    printf("enter the elements to be sorted\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    merge(a,0,n-1);

    printf("the sorted array is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    getch();
}



