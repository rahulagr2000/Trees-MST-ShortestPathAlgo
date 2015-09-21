//QUICK SORT
#include<stdio.h>
int part(int a[],int low,int high)
{
    int i,j,temp,key;
    key=a[low];
    i=low+1;
    j=high;
    while(1)
    {
            while(i<high && key>=a[i])  i++;
            while(key<a[j])             j--;
            
            if(i<j)
            {
                   temp=a[i];
                   a[i]=a[j];
                   a[j]=temp;
            }
            
            else
            {
                   temp=a[low];
                   a[low]=a[j];
                   a[j]=temp;
                   return j;
            }
    }
}
void sort(int a[],int low, int high)
{
     int j;

     if(low<high)
     {
                 j=part(a,low,high);
                 sort(a,low,j-1);
                 sort(a,j+1,high);
     }
}

main()
{
    int i,n,a[20];

    printf("enter no. of elements\n");
    scanf("%d",&n);

    printf("enter the no. to be sorted\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    sort(a,0,n-1);

    printf("the sorted array is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    getch();
}


