#include<bits/stdc++.h>
using namespace std;

/*
总结一下：
没有注意特殊情况：
0多项式
多项式抵消
*/
 
typedef struct List{
	int coe; //系数
	int index; //指数
	struct List *next; 
}*LinkList,Node;

LinkList ReadList(){
	int n,c,i;
	scanf("%d",&n);
	LinkList list,p,rear;
	list = (LinkList)malloc(sizeof(Node));
	list->next=NULL;
	rear=list;
	while(n--){
		scanf("%d %d",&c,&i);//读入系数和指数
		p= (LinkList)malloc(sizeof(Node));
		p->coe=c;p->index=i;
		rear->next=p;
		rear=p;
		rear->next=NULL;
	}
	return list;
}

void PrintList(LinkList &list){
	LinkList p=list->next;
	if(p==NULL){
		printf("0 0");
		return ;
	}
	while(p->next!=NULL){
		printf("%d %d ",p->coe,p->index);
		p=p->next;
	}
	printf("%d %d",p->coe,p->index);
}

void InsertList(LinkList &list,LinkList &p){
	LinkList rear=list;
	while(rear->next!=NULL&&p->index<rear->next->index){
		rear=rear->next;		
	}//找到插入的前驱元素，即p要插入到rear后 
	if(rear->next&&p->index==rear->next->index)
	{	//如果有指数相同的情况出现 
		if(rear->next->coe+p->coe==0)
			rear->next=rear->next->next;
		else
			rear->next->coe+=p->coe;
		free(p);
	}
	else{
		p->next=rear->next;
		rear->next=p;
	}
}

LinkList AddList(LinkList &list1,LinkList &list2){
	LinkList p1 = list1->next;
	LinkList p2 = list2->next;
	LinkList list = (LinkList)malloc(sizeof(Node));
	list->next = NULL;
	LinkList rear=list;
	while(p1&&p2){	//这里坑死我啦，三个if千万千万不能并行 
		if(p1->index>p2->index){
			rear->next=p1;
			p1=p1->next;
		}
		else if(p1->index<p2->index){
			rear->next=p2;
			p2=p2->next;
		}
		else if(p1->index==p2->index){
			//考虑到相消的情况
			if(p1->coe+p2->coe==0){
				p1=p1->next;
				p2=p2->next;
				continue;
			}	
			if(p1->coe+p2->coe!=0){
				rear->next=p1;
				rear->next->coe=p1->coe+p2->coe;			 				
				p1=p1->next;
				p2=p2->next;
			}	
		}
		rear=rear->next;
	}
	rear->next=(p1)?p1:p2;
	return list;
}

LinkList MulList(LinkList &list1,LinkList &list2){	//先算出来再插入的思路 
	LinkList p1 = list1->next;
	LinkList p2 = list2->next;
	LinkList list = (LinkList)malloc(sizeof(Node));
	list->next = NULL;
	//int cnt=1;
	while(p1!=NULL){
		while(p2!=NULL){
			LinkList p=(LinkList)malloc(sizeof(Node));
			p->coe=p1->coe*p2->coe;
			p->index=p1->index+p2->index;
			InsertList(list,p);
			p2=p2->next;
			//cout<<cnt<<" ";cnt++;
		}
		p1=p1->next;
		p2=list2->next;
	}	
	return list;
}

int main(){
	LinkList Mul_List,Add_List,list1,list2;
	list1 = ReadList();
	list2 = ReadList();
	Mul_List = MulList(list1,list2);
	Add_List = AddList(list1,list2);
	PrintList(Mul_List);
	cout<<endl;
	PrintList(Add_List);
	return 0;
}
