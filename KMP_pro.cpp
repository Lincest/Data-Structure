#include<bits/stdc++.h>
using namespace std;
int next[100];
	
void get_next(string T,int *next)
{
	int i=0;int j=-1;
	next[0]=-1;
	while(i<T.size())
	{
		if(T[i]==T[j]||j==-1){
			i++;
			j++;
			next[i]=j;				
		}
		else
			j=next[j];	
	}
}

int main(){
	string t;
	cin>>t;
	get_next(t,next);
	for(int i=0;i<t.size();++i)
	{
		cout<<next[i]<<" ";
	}
}
