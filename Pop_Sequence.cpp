#include<bits/stdc++.h>
using namespace std;

int main()
{
	int M,N,K;
	cin>>M>>N>>K; //M��ʾջ��������N��ʾ�������еĳ��ȣ�K��ʾһ������K������
	while(K--){
		stack<int> s;//����һ��ջ
		int min=1;//��1��ʼpushÿһ����ջ 
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
