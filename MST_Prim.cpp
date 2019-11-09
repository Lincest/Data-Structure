#include<bits/stdc++.h>
using namespace std;

int Graph[35][35];
int N,M;	//N是边数，M是结点数 


void InitGraph(){
	cout<<"请输入边的个数: "<<endl;
	cin>>N;
	cout<<"请输入边的起点，终点和权值: "<<endl;
	int begin,end,weight;
	for(int i=1;i<=N;++i){
		cin>>begin>>end>>weight;
		Graph[begin][begin]=0;
		Graph[end][end]=0;
		Graph[begin][end]=weight;
		Graph[end][begin]=weight;
		if(begin>M)M=begin;
		else if(end>M)M=end;//求最大的结点值 
	} 
}

void PrintGraph(){
	int i,j;
	for(int i=1;i<=M;++i)
		for(int j=i;j<=M;++j)
		{
			printf("%d %d %d\n",i,j,Graph[i][j]);
		}
}
/*
data:
1 2 4
1 3 3
2 3 5
2 4 5
3 4 5
2 5 9
3 8 5
4 8 4
5 4 7
5 6 3
4 6 6
4 7 5
6 7 2
7 8 6 
total N = 14
*/

void Prim(){
	int lowcost[35],adjvex[35];
	lowcost[1]=0;	//lowcost值为0表示改下标的顶点已经加入生成树
	adjvex[1]=0;	//adjvex[i]=j表示如果lowcost[i]所对应的边的顶点,比如<1,2>=5那么lowcost[2]=5,adjvex[2]=1 
	int min;
	for(int i=2;i<=M;++i){
		lowcost[i]=Graph[1][i];
		adjvex[i]=1;
	} 
	for(int i=2;i<=M;++i){
		min=9999;
		int j=2,k=1;
		while(j<=M){	//循环所有的顶点 
			if(lowcost[j]!=0&&lowcost[j]<min){
				min=lowcost[j];
				k=j;
			}
			j++;
		}
		printf("%d %d\n",adjvex[k],k);
		lowcost[k]=0;
		for(int j=2;j<=M;j++){
			if(lowcost[j]!=0&&Graph[k][j]<lowcost[j])
			{
				adjvex[j]=k;
				lowcost[j]=Graph[k][j];
			}
		}
	}
}

	
int main(){
	for(int i=0;i<35;++i)
		for(int j=0;j<35;++j)
			Graph[i][j]=99999;
	InitGraph();
	printf("Print: \n");
	PrintGraph();
	printf("Prim结果:\n");
	Prim();
	return 0;
}
