#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<stdio.h>
using namespace std;


int main(){
	stack<char> s;
	queue<char> t;
	stack<char> rt;
	string st="B(ehnxgz)B";
	string Bt="tAdA";
	string A="sae";
	string B;
	for(int j=0;j<Bt.size();++j){
		if(Bt[j]!='A')
			B+=Bt[j];
		else
			B+=A;
	}
	
	int flag=0;			
	for(int i=st.size()-1;i>=0;--i)
	{
		s.push(st[i]);
		if(s.top()=='('){
			s.pop();
			char e=s.top();
			s.pop();
			while(s.top()!=')')
			{
				t.push(e);
				t.push(s.top());
				s.pop();
			}
			t.push(e);
			s.pop();
		}
		while(!t.empty())
		{
			s.push(t.front());
			t.pop();
		}
	}	
	while(!s.empty()){
		if(s.top()!='B')
		{
			cout<<s.top();
			s.pop();
		}
		else{
			cout<<B;
		s.pop();
		}	
	}

	return 0;
		
}
			


