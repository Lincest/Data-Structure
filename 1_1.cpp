#include<bits/stdc++.h>
using namespace std;

typedef struct circle_list
{
	int number;
	int code;
	struct circle_list *next;
}*List,Node;
 

//插入数据到链表中
int insert_list(List &head,int i)
{
	    //创建节点
	    int val;
	    printf("请输入密码：");
	    cin>>val;
		List newnode = (List)malloc(sizeof(Node)) ;
		newnode->code = val;
		newnode->number = i;
	    if(head->next!= NULL)
		{
	        List p = head;
			while(p->next != head )
			{
				p = p->next;
			}
			p->next = newnode;
			newnode->next = head;
			return 1;
 
		}
		else
		{
			 head=newnode;
			 newnode->next=head;
		}
}



int main()
{
    List newlist;
    newlist = (List)malloc(sizeof(Node));
    int n;
    cout<<"请输入人数:"; 
    cin>>n;
    for(int i=1;i<=n;++i)
    	insert_list(newlist,i);
    int count=10;
    List num=newlist;
    //cout<<"第一个元素："<<newlist->number<<endl; 
    while(count--){
    	cout<<num->code;
    	num=num->next;
    }
    int m=20;
    cout<<"请输入m值";
	cin>>m; 
	List r = newlist;
	List p = newlist;
	while(newlist->next!=newlist){
		p=r;
		while(r->next!=p)r=r->next;//找到第一个元素之前的那个，用于删除方便 
		for(int i=1;i<m;++i){
			p=p->next;	
			r=r->next;	
		}//找到要删除的元素p
		m=p->code; 
		cout<<p->number<<" ";
		if(p!=newlist)//特判:如果p不是首个元素 
			r->next=p->next;
		else
		{
			newlist=p->next;
			r->next=newlist;
		}
		r=r->next;
		free(p);
	}
	//退出循环说明只有一个节点了，直接输出即可
	cout<<newlist->number; 
    return 0;
}
 

