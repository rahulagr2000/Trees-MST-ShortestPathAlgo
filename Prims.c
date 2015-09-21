// PRIM'S MST ALGO
// Rahul Agrawal , 20 Sep 2012

# include <stdio.h>
int data[100];
int graph[100][100];
int tree[100][100];
int n;
int i;
int x,y;
int included[100] = {0};
int visited[100] = {0};

void resetVisited()
{
  int i;
  for(i=0;i<100;i++)
  visited[i] = 0;
}

void initialize()
{
  int i,j;
  for(i=0;i<100;i++)
    for(j=0;j<100;j++)
    tree[i][j] = graph[i][j] = 0;
}

void resetTree()
{
  int i,j;
  for(i=0;i<100;i++)
    for(j=0;j<100;j++)
{
included[j]= 0;
tree[i][j] = 0;
}
}


int search(int data1)
{
  int i = 0;
  for(i=0;i<n;i++)
    if(data1==data[i])
    return i;
  return -1;
}

int min(int a, int b)
{
  if(a<b) return a;
  else return b;
}
void clearScreen();

void markGraph(int data1, int data2,int w)
{
  int i,j;
  i = search(data1);
  j = search(data2);
  if(i!=-1 && j!=-1)
    graph[i][j] = w;
  else
  printf("\nRequired Elements not found\n");
}

void getVertices(int k)
{
  int i;
  n=k;
  printf("\nEnter Data :\n");
  for(i=0;i<n;i++)
    scanf("\n%d",&data[i]);
}

void getConnection(int k)
{
  int inp,index,w;
  printf("\nPlease Enter All Vertices adjacent to %d ,       followed by weight of path(-1 to end) : \n",data[k]);
while(1)
{
  scanf("\n%d",&inp);
  if(inp == -1) break;
  scanf("\n%d",&w);
  if(inp!=-1)
{
index =search(inp);
if(index<n && index!=k && index>=0)
  markGraph(data[k],inp,w);
else
  printf("Data not found");
}
else break;
}
}

void clearScreen()
{
  return;
}
void getAllConnections()
{
  int i;
  for(i=0;i<n;i++)
  {
    clearScreen();
    //displayData();
    getConnection(i);
}
}

void getInput()
{
  int n;
  printf("Please Enter the no. of Vertices : ");
  scanf("\n%d",&n);
  getVertices(n);
  getAllConnections();
}

void displayGraph()
{
  int i,j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%d",graph[i][j]);
    printf("\n");
  } 
}

void getMWnode()
{
  int i,j;
  x = y = -1;
  int minimum=9999;
  for(i=0;i<n;i++)
  {
	for(j=0;j<n;j++)
		{
		  if(graph[i][j]!=0)
		  {
		    if(graph[i][j] < minimum)
		    {
		      x = i;
		      y = j;
		      minimum = graph[i][j];
		    }
		  }
		}
	}

	if(minimum == 9999)
	x = y = -1;
}

int pathExist(int a, int b)
{
  int i;
  int found;
  visited[a] = 1;
  for(i=0;i<n;i++)
  {
    if(graph[a][i] == 1 && visited[i] == 0)
    {
      if(i == b) return 1;
      found = pathExist(i, b);
      if(found == 1) return found;
    }
  }
return 0;
}

}
int vertexRemain()
{
  int i;
  for(i=0;i<n;i++)
  {
     if(included[i] == 0) return 1;
  }
return 0;
}

void getMWconnectednode()
{
  int i,j;
  x=y=-1;
  int minimum = 9999;
  for(i=0;i<n;i++)
  {
	if(included[i] == 1)
	{
		for(j=0;j<n;j++)
		{
			if(graph[i][j] != 0)
			{
				if(graph[i][j]<minimum && included[j]!=1)
				{
				x = i;
				y = j;
				minimum = graph[i][j];
				}
			}
		}
	}
}
if(minimum == 9999)
x = y = -1;
return;
}


void Prims()
{
  resetTree();
  included[0] = 1;
  while(vertexRemain())
  {
      getMWconnectednode();
      if(x==-1)
      return;
      tree[x][y] = 1;
      included[x] = included[y] = 1;
  }
}

void displayTree()
{
  int i,j;
  printf("\nAdjacency Matrix for Spanning Tree : ");
  for(i=0;i<n;i++)
	{
	  printf("\n");
	  for(j=0;j<n;j++)
	    printf("%d ",tree[i][j]);
	}
}

void main()
{
  initialize();
  getInput();
  printf("\nBy Prims Algorithm ");
  Prims();
  displayTree();
  getch();

}







