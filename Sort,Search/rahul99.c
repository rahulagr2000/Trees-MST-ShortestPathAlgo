BINARY SEARCH

#include<stdio.h>

main()
{
int i,j=0,m,n,a[20],h,no,l;
printf("enter the no of elements...\n");
	scanf("%d",&n);
printf("enter the elements...\n");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("enter d element 2 b searchd...\n");
	scanf("%d",&no);
l=0;
h=n-1;
while(l<=h)
{
	m=(l+h)/2;
	if(a[m]==no)
	{
		printf("found...\n");
		j++;
		break;
	}
	else if(no<a[m])
		h=m-1;
	else if(no>a[m])
		l=m+1;
}
if(j==0)
printf("not found....\n");
}


