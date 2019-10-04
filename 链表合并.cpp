#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef struct Node {
    ElementType Data;
    PtrToNode   Next;
}Node;
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L3;
    L1 = Read();
    L2 = Read();
    L3 = Merge(L1, L2);
    Print(L3);
    Print(L1);
    Print(L2);
    return 0;
}

List Read(){
     int n,k;
     scanf("%d",&n);
     List LL;
     LL=(List)malloc(sizeof(Node));
     LL->Next=NULL;
     if(n==0)return LL;
     List p=LL;
     for(int i=1;i<=n;++i){
     	 List L;
     	 L=(List)malloc(sizeof(Node));
         scanf("%d",&k);
         L->Data=k;
         p->Next=L;
         p=L;
     }
     p->Next=NULL;
     return LL;
}

void Print( List L )
{
	List p=L->Next;
	if(p){
		List r;
		r=L;
		while(p){
			printf("%d ",p->Data);
			p=p->Next;
	 	}
	}
	else
	{
		printf("NULL");
	}
	printf("\n");
	
}
 
List Merge( List L1, List L2 ){
    List L3=(List)malloc(sizeof(Node));
    L3->Next=NULL;
    List p=L3;
    List p1=L1->Next;
    List p2=L2->Next;
    while(p1&&p2){
        if(p1->Data<=p2->Data){
        	p->Next=p1;
        	p=p1;
        	p1=p1->Next;
        }
        else{
           	p->Next=p2;
        	p=p2;
        	p2=p2->Next;
        }
    }
    if(p2==NULL)
        p->Next=p1;
    else
        p->Next=p2;
    L1->Next=NULL;
    L2->Next=NULL;
    return L3;
    
}
