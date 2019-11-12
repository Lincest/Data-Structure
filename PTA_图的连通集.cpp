#include<bits/stdc++.h>
using namespace std;
int graph[20][20];
int visit[20];
int N,E,temp;
void DFS(int n);
void BFS(int n);
queue<int> q;
int check();

int main(){
	cin>>N>>E;
	int m,n;
	for(int i=0;i<E;++i){
		cin>>m>>n;
		graph[m][n]=1;
		graph[n][m]=1;
	}
	cout<<"{ ";
	DFS(0);
	cout<<"}";
	while(check()!=999){
		cout<<endl;
		cout<<"{ ";
		DFS(check());
		cout<<"}";
	}
	memset(visit,0,sizeof(visit));
	cout<<endl;
	cout<<"{ ";
	BFS(0);
	cout<<"}";
	while(check()!=999){
		cout<<endl;
		cout<<"{ ";
		BFS(check());
		cout<<"}";
	}
}

void DFS(int n){
	if(!visit[n]){
		visit[n]=1;
		cout<<n<<" ";
		for(int i=0;i<N;++i){
			if(graph[n][i]==1){
				DFS(i);
			}
		}
	}
	return ;
}

void BFS(int n){
	if(!visit[n]){
		visit[n]=1;
		cout<<n<<" ";
		for(int i=0;i<N;++i){
			if(graph[n][i]==1)
				q.push(i);
			}
		while(!q.empty()){
			temp=q.front();
			q.pop();
			BFS(temp);		
			}
	}
	return ;
}
int check(){
	for(int i=0;i<N;++i){
			if(visit[i]==0)
				return i;
		}
	return 999;
	}
