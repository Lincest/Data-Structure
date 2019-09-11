#include<bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR -1


typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList_L(LinkList &L,int n){
	//单链表的整表创建
	//逆位序输入n个元素的值，建立带表头结点的单链线性表L
	 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	//带头结点的单链表 
	for(int i=n;i>0;--i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));//生成新节点
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	} 
} 

void CreateList_L_Tail(LinkList &L,int n){
	//单链表的整表创建---尾插法 
	//顺位序输入n个元素的值，建立带表头结点的单链线性表L
	 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	//带头结点的单链表 
	LinkList r=L;
	for(int i=n;i>0;--i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));//生成新节点
		scanf("%d",&p->data);
		r->next = p;
		r = p;
	} 
	r->next=NULL; //重要，一开始忘了 
} 


int GetElem_L(LinkList L,int i,int &e)
{
	//取值 
	//L为带头结点的单链表的头指针
	//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
	LinkList p = L->next;
	int j=1;	//目前在第一个结点 
	while(p&&j<i){
		p = p->next;
		++j;
	} 
	if(!p||j>i)return ERROR;	//i元素不存在 
	e = p->data;
	return OK;
}

void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	//单链表La和Lb按元素值非递减排列
	//归并La和Lb得到新的单链线性表Lc，Lc的元素也按值非递减排列
	 Lc=(LinkList)malloc(sizeof(LNode));
	 Lc=La;
	 LinkList pc=Lc,pa,pb;
	 pa=La->next;
	 pb=Lb->next;
	 while(pa&&pb)
	 {
	 	if(pa->data<=pb->data){
	 		pc->next=pa;
	 		pc=pc->next;
	 		pa=pa->next;
		}
		else{
	 		pc->next=pb;
	 		pc=pc->next;
	 		pb=pb->next;
		}		
	 }
	 pa->next==NULL?pc->next=pb:pc->next=pa;
	 free(Lb);
}


int main()
{
	LinkList list_tail,list_tail2,p;
	CreateList_L_Tail(list_tail,3);
	CreateList_L_Tail(list_tail2,3);
	LinkList listmerge;
	MergeList_L(list_tail,list_tail2,listmerge);
	p=listmerge;
	while(p->next){
		p=p->next;
		cout<<p->data<<" ";
	}
	return 0;	
}
