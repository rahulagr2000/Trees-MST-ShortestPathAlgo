//INSERTION SORT

#include<stdio.h>

void sort(int n,int a[])
{
     int i,j,item;

     for(i=1;i<n;i++)
     {
                        item=a[i];
                        j=i-1;
                        while(item<a[j] && j>=0)
                        {
                                              a[j+1]=a[j];
                                              j--;
                        }
                        a[j+1]=item;
     }
}

main()
{
    int i,j,n,a[20];
    printf("enter no. of elements\n");
    scanf("%d",&n);

    printf("enter the elements to be sorted\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    sort(n,a);

    printf("the sorted array is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    getch();
}


