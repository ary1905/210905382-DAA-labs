#include<stdio.h>
#include<stdlib.h>

int g[20][20];
int V;
int visited[20];
int stack[20], top=-1;
int seq[20], c=0;

void push(int v){
    stack[++top] = v;
}

int pop(){
    if(top==-1)
        return -1;
    return stack[top--];
}

void dfsv(int v){
    seq[c++]=v;
    visited[v] = 1;
    push(v);
    printf("Push %d\n",v);
    int i;
    for(i = 0; i < V; ++i){
        if(!visited[i] && g[v][i])
            dfsv(i);
    }
    printf("Pop %d\n",pop());
}

void dfs(){
    int i;
    for(i = 0; i < V; ++i){
        if(!visited[i])
              dfsv(i);
      }
}

void main(){
    printf("Enter the Number of Vertices : \n");
    scanf(" %d", &V);
    int i, j;
    printf("Enter the Adjacency Matrix: \n");
    for (i = 0; i < V; ++i){
        for (j = 0; j < V; ++j)
            scanf(" %d", &g[i][j]);
    }
    printf("\n");
    dfs();
    printf("\n--Sequence--\n");
    for(int i=0;i<V;i++)
        printf("%d\t",seq[i]);
    printf("\n");
}
