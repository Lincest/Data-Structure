#include<bits/stdc++.h>
using namespace std;


int main(){
	char s;
	stack<char> st;
	int flag=0;
	while(scanf("%c",&s)&&s!='&'){
		if(s=='@'){
			flag=1;
			break;
		}
		st.push(s);
	}
	while(scanf("%c",&s)&&s!='@'&&flag==0){
		if(st.empty())
		{
			flag=1;
			break;
		}	
		if(st.top()==s)
			st.pop();	
	}
	if(flag==0)printf("true");
	else
		printf("false");
	return 0;
}
