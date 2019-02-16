#include<cstdio>
#include<iostream>
#include<ctime>
using namespace std;
#define MAXSIZE 20
typedef int Elemtype;
typedef int Status;		//Status表示状态

typedef struct Node
{
	Elemtype data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;  //定义LinkList



Status GetElem(LinkList L,int i,Elemtype *e)	//用e返回L中第i个元素的值
{
	int j=1;
	LinkList p;
	p = L->next;	//让p指向链表L的第一个结点 	
	while(p&&j<i)	//p不为空且j还没有等于i
	{
		p = p->next;	//p指向下一个结点
		++j;
	}
	if(!p || j>i)
		return false;
	*e = p->data;	//e返回i个元素的数据
	return true;
}


Status ListInsert(LinkList* L,int i,Elemtype e)		//在L的第i个位置前插入新的数据元素e并使L的长度加1
{
	int j=1;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p&&j<i)
	{
		p = p->next;
		++j;
	}
	if(!p||j>i)
		return false;
	s = (LinkList)malloc(sizeof(Node));	//生成新的结点s
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

Status ListDelete(LinkList* L,int i,Elemtype* e)	//删除L的第i个数据元素，用e返回其值，L的长度减1
{
	int j=1;
	LinkList p,q;
	p = *L;
	while(p->next&&j<i)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i)
		return false;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);		//让系统回收此结点，释放内存
	return true;
}


/*单链表的整表创建---头插法*/
void CreateListHead(LinkList* L,int n)		//随机产生n个元素的值，建立带表头结点的单链线性表L（头插法）
{
	LinkList p;
	int i;
	srand(time(0));		//初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));
	(*L) -> next = NULL;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1; //随机生成100以内的数字
		p->next = (*L)->next;
		(*L)->next = p;
	}
}


/*单链表的整表创建---尾插法*/
void CreateListTail(LinkList* L,int n)
{
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L; 	//r为指向尾部的结点
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

int main()
{
	LinkList L = (LinkList)malloc(sizeof(Node));
	LinkList L2 = (LinkList)malloc(sizeof(Node));
	CreateListTail(&L,10);
	CreateListHead(&L2,10);
	while(L->next)
	{
		cout<<L->data<<endl;
		L = L->next;
	}
	cout<<"_---------------------";
	while(L2->next)
	{
		cout<<L2->data<<endl;
		L2 = L2->next;
	}
	return 0;
}