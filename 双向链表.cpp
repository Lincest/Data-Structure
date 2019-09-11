#include<bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR -1

//双向链表的储存结构
typedef struct DuLNode{
	int data;
	struct DuLNode *next;
	struct DuLNode *prior;
}DuLNode,*DuLinkList; 

int InitList(DuLinkList &L)
{
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->next = NULL;	
	L->prior = NULL;	//带头结点的双向循环链表 
	DuLinkList r=L;
	for(int i=5;i>0;--i)
	{
		DuLinkList p = new DuLNode;//生成新节点
		scanf("%d",&p->data);
		r->next=p;
		p->prior=r;
		r=p;
	} 
	r->next=L;
	L->prior=r;
	return OK;
}

DuLinkList GetElemP_Dul(DuLinkList &L,int i){
	DuLinkList r=L->next;
	for(int j=1;j<i;++j)
	{
		r=r->next;
	}
	return r;
}

int ListInsert_DuL(DuLinkList &L,int i,int e){
	DuLinkList p,s;
	if(!(p=GetElemP_Dul(L,i)))
		return ERROR;
	if(!(s=(DuLinkList)malloc(sizeof(DuLNode))))return ERROR;
	s->data=e;
	p->prior->next=s;
	s->prior=p->prior;
	s->next=p;
	p->prior=s;
	return OK;
}

int ListDelete_DuL(DuLinkList &L,int i){
	//删除带头结点的双向循环线性表L的第i个元素
	DuLinkList p;
	 if(!(p=GetElemP_Dul(L,i)))
		return ERROR;
	p->next->prior=p->prior;
	p->prior->next=p->next;
	free(p);
	return OK;
}

int main()
{
	DuLinkList list;
	InitList(list);
	DuLinkList r=list->next;
	ListInsert_DuL(list,3,100);
	ListDelete_DuL(list,2);
	for(int i=15;i>0;--i){
		if(r==list)
			r=r->next;
		cout<<r->data<<" ";
		r=r->next;
	}
	return 0;
	
}
