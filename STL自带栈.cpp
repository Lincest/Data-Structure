#include<bits/stdc++.h>
using namespace std;

stack<int> s;


int main(){
	int k;
	printf("whether the stack is empty: %d\n",s.empty());
	for(int i=1;i<=5;++i){
		cin>>k;
		s.push(k);
	}
	printf("now push every element out of stack: ");
	while(!s.empty()){	
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
	
} 
