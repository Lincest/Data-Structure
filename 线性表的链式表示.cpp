#include<bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR -1


typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList_L(LinkList &L,int n){
	//�������������
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
	 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	//��ͷ���ĵ����� 
	for(int i=n;i>0;--i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		scanf("%d",&p->data);
		p->next = L->next;
		L->next = p;
	} 
} 

void CreateList_L_Tail(LinkList &L,int n){
	//�������������---β�巨 
	//˳λ������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L
	 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	//��ͷ���ĵ����� 
	LinkList r=L;
	for(int i=n;i>0;--i)
	{
		LinkList p = (LinkList)malloc(sizeof(LNode));//�����½ڵ�
		scanf("%d",&p->data);
		r->next = p;
		r = p;
	} 
	r->next=NULL; //��Ҫ��һ��ʼ���� 
} 


int GetElem_L(LinkList L,int i,int &e)
{
	//ȡֵ 
	//LΪ��ͷ���ĵ������ͷָ��
	//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
	LinkList p = L->next;
	int j=1;	//Ŀǰ�ڵ�һ����� 
	while(p&&j<i){
		p = p->next;
		++j;
	} 
	if(!p||j>i)return ERROR;	//iԪ�ز����� 
	e = p->data;
	return OK;
}

void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc){
	//������La��Lb��Ԫ��ֵ�ǵݼ�����
	//�鲢La��Lb�õ��µĵ������Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
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
