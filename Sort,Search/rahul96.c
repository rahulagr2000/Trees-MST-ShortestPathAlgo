//RADIX SORT


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node
{
       int info;
       struct node *link;
};
typedef struct node *NODE;

int separate(int item,int j)
{
    return item/(int)pow(10,j-1)%10;
}
int largest(int a[],int n)
{
    int i,big;
    big=a[0];

    for(i=1;i<n;i++)
    {
                    if(a[i]>big)
                    big=a[i];
    }
    return big;
}

NODE getnode()
{
     NODE x;
     x=(NODE)malloc(sizeof(struct node));
     return x;
}

NODE insert(int q,NODE w)
{
     NODE t,c;
     t=getnode();
     t->info=q;
     t->link=NULL;
     if(w==NULL)
         return t;
     c=w;
     while(c->link!=NULL)
                         c=c->link;
     c->link=t;

     return w;
}


void sort(int a[],int n)
{
     int i,j,k,m,big,digit,q;

     NODE p[10],t;
     big=largest(a,n);
     m=log10(big)+1;

     for(j=1;j<=m;j++)
     {
                      for(i=0;i<=9;i++)
                      p[i]=NULL;

                      for(i=0;i<n;i++)
                      {
                                      digit=separate(a[i],j);
                                      p[digit]=insert(a[i],p[digit]);
                      }
                      k=0;
                      for(i=0;i<=9;i++)
                      {
                                       t=p[i];
                                       while(t!=NULL)
                                       {
                                                     a[k++]=t->info;
                                                     t=t->link;

                    }
                      }
     }
}

main()
{
    int n,i,a[30];
    printf("enter no. of elements\n");
    scanf("%d",&n);

    printf("enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    sort(a,n);

    printf("the sorted araay is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}


