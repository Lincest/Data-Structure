#include<bits/stdc++.h>
using namespace std;

void get_next(string T,int *next)
{
	int i=0,j=-1;
	next[0]=-1;
	while(i<T.size()){
		if(j==-1||T[i]==T[j])
		{
			i++;
			j++;
			next[i]=j;
		} 
		else
			j=next[j];                                       
	}
}

int kmp(string s,string t,int pos){//返回字串T在主串S中第pos个字符之后的位置，若不存在则返回0 
	int i=pos;	
	int j=0;//T中的当前位置下标
	int next[255];
	get_next(t,next);
	while(i<=s.size()&&j<=t.size()){
		if(j==0||s[i]==t[j]){
			//当两个字母相等时继续
			++i;
			++j; 
		}
		else{
			j=next[j];
		}
	}
	if(j>t.size())
		return i-t.size();
	else
		return 0;	
}


int main(){
	string s="ababababac";
	string t="abac";
	int k = kmp(s,t,0);
	cout<<k<<endl;
	return 0;
	 
}
