#include<bits/stdc++.h>
using namespace std;

typedef struct StackNode{
	int data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
	LinkStackPtr top;
	int count;
}LinkStack;


bool InitStack(LinkStack &s){
	s.top=new StackNode;
	s.count=0;
	return true;		
}

bool StackEmpty(LinkStack &s){
	return s.count==0;	
}

bool push(LinkStack &s,int e){
	LinkStackPtr p=new StackNode;
	p->data=e;
	p->next=s.top;
	s.top=p;
	s.count++;
	return true;
}

bool pop(LinkStack &s,int &e){
	if(StackEmpty(s))
		return false;
	LinkStackPtr p=s.top;
	e=p->data;
	s.top=s.top->next;
	free(p);
	s.count--;
	return true;
}




int main(){
	LinkStack s;
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
