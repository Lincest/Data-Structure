#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
	char data;
	struct Stack *next;
}Stack;

void push(Stack *&S, char e);
bool pop(Stack *&S, char &e);
void DestroyStack(*&S);
bool matching(Stack *&S, char *str);


void main()
{
	char str[256];

	printf("Please enter a string:");

/*	输入串：while (m<(a[8]+t) {m=m+1;  t=t-1;}
*/
/*方法1：*/
	gets(str);

/*方法2：
    char ch;
	int i = 0;
	 
	while((ch=getchar())!='\n')
		str[i++] = ch;
	str[i] = '\0';
*/	   

	Stack *S;

	S = NULL;

	if(matching(S,str))
		printf("Right!\n");
	else
		printf("Wrong!\n");
	if(S)
		DestroyStack(S);
}

void push(Stack *&S, char e)
{
	Stack *p;

	p = (struct Stack*)malloc(sizeof(struct Stack));
	if(!p)
		printf("There's no space.\n");
	else{
		p->data = e;
		p->next = S;
		S = p;
	}
	
}

bool pop(Stack *&S, char &e)
{
	Stack *p;

	if(S==NULL)
		return false;
	else{
		p = S;
		S = S->next;
		e = p->data;
		free(p);
		return true;
	}
}

void DestroyStack(Stack *&S)
{
	Stack *p;

	p = S;
	while(S){
		p = S;
		S = S->next;
		free(p);
	}
}

bool matching(Stack *&S,char *str)
{
	char *p;
	char e;

	for(p=str; *p; p++){
		switch(*p){
			case '(':
			case '[':
			case '{':
				push(S,*p);
				printf("%c", S->data);
				break;
			case ')':
				if(!pop(S,e)||e != '(')
					return false;
				break;
			case ']':
				if(!pop(S,e)||e != '[')
					return false;
				break;
			case '}':
				if(!pop(S,e)||e != '{')
					return false;
				break;
		}
	}
	if(S==NULL) 
		return true;
	else
		return false; //((((  ))
}


