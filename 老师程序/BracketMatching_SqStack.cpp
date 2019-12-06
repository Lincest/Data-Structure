#include<stdio.h>
#include<stdlib.h>
#include <string.h>

bool matching(char *str)
{
	char *p;
	char Stack[256];
	int top;

	top = -1;
	for(p=str; *p; p++){
		switch(*p){
			case '(':
			case '[':
			case '{':
				Stack[++top] = *p;
				break;
			case ')':
				if(top==-1 || Stack[top]!='(')
					return false;
				top--;
				break;
			case ']':
				if(top==-1 || Stack[top]!='[')
					return false;
				top--;
				break;
			case '}':
				if(top==-1 || Stack[top]!='{')
					return false;
				top--;
				break;
		}
	}
	if(top==-1)
		return true;
	else
		return false;
}

void main()
{
	int n;
	char str[256];

	scanf("%d\n",&n);
	while(n){
		gets(str);
		if(matching(str))
			printf("right\n");
		else{
			printf("wrong\n");
		}
		n--;
	}
}

