#include<bits/stdc++.h>
using namespace std;

#define MAXSIZE 10005

typedef struct{
	int data[MAXSIZE];
	int top;	//top指向最顶部元素 
}Stack;

bool InitStack(Stack &s){
	s.top=-1;
}

bool StackEmpty(Stack &s){
	return s.top==-1;
}

bool push(Stack &s,int e){
	s.top++;
	s.data[s.top]=e;
}

bool pop(Stack &s,int &e){
	e=s.data[s.top];
	s.top--;
}



int main(){
	Stack s;
	InitStack(s);
	int k;
	printf("whether the stack is empty: %d\n",StackEmpty(s));
	for(int i=1;i<=5;++i){
		cin>>k;
		push(s,k);
	}
	printf("now push every element out of stack: ");
	while(!StackEmpty(s)){
		if(pop(s,k))
			cout<<k<<" ";
	}
	return 0;
	
} 
