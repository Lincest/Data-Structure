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

int kmp(string s,string t,int pos){//�����ִ�T������S�е�pos���ַ�֮���λ�ã����������򷵻�0 
	int i=pos;	
	int j=0;//T�еĵ�ǰλ���±�
	int next[255];
	get_next(t,next);
	while(i<=s.size()&&j<=t.size()){
		if(j==0||s[i]==t[j]){
			//��������ĸ���ʱ����
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
