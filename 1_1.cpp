#include<bits/stdc++.h>
using namespace std;

typedef struct circle_list
{
	int number;
	int code;
	struct circle_list *next;
}*List,Node;
 

//�������ݵ�������
int insert_list(List &head,int i)
{
	    //�����ڵ�
	    int val;
	    printf("���������룺");
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
    cout<<"����������:"; 
    cin>>n;
    for(int i=1;i<=n;++i)
    	insert_list(newlist,i);
    int count=10;
    List num=newlist;
    //cout<<"��һ��Ԫ�أ�"<<newlist->number<<endl; 
    while(count--){
    	cout<<num->code;
    	num=num->next;
    }
    int m=20;
    cout<<"������mֵ";
	cin>>m; 
	List r = newlist;
	List p = newlist;
	while(newlist->next!=newlist){
		p=r;
		while(r->next!=p)r=r->next;//�ҵ���һ��Ԫ��֮ǰ���Ǹ�������ɾ������ 
		for(int i=1;i<m;++i){
			p=p->next;	
			r=r->next;	
		}//�ҵ�Ҫɾ����Ԫ��p
		m=p->code; 
		cout<<p->number<<" ";
		if(p!=newlist)//����:���p�����׸�Ԫ�� 
			r->next=p->next;
		else
		{
			newlist=p->next;
			r->next=newlist;
		}
		r=r->next;
		free(p);
	}
	//�˳�ѭ��˵��ֻ��һ���ڵ��ˣ�ֱ���������
	cout<<newlist->number; 
    return 0;
}
 

