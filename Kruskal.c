
// Kruskal's MST Algorithm
// Rahul Agrawal , 30 Aug 2012

# include<stdio.h>

int n;
int noe;
int e[100][4];

int tree[10][10];

int sets[100][10];
int top[100];

void read_graph();
void initialize_span_t();
void sort_edges();
void algorithm();
int find_node(int );
void print_min_span_t();


void read_graph()
{
	int i,j,w;
	printf("Enter the no. of nodes:");
	scanf("%d",&n);
	noe=0;
	printf("Enter the weights for the following edges ::\n");
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			printf("%d--%d",i,j);
			scanf("%d",&w);
			if(w!=0)
			{
				noe++;
				e[noe][1]=i;
				e[noe][2]=j;
				e[noe][3]=w;
			}
		}
	}

}

void sort_edges()
{
	int i,j,t;
	for(i=1;i<=noe-1;i++)
	{
		for(j=1;j<=noe-i;j++)
		{
			if(e[j][3]>e[j+1][3])
			{
				t=e[j][1];
				e[j][1]=e[j+1][1];
				e[j+1][1]=t;
				t=e[j][2];
				e[j][2]=e[j+1][2];
				e[j+1][2]=t;
				t=e[j][3];
				e[j][3]=e[j+1][3];
				e[j+1][3]=t;
			}
		}
	}

}

void algorithm()
{
	int i,j,p1,p2;
	for(i=1;i<=n;i++)
	{
		sets[i][1]=i;
		top[i]=1;
	}
	for(i=1;i<=noe;i++)
	{
		p1=find_node(e[i][1]);
		p2=find_node(e[i][2]);
		if(p1!=p2)
		{
			printf("The edge included in the tree is ::%d--%d\n",e[i][1],e[i][2]);
			tree[e[i][1]][e[i][2]]=e[i][3];
			tree[e[i][2]][e[i][1]]=e[i][3];
			for(j=1;j<=top[p2];j++)
			{
				top[p1]++;
				sets[p1][top[p1]]=sets[p2][j];
			}
			top[p2]=0;
		}
		else
		{
			printf("Inclusion of the edge %d--%d forms a cycle. so it is removed\n",e[i][1],e[i][2]);
		}
	}
}

int find_node(int n)
{
	int i,j;
	for(i=1;i<=noe;i++)
	{
		for(j=1;j<=top[i];j++)
		{
			if(n==sets[i][j])
			return i;
		}
	}
return -1;
}

int main()
{
	read_graph();
	sort_edges();
	algorithm();
	getch();
}

