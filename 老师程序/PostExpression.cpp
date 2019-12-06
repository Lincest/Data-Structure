#include<stdio.h>

bool is_digit(char ch);
int operation(int a,char ch,int b);

void main()
{
	char str[256];
	char *p;
	int stack[256];
	int top;
	int a,b;

	gets(str);
	top = -1;
	for(p=str; *p; p++){
		if(is_digit(*p))
			stack[++top] = *p-'0';
		else{ 
			a = stack[top--];
			b = stack[top--];
			stack[++top] = operation(b,*p,a);
		}
	}
	printf("%d\n",stack[0]);
	
}

bool is_digit(char ch)
{
	return ch>='0' && ch<='9';
}

int operation(int a,char ch,int b)
{
	switch(ch){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}