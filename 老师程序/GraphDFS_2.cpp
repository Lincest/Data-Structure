#include <stdio.h>
#include <stdlib.h>

int G[100][100];
bool visited[100];

void DFS(int v, int vexnum)  
{     
	int i; 
	
	visited[v] = true;

	printf("%d ", v);

	for(i=0; i<vexnum; i++){
		if(G[v][i] && !visited[i])
			DFS(i, vexnum);
	}
}

void DFSTraverse(int vexnum) 
{
	int v,count;
	
	count = 0;
	for(v=0; v<vexnum; ++v) 
		visited[v] = false;
	for(v=0; v<vexnum; ++v){ 
		if(visited[v]==false){ 
			DFS(v, vexnum);
			count++;
		}
	}
	printf("\n%d\n", count);
}

void main()
{
	
	int i,j, vexnum;

	scanf("%d", &vexnum);
	for(i=0; i<vexnum; i++)
		for(j=0; j<vexnum; j++)
			scanf("%d", &G[i][j]);

	DFSTraverse(vexnum);
}