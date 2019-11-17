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
	cout<<"�������Ŀ:";cin>>N;
	G.numEdges=N;
	cout<<"���붥����Ŀ:";cin>>M;
	G.numVertexes=M;
	cout<<"�����,Ȩֵ:"<<endl;
	for(int i=0;i<M;++i)
		for(int j=0;j<M;++j)
		{
			G.matrix[i][j]=INFINITY;	
		}
	for(int i=0;i<N;++i){
		cin>>v1>>v2>>weight;
		G.matrix[v1][v2]=weight;
		G.matrix[v2][v1]=weight;	//����ͼ 
	}
	cout<<"����ͼ�ɹ�"<<endl;
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
	} 
	final[k]=1;//�ҵ���k 
	for(w=0;w<G.numVertexes;++w){	//��ѭ��һ�����ж��㣬����v0������w����Сֵ,��Ϊÿ�μ���һ��k������һ����ת���㣬������Ҫ������ȷ��һ�� 
		if(!final[w]&&(min+G.matrix[k][w]<D[w])){
			D[w]=min+G.matrix[k][w];
			P[w]=k;
		}
	}
}


int main(){
	Graph G;
	CreateGraph(G);
	Pathmatrix P;
	ShortPathTable D;
	shortest_path_dijkstra(G,0,P,D);
	for(int i=0;i<G.numVertexes;++i){
		cout<<P[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<G.numVertexes;++i){
		cout<<D[i]<<" ";
	}
	return 0;
}

/*
0 1 1
0 2 5
0 3 3
1 2 1
1 3 4
2 3 2
*/

