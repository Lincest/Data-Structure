#include<bits/stdc++.h>
using namespace std;

int main()
{
	int M,N,K;
	cin>>M>>N>>K; //M表示栈的容量，N表示输入序列的长度，K表示一共输入K个序列
	while(K--){
		stack<int> s;//创建一个栈
		int min=1;//从1开始push每一个入栈 
		int flag=1;
		for(int i=1;i<=N;++i){
			int c;cin>>c;
			while(c>=min&&s.size()<M){
				s.push(min);
				min++;
			}
			if(c==s.top()){
				s.pop();
			}
			else
				flag=0;
		}
		if(flag==0)cout<<"NO"<<endl;
		if(flag==1)cout<<"YES"<<endl; 
	} 
	return 0;
}
