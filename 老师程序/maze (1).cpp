//#include <iostream>
//#include <fstream>

//using namespace std;

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

typedef struct {
	int ord;
	int x,y;
	int dir;
}SElemType;

typedef int MazeType, **Maze;

typedef struct StackNode {
	SElemType pos;
	StackNode *next;
}StackNode, *LinkStack;

void InitStack_L(LinkStack &S)
{
	S = NULL;
}

bool StackEmpty_L(LinkStack S)
{
	if(S)
		return false;
	else
		return true;
}

int Push_L(LinkStack &S, SElemType e)
{
	LinkStack p;

    p = (LinkStack)malloc(sizeof(StackNode));
    if(!p) 
      exit(0);
	p->pos.ord = e.ord;
	p->pos.x = e.x;
	p->pos.y = e.y;
	p->pos.dir = e.dir;
	p->next = S;
	S = p;
    return OK;
}

int Pop_L(LinkStack &S, SElemType &e)
{
	LinkStack p;

	if(S==NULL)
		return ERROR;
	else{
		p = S;
		S = S->next;
		e.ord = p->pos.ord;
		e.x = p->pos.x;
		e.y = p->pos.y;
		e.dir = p->pos.dir;
		free(p);
		return OK;
	}
}

typedef struct{
     SElemType  *base;
     SElemType  *top; 
     int stacksize; 
}SqStack; 

void InitStack_S(SqStack &S, int size)
{
	S.base = S.top = (SElemType *)malloc(size*sizeof(SElemType));
    if(!S.base) 
		exit(0);
    S.stacksize = size;
}

bool StackEmpty_S(SqStack S)
{
	if(S.top == S.base)
		return true;
	else
		return false;
}

int Push_S(SqStack &S, SElemType e)
{
	S.top->ord = e.ord;
	S.top->x = e.x;
	S.top->y = e.y;
	S.top->dir = e.dir;
	S.top++;
    return OK;
}

int Pop_S(SqStack &S, SElemType &e)
{
	if(S.top == S.base)
		return ERROR;
	else{
		S.top--;
		e.ord = S.top->ord;
		e.x = S.top->x;
		e.y = S.top->y;
		e.dir = S.top->dir;
		return OK;
	}
}

void NextPos(SElemType &NextPos)
{
	int movei[4] = {0,1,0,-1};
	int movej[4] = {1,0,-1,0};
	if(NextPos.dir >= 4 || NextPos.dir < 0)
		return;
	NextPos.x = NextPos.x + movei[NextPos.dir];
	NextPos.y = NextPos.y + movej[NextPos.dir];
}

void MarkPrint(Maze &maze, SElemType pos)
{
	maze[pos.x][pos.y] = 3; //曾走过，但不通。printf("@");
}

void FootPrint(Maze &maze, SElemType pos)
{
	maze[pos.x][pos.y] = 2; //正在当前路径上。printf("*");
}

bool Pass(Maze maze, SElemType pos)
{
	if(!maze[pos.x][pos.y])
		return true;
	else
		return false;
}

bool operator == (SElemType M, SElemType N)
{
	return M.x==N.x && M.y==N.y; 
}

int ReadMaze(Maze &maze,int &m,int &n)
{
	char *filename="maze.txt";
	char ch;
	int i, j;

/*	ifstream fin;
	fin.open(filename,ios::in);
	fin>>m>>n;
	maze=new MazeType*[m];
	for (i=0;i<m;i++) maze[i]=new MazeType[n];
	for (i=0;i<m;i++)
		for (j=0;j<n;j++) {
			fin>>ch;
			maze[i][j] = ch=='1';
		}
	fin.close();
*/
	FILE *mazefile;
	

	if((mazefile = fopen(filename,"r"))==NULL) {
		printf("Could not open maze file\n");
		exit(0);
	}
	fscanf(mazefile,"%d %d\n",&m,&n);
	maze = new MazeType*[m];
	for (i=0;i<m;i++) 
		maze[i] = new MazeType[n];
	for (i=0;i<m;i++){
		for (j=0;j<n;j++) {
			fscanf(mazefile,"%c",&ch);
			maze[i][j] = ch=='1';
		}
		fscanf(mazefile,"\n");
	}

	return OK;
}

int PrintMaze(Maze maze,int m,int n)
{
/*	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			switch(maze[i][j]) {
				case 0:cout<<' ';break;
				case 1:cout<<'#';break;
				case 3:cout<<'@';break;
				case 2:cout<<'*';
			};
		}
		cout<<endl;
	}
*/
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++) {
			switch(maze[i][j]) {
				case 0:
					printf(" ");
					break;
				case 1:
					printf("#");
					break;
				case 3:
					printf("@");
					break;
				case 2:
					printf("*");
			};
		}
		printf("\n");
	}
	printf("\n");

	return OK;
}

int MazePath(Maze &maze, SElemType start, SElemType end) 
{
	int curstep;
	SElemType curpos;
	LinkStack S;
	//SqStack S;

	InitStack_L(S);
	//InitStack_S(S, 100);
	curpos.x = start.x;
	curpos.y = start.y;
	curstep = 1;

	do{
		if(Pass(maze, curpos)){
			FootPrint(maze, curpos);
			curpos.ord = curstep;
			curpos.dir = 0;
			Push_L(S, curpos);
			//Push_S(S, curpos);
			if(curpos == end)
				return OK;
			NextPos(curpos);
			curstep++;
		}
		else{
			if(!StackEmpty_L(S)){
			//if(!StackEmpty_S(S)){
				Pop_L(S, curpos);
				//Pop_S(S, curpos);
				while(curpos.dir == 4 && !StackEmpty_L(S)){
				//while(curpos.dir == 4 && !StackEmpty_S(S)){
					MarkPrint(maze, curpos);
					Pop_L(S, curpos);
					//Pop_S(S, curpos);
				}
				if(curpos.dir < 4){
					curpos.dir++;
					Push_L(S, curpos);
					//Push_S(S, curpos);
					NextPos(curpos);
				}
			}
		}
	}while(!StackEmpty_L(S));
	//}while(!StackEmpty_S(S));

	return ERROR;
}

int main()
{
	int m,n;
	Maze maze;
	SElemType start, end;

	ReadMaze(maze,m,n);
	printf("迷宫如下(空格为通路，#为墙):\n");
	PrintMaze(maze,m,n);
	
	start.x = start.y = 1;
	end.x = m-2;
	end.y = n-2;

	if (MazePath(maze, start, end)) {
		printf("从入口到出口的路径为(*为路径):\n");
		PrintMaze(maze,m,n);
	}else 
		printf("找不到从入口到出口的路径!\n");

	return 0;
}


