#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read(){
     int n,k;
     scanf("%d",&n);
     List LL;
     LL=(Node*)malloc(sizeof(Node));
     LL->Next=NULL;
     List p=LL;
     for(int i=1;i<=n;++i){
     	 List L;
     	 L=(Node*)malloc(sizeof(Node));
         scanf("%d",&k);
         L->Data=k;
         p->Next=L;
         p=p->Next;
     }
     p->Next=NULL;
     return LL;
}

void Print( List L )
{
	List p=L;
	if(L->Next==NULL)
		printf("NULL");
	while(L->Next!=NULL){
		printf("%d",p->Next->Data);
		p=p->Next;
	}
	
}
 
List Merge( List L1, List L2 ){
    List L3=L1;
    List p=L3;
    while(L1->Next!=NULL&&L2->Next!=NULL){
        if(L1->Next->Data<L2->Next->Data){
            p->Next=L1->Next;
            p=p->Next;
            L1=L1->Next;
        }
        else{
            p->Next=L2->Next;
            p=p->Next;
            L2=L2->Next;
        }
    }
    if(L1->Next==NULL)
        p->Next=L2;
    else
        p->Next=L1;
    free(L1);
    free(L2);
    return L3;
}
