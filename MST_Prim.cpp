#include<bits/stdc++.h>
using namespace std;

int Graph[35][35];
int N,M;	//N�Ǳ�����M�ǽ���� 


void InitGraph(){
	cout<<"������ߵĸ���: "<<endl;
	cin>>N;
	cout<<"������ߵ���㣬�յ��Ȩֵ: "<<endl;
	int begin,end,weight;
	for(int i=1;i<=N;++i){
		cin>>begin>>end>>weight;
		Graph[begin][begin]=0;
		Graph[end][end]=0;
		Graph[begin][end]=weight;
		Graph[end][begin]=weight;
		if(begin>M)M=begin;
		else if(end>M)M=end;//�����Ľ��ֵ 
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
	lowcost[1]=0;	//lowcostֵΪ0��ʾ���±�Ķ����Ѿ�����������
	adjvex[1]=0;	//adjvex[i]=j��ʾ���lowcost[i]����Ӧ�ıߵĶ���,����<1,2>=5��ôlowcost[2]=5,adjvex[2]=1 
	int min;
	for(int i=2;i<=M;++i){
		lowcost[i]=Graph[1][i];
		adjvex[i]=1;
	} 
	for(int i=2;i<=M;++i){
		min=9999;
		int j=2,k=1;
		while(j<=M){	//ѭ�����еĶ��� 
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
	printf("Prim���:\n");
	Prim();
	return 0;
}
