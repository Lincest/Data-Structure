#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VerStrLen 5
#define MaxVnum 50

typedef struct {//邻接矩阵
     int  **arcs;  
     char **vex; //顶点向量
     int  vexnum, arcnum;
}MGraph;

typedef struct ArcNode{ //表结点
     int    adjvex;
     int    weight;
     struct ArcNode *nextarc;
}ArcNode;
typedef struct Vnode{ //头结点
      char     *data;
      ArcNode  *firstarc;
}Vnode, *AdjList;  
typedef struct {//邻接表
      int      vexnum,arcnum;
      AdjList  vertices;
}ALGraph;  

bool visited[MaxVnum];

void Read_Graph1_MG(MGraph &MG);
void Mat_To_AdjList(MGraph MG,  ALGraph  &ALG);

void Read_Graph2_ALG(ALGraph &ALG);

void DFSTraverse_ALG(ALGraph G); 
void DFS_ALG(ALGraph G, int v); 
void BFSTraverse_ALG(ALGraph G); 

void DFSTraverse_MG(MGraph G); 
void DFS_MG(MGraph G, int v);  

int Locate_vex_ALG(ALGraph G, char *s);
int Exist_Path_DFS_ALG(ALGraph G, int i, int j);

void Free_ALG(ALGraph &G);
void Free_MG(MGraph &G);

void main()
{
	MGraph MG1;
	ALGraph ALG1, ALG2;
	int i, j, v;

	
	Read_Graph1_MG(MG1);
	Mat_To_AdjList(MG1, ALG1);

	//邻接表深度优先搜索
	printf("图1的邻接表深度优先搜索序列: ");
	DFSTraverse_ALG(ALG1);
	printf("\n");
	
	//邻接表广度优先遍历
	printf("图1的邻接表广度优先搜索序列: ");
	BFSTraverse_ALG(ALG1);
	printf("\n");

	//邻接矩阵深度优先遍历
	printf("图1的邻接矩阵深度优先搜索序列: ");
	DFSTraverse_MG(MG1);
	printf("\n");

	Read_Graph2_ALG(ALG2);

	printf("图2的邻接表深度优先搜索序列: ");
	DFSTraverse_ALG(ALG2);
	printf("\n");
	printf("图2的邻接表广度优先搜索序列: ");
	BFSTraverse_ALG(ALG2);
	printf("\n");

	i = Locate_vex_ALG(ALG2, "v6");
	j = Locate_vex_ALG(ALG2, "v1");
	if(i==-1 || j==-1){
		printf("图中无此顶点\n");
	}
	else{
		for(v=0; v<ALG2.vexnum; ++v) 
			visited[v] = false;
		if(Exist_Path_DFS_ALG(ALG2, i, j))
			printf("Existing a path from %s to %s\n", ALG2.vertices[i].data, ALG2.vertices[j].data);
		else
			printf("No path from %s to %s\n", ALG2.vertices[i].data, ALG2.vertices[j].data);
	}

	
	Free_MG(MG1);
	Free_ALG(ALG1);
	Free_ALG(ALG2);
	
}

void Read_Graph1_MG(MGraph &MG)
{
	FILE *tfile;
	int i,j;

	if((tfile = fopen("Graph1.txt","r"))==NULL) {
		printf("Could not open Graph.txt file\n");
		exit(0);
	}

	fscanf(tfile, "%d\n", &MG.vexnum);
	//构建邻接矩阵
	MG.arcnum = 0;
	MG.vex = (char **)malloc(MG.vexnum*sizeof(char *));
	for(i=0; i<MG.vexnum; i++){
		MG.vex[i] = (char *)malloc(VerStrLen*sizeof(char));
		fscanf(tfile, "%s", MG.vex[i]);
	}
	
	MG.arcs = (int **)malloc(MG.vexnum*sizeof(int *));
	for(i=0; i<MG.vexnum; i++){
		MG.arcs[i] = (int *)malloc(MG.vexnum*sizeof(int));
		for(j=0; j<MG.vexnum; j++){
			fscanf(tfile, "%d", &MG.arcs[i][j]);
			if(MG.arcs[i][j])
				MG.arcnum++;
		}
	}
	MG.arcnum /= 2;
	
	fclose(tfile);
}

void Mat_To_AdjList(MGraph MG,  ALGraph  &ALG)
{
	int i,j;
	ArcNode *p;

	//构建邻接表
	ALG.arcnum = MG.arcnum;
	ALG.vexnum = MG.vexnum;
	ALG.vertices = (AdjList)malloc(MG.vexnum*sizeof(Vnode));
	for(i=0; i<MG.vexnum; i++){
		ALG.vertices[i].data = (char *)malloc(VerStrLen*sizeof(char));
		strcpy(ALG.vertices[i].data, MG.vex[i]);
		ALG.vertices[i].firstarc = NULL;
	}
	for(i=0; i<MG.vexnum; i++){
		for(j=MG.vexnum-1; j>=0; j--)
			if(MG.arcs[i][j]!=0){
				p = (ArcNode *)malloc(sizeof(ArcNode)); 
				p->adjvex = j;
				p->weight = MG.arcs[i][j];
				p->nextarc = ALG.vertices[i].firstarc;
				ALG.vertices[i].firstarc = p;
			}
	}
}


void DFSTraverse_ALG(ALGraph G) 
{
	int v;
	
	for(v=0; v<G.vexnum; ++v) 
		visited[v] = false;
	for(v=0; v<G.vexnum; ++v) 
		if(visited[v]==false) 
			DFS_ALG(G, v);
}

void DFSTraverse_MG(MGraph G) 
{
	int v;
	
	for(v=0; v<G.vexnum; ++v) 
		visited[v] = false;
	for(v=0; v<G.vexnum; ++v) 
		if(visited[v]==false) 
			DFS_MG(G, v);
}

void DFS_ALG(ALGraph G, int v)  
{     
	ArcNode *p; 
	
	visited[v] = true; 
	printf("%s  ", G.vertices[v].data);
	//p = G.vertices[v].firstarc;
	//while (p != NULL){
	for(p=G.vertices[v].firstarc; p; p=p->nextarc){
		if(visited[p->adjvex]==false)
			DFS_ALG(G, p->adjvex); 
		//p = p->nextarc;   
	}
}

void DFS_MG(MGraph G, int v)  
{     
	int i; 
	
	visited[v] = true; 
	printf("%s  ", G.vex[v]);
	for(i=0; i<G.vexnum; i++){
		if(G.arcs[v][i] && !visited[i])
			DFS_MG(G, i);
	}
}

void BFSTraverse_ALG(ALGraph G)
{
	int v, u;
	int *Q;
	int front=0, rear=0;
	ArcNode *p; 
	
	for(v=0; v<G.vexnum; ++v) 
		visited[v] = false;
	Q = (int *)malloc(G.vexnum*sizeof(int));
	for(v=0; v<G.vexnum; ++v) 
		if(visited[v]==false){ 
			Q[rear++] = v;
			visited[v] = true;
			printf("%s  ", G.vertices[v].data);
			while(front != rear){
				u = Q[front++];
				//p = G.vertices[u].firstarc;
				//while (p != NULL){
				for(p=G.vertices[u].firstarc; p; p=p->nextarc){
					if(visited[p->adjvex]==false){
						Q[rear++] = p->adjvex;
						visited[p->adjvex] = true;
						printf("%s  ", G.vertices[p->adjvex].data);
					}
					//p = p->nextarc;
				}
			}
		}
	free(Q);
}

void Read_Graph2_ALG(ALGraph &ALG)
{
	FILE *tfile;
	int i,j,w;
	ArcNode *p, *tail; //AdjList p;

	if((tfile = fopen("Graph2.txt","r"))==NULL) {
		printf("Could not open Graph.txt file\n");
		exit(0);
	}

	fscanf(tfile, "%d\n", &ALG.vexnum);
	
	ALG.arcnum = 0;
	ALG.vertices = (AdjList)malloc(ALG.vexnum*sizeof(Vnode));
	for(i=0; i<ALG.vexnum; i++){
		ALG.vertices[i].data = (char *)malloc(VerStrLen*sizeof(char));
		fscanf(tfile, "%s", ALG.vertices[i].data);
		ALG.vertices[i].firstarc = NULL; 
	}

	while(!feof(tfile)){
		fscanf(tfile, "%d %d %d", &i, &j, &w);
		p = (ArcNode *)malloc(sizeof(ArcNode)); 
		p->adjvex = j-1;
		p->weight = w;
		p->nextarc = NULL;
		if(ALG.vertices[i-1].firstarc == NULL)
			ALG.vertices[i-1].firstarc = p;
		else
			tail->nextarc = p;
		tail = p;
		ALG.arcnum++;
	}
	fclose(tfile);
}

int Locate_vex_ALG(ALGraph G, char *s)
{
	int i;

	for(i=0; i<G.vexnum; i++){
		if(!strcmp(s, G.vertices[i].data))
			return i;
	}
	return -1;
}



int Exist_Path_DFS_ALG(ALGraph G, int i, int j)
{
	int k;
	ArcNode *p;

	if(i==j) 
		return 1;
	visited[i] = 1;
	for(p=G.vertices[i].firstarc; p; p=p->nextarc){
		k = p->adjvex;
		if(!visited[k])
			if(Exist_Path_DFS_ALG(G, k, j))
				return 1;
    }
	return 0;
}

void Free_ALG(ALGraph &G)
{
	int i;
	ArcNode *p, *q;	

	for(i=0; i<G.vexnum; i++){
		free(G.vertices[i].data);
		p = G.vertices[i].firstarc;
		while(p){
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	free(G.vertices);
	G.vertices = NULL;
}

void Free_MG(MGraph &G)
{
	int i;

	for(i=0; i<G.vexnum; i++){
		free(G.vex[i]);
		free(G.arcs[i]);
	}
	free(G.vex);
	free(G.arcs);
}

