#include<bits/stdc++.h>
using namespace std;

typedef struct{
	char begin;
	char end;
	int weight;
}Edge;

Edge edge[35];	//边集
int N; //边的条数
char parent[300];	//用于判断是否形成回路 


bool comp(Edge a,Edge b){
	return a.weight<b.weight;
}

void ScanEdge(){
	//输入带权边
	cout<<"请输入边的条数: "<<endl;
	cin>>N;
	cout<<"请输入边的起点，终点和权值: "<<endl;
	for(int i=1;i<=N;++i){
		cin>>edge[i].begin>>edge[i].end>>edge[i].weight;
	} 
	edge[N+1].weight=-1;
} 
/*
data:
a b 4
a c 3
b c 5
b d 5
c d 5
b e 9
c h 5
d h 4
e d 7
e f 3
d f 6
d g 5
f g 2
g h 6 
total N = 14
*/

void PrintEdge(){
	int i=1;
	while(edge[i].weight!=-1){
		cout<<edge[i].begin<<" "<<edge[i].end<<" "<<edge[i].weight<<endl;
		++i;
	}
}

char Find(char *parent,char f){
	while(parent[f]>0)
		f=parent[f];
	return f;
}

void Krustal(){	//输出最小生成树
	char n,m;
	for(int i=1;i<=N;++i){
	 	n = Find(parent,edge[i].begin);
	 	m = Find(parent,edge[i].end);
		if(n!=m){
			//m!=n说明选择该边后不会形成回路
			parent[n]=m;	//将m作为n的"parent"放入parent数组 
			cout<<edge[i].begin<<" "<<edge[i].end<<" "<<edge[i].weight<<endl;
		}
	}
	
}


int main(){
	ScanEdge();
	sort(edge+1,edge+N+1,comp);
	cout<<"排序后结果为:"<<endl;
	PrintEdge();
	cout<<"最小生成树为:"<<endl;
	Krustal();
}
