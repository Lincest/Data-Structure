#include<bits/stdc++.h>
using namespace std;

typedef struct{
	char begin;
	char end;
	int weight;
}Edge;

Edge edge[35];	//�߼�
int N; //�ߵ�����
char parent[300];	//�����ж��Ƿ��γɻ�· 


bool comp(Edge a,Edge b){
	return a.weight<b.weight;
}

void ScanEdge(){
	//�����Ȩ��
	cout<<"������ߵ�����: "<<endl;
	cin>>N;
	cout<<"������ߵ���㣬�յ��Ȩֵ: "<<endl;
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

void Krustal(){	//�����С������
	char n,m;
	for(int i=1;i<=N;++i){
	 	n = Find(parent,edge[i].begin);
	 	m = Find(parent,edge[i].end);
		if(n!=m){
			//m!=n˵��ѡ��ñߺ󲻻��γɻ�·
			parent[n]=m;	//��m��Ϊn��"parent"����parent���� 
			cout<<edge[i].begin<<" "<<edge[i].end<<" "<<edge[i].weight<<endl;
		}
	}
	
}


int main(){
	ScanEdge();
	sort(edge+1,edge+N+1,comp);
	cout<<"�������Ϊ:"<<endl;
	PrintEdge();
	cout<<"��С������Ϊ:"<<endl;
	Krustal();
}
