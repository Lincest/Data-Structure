#include<bits/stdc++.h>
using namespace std;
int next[100];
int nextval[100];
void get_next(string T,int *next)	//求next 
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

void get_nextval(string T,int *nextval){ //求nextval 
    nextval[0]=-1;
    for(int i=1;i<T.size();++i)
    {
        if(T[next[i]]==T[i])
        {
            nextval[i]=nextval[next[i]];
        }
        else
            nextval[i]=next[i];
    }
}

int main(){
	string t="abcaabbabcabaacbacba";
	get_next(t,next);
	for(int i=0;i<t.size();++i)
	{
		cout<<next[i]+1<<" ";	//+1后输出 
	}
	cout<<endl;
	get_nextval(t,nextval);
	for(int i=0;i<t.size();++i)
	{
		cout<<nextval[i]+1<<" ";	//+1后输出 
	}
}
