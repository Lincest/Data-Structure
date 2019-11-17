#include<bits/stdc++.h>
using namespace std;
#define MAXVEX 100
#define INFINITY 65535

typedef struct{
	char vexs[MAXVEX];// 顶点表
	int matrix[MAXVEX][MAXVEX];
	int numVertexes,numEdges;//顶点数，边数 
}Graph;	//图的邻接矩阵

typedef int Pathmatrix[MAXVEX];	//P用来存储路径下标,P[v]表示v的前驱顶点 
typedef int ShortPathTable[MAXVEX];	//D用来存储v0到v的路径长度,D[v]表示v0-v的路径长度 


void CreateGraph(Graph &G){
	int N,M;
	int v1,v2,weight;
	cin>>M;
	G.numVertexes=M;
	cin>>N;
	G.numEdges=N;
	for(int i=0;i<M;++i)
		for(int j=0;j<M;++j)
		{
			G.matrix[i][j]=INFINITY;	
		}
	for(int i=0;i<N;++i){
		cin>>v1>>v2>>weight;
		v1-=1;v2-=1;	//一点点操作 
		G.matrix[v1][v2]=weight;
		G.matrix[v2][v1]=weight;	//无向图 
	}
	
}



void shortest_path_dijkstra(Graph G,int v0,Pathmatrix &P,ShortPathTable &D)
{
	int v,w,k,m,min;
	int final[MAXVEX];	//final[w]=1表示v0到vw的最短路径已经确定
	for(v=0;v<G.numVertexes;++v){
		final[v]=0;	//初始化均为未知状态 
		D[v]=G.matrix[v0][v];	//将和v0点有连线的顶点加上权值 
		P[v]=0;
	} 
	D[v0]=0;	//v0到自己的路径长度肯定为0 
	final[v0]=1;	//确定了v0
	for(v=1;v<G.numVertexes;++v){	//一共numVertex-1个顶点，每次大循环必找到一个顶点 
		min=INFINITY;
		for(w=0;w<G.numVertexes;++w){	//这一层循环用于寻找当前未确定最小路径的离v0最近的一个顶点k
			if(!final[w]&&D[w]<min){
				k=w;
				min=D[w];
			}
		}
	final[k]=1;//找到了k 
	for(w=0;w<G.numVertexes;++w){	//再循环一次所有顶点，更新v0到所有w的最小值,因为每次加入一个k将加入一个中转顶点，所以需要这样再确定一次 
		if(!final[w]&&(min+G.matrix[k][w]<D[w])){
			D[w]=min+G.matrix[k][w];
			P[w]=k;
		}
	}
}
}


int main(){
	Graph G;
	CreateGraph(G);
	Pathmatrix P;
	ShortPathTable D;
	int minD=0;
	int minAD=INFINITY,minAV=INFINITY;
	int minV=INFINITY;
	int flag=0;
	for(int i=0;i<G.numVertexes;++i){
		shortest_path_dijkstra(G,i,P,D);
		for(int j=0;j<G.numVertexes;++j){
				if(D[j]==INFINITY)
				flag=1;
				if(D[j]>minD){
					minD=D[j];
					minV=i+1;
				}
		}
		if(minD<minAD){
			minAD=minD;
			minAV=minV;
		}
		minD=0;
	}
	if(flag==0)
		cout<<minAV<<" "<<minAD;
	else if(flag==1)
		cout<<0;
	return 0;
}

/*
for(int j=0;j<G.numVertexes;++j){
			if(D[j]>minD){
				minD=D[j];
				minV=j+1;
			}
		}
		if(minD<minAD){
			minAD=minD;
			minAV=minV;
		}
	}
	cout<<minAV<<" "<<minAD<<endl;
*/

/*

	for(int j=0;j<G.numVertexes;++j){
		shortest_path_dijkstra(G,j,P,D);
		for(int i=0;i<G.numVertexes;++i){
			cout<<D[i]<<" ";
		}
		cout<<endl;
	}
*/

