#include<iostream>
#include<stack>

using namespace std;

char p[7][7]=       // +-*/()#
{
	'>','>','<','<','<','>','>',
	'>','>','<','<','<','>','>',
	'>','>','>','>','<','>','>',
	'>','>','>','>','<','>','>',
	'<','<','<','<','<','=','@',
	'>','>','>','>','@','>','>',
	'<','<','<','<','<','@','=' 
};

stack<double>opdn;
stack<char>optr;

double operation(double a,char ch,double b);
int index(char);
double EvaluateExpression();
bool is_digit(char);

int main()
{
	for(;;)
		cout<<EvaluateExpression()<<endl;
	return 0;
}
double EvaluateExpression()
{	
	optr.push('#');
	char ch,ch1;
	cin>>ch;	
	double a,b;

	for(;;){
		if(ch == '#' && optr.top() == '#')
			break;
        if(is_digit(ch)){
			double m = ch-'0';
			//while(cin>>ch,is_digit(ch))
			while(ch=getchar(),is_digit(ch))
				m = m*10+ch-'0';
			opdn.push(m);
			continue;
		}
		
		int pos1 = index(optr.top());
		int pos2 = index(ch);

		switch(p[pos1][pos2]){
			case '<': 
				optr.push(ch); 
				cin>>ch;
				break;
			case '=': 
				optr.pop();
				cin>>ch; 
				break;
			case '>': 
				ch1 = optr.top(); 
				optr.pop();
				a = opdn.top(); 
				opdn.pop();
				b = opdn.top();
				opdn.pop();	
				opdn.push(operation(b,ch1,a));
				break;
		}
	}
	return opdn.top();
}


double operation(double a,char ch,double b)
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

int index(char ch)
{
	//string seq="+-*/()#";
	switch(ch){
		case '+': 
			return 0;
		case '-': 
			return 1;
		case '*': 
			return 2;
		case '/': 
			return 3;
		case '(': 
			return 4;
		case ')': 
			return 5;
		case '#': 
			return 6;
	}
}

bool is_digit(char ch)
{
	return ch>='0' && ch<='9';
}