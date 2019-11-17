#include<bits/stdc++.h>
using namespace std;
#define MAXVEX 100
#define INFINITY 65535

typedef struct{
	char vexs[MAXVEX];// �����
	int matrix[MAXVEX][MAXVEX];
	int numVertexes,numEdges;//������������ 
}Graph;	//ͼ���ڽӾ���

typedef int Pathmatrix[MAXVEX];	//P�����洢·���±�,P[v]��ʾv��ǰ������ 
typedef int ShortPathTable[MAXVEX];	//D�����洢v0��v��·������,D[v]��ʾv0-v��·������ 


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
		v1-=1;v2-=1;	//һ������ 
		G.matrix[v1][v2]=weight;
		G.matrix[v2][v1]=weight;	//����ͼ 
	}
	
}



void shortest_path_dijkstra(Graph G,int v0,Pathmatrix &P,ShortPathTable &D)
{
	int v,w,k,m,min;
	int final[MAXVEX];	//final[w]=1��ʾv0��vw�����·���Ѿ�ȷ��
	for(v=0;v<G.numVertexes;++v){
		final[v]=0;	//��ʼ����Ϊδ֪״̬ 
		D[v]=G.matrix[v0][v];	//����v0�������ߵĶ������Ȩֵ 
		P[v]=0;
	} 
	D[v0]=0;	//v0���Լ���·�����ȿ϶�Ϊ0 
	final[v0]=1;	//ȷ����v0
	for(v=1;v<G.numVertexes;++v){	//һ��numVertex-1�����㣬ÿ�δ�ѭ�����ҵ�һ������ 
		min=INFINITY;
		for(w=0;w<G.numVertexes;++w){	//��һ��ѭ������Ѱ�ҵ�ǰδȷ����С·������v0�����һ������k
			if(!final[w]&&D[w]<min){
				k=w;
				min=D[w];
			}
		}
	final[k]=1;//�ҵ���k 
	for(w=0;w<G.numVertexes;++w){	//��ѭ��һ�����ж��㣬����v0������w����Сֵ,��Ϊÿ�μ���һ��k������һ����ת���㣬������Ҫ������ȷ��һ�� 
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

