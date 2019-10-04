#include<bits/stdc++.h>
using namespace std;

typedef struct Stack{
	Stack *next;
	char data;
}*LinkStack,Stack;

bool StackEmpty(LinkStack &s){
	return s->next==NULL;
}

void InitStack(LinkStack &s){
	s = new Stack;
	s->next=NULL;
}

bool Push(LinkStack &s,char &e){
	LinkStack p = new Stack;
	p->data=e;
	p->next=s;
	s=p;
	return true;
}

bool Pop(LinkStack &s){
	if(!StackEmpty(s)){
		s=s->next;
		return true;
	}
	else return false;
	
}

char top(LinkStack &s){
	return !StackEmpty(s)?s->data:'F';
}



int main(){
	LinkStack s;
	InitStack(s);
	string str1;
	char ss;
	cin>>str1;
	int flag=1;
	for(int i=0;i<str1.size();++i){
		if(str1[i]=='}'||str1[i]==']'||str1[i]==')')
		{
			if((str1[i]=='}'&&top(s)=='{')||(str1[i]==']'&&top(s)=='[')||(str1[i]==')'&&top(s)=='('))
			{
				Pop(s);
				continue;
			}
			else
				flag=0;
		}
		else if(str1[i]=='['||str1[i]=='{'||str1[i]=='(')
		{
			Push(s,str1[i]);
			continue;
		}
		else 
			continue;
	}
	if(!StackEmpty(s))flag=0;
	if(flag==1)printf("À¨ºÅÆ¥Åä");
	if(flag==0)printf("À¨ºÅ²»Æ¥Åä");
	return 0;
}
