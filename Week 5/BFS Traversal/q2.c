#include <stdio.h>
#include <stdlib.h>

int g[100][100];
int V;
int visited[100];
int seq[100];
int queue[100], f = 0, r = 0, c = 0;

void enqueue(int v)
{
	queue[r++] = v;
}

int dequeue()
{
	if(f == r)
	{
		return -1;
	}
	
	return queue[f++];
}

void bfsv(int v)
{
    seq[c++] = v;
    visited[v] = 1;
	
	int i;
	
	for(i = 0; i < V; ++i)
	{
		if(!visited[i] && g[v][i])
		{
			enqueue(i);
            printf("Enqueue: %d\n", i);
        }
    }
}

void bfs()
{
	int i, x;
	enqueue(0);
	printf("Enqueue: 0\n");
	do
	{
		x = dequeue();
		
		if(x != -1 && !visited[x])
		{
            printf("Dequeue: %d\n", x);
			bfsv(x);
		}
	}while (x != -1);
}

int main()
{
	printf("Enter the Number of Vertices : \n");
	scanf(" %d", &V);
	
	int i, j;
	
	printf("Enter the Adjacency Matrix: \n");
	
	for (i = 0; i < V; ++i)
	{
		for (j = 0; j < V; ++j)
		{
			scanf(" %d", &g[i][j]);
		}
	}	
	
	bfs();

    printf("\n--Sequence--\n");
    for(int i=0;i<V;i++)
        printf("%d\t",seq[i]);
    printf("\n");
	return 0;
}