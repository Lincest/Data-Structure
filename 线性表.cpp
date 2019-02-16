#include<cstdio>
#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef int Elemtype;	//Elemtype类型根据实际情况而定，这里取int
typedef struct 
{
	int data[MAXSIZE];
	int length;
}Sqlist;		//线性表的顺序储存结构



//线性表的抽象数据类型
Sqlist InitList(Sqlist* L)		//初始化建立一个空表
{
	Sqlist list;
	L->length = 0;
	list.length = L->length;
	for(int i=0;i<MAXSIZE;++i)
		list.data[i] = 0;
	return list;
}	

bool ListEmpty(Sqlist* L){			//若线性表为空返回true不然返回false
	if(L->length==0) return true;
	return false;
	
}	

bool ClearList(Sqlist *L)			//清空线性表
{
	for(int i=0;i<MAXSIZE;++i)
		L->data[i] = 0;
	return true;
}	

bool GetElem(Sqlist L,int i,Elemtype* e)		//将线性表的第i个位置元素返回给e,若不存在返回false
{
	if(L.length==0 || i<1 || i>L.length)
		return false;
	*e = L.data[i-1];	//因为return返回状态，故这里用指针实现
	return true;
}	

int LocateElem(Sqlist* L,Elemtype e)		//在线性表L中查找与给定值e相等的元素，若查找成功，返回该元素在表中的标号表示成功；否则返回0表示失败
{
	for(int i=0;i<L->length;++i)
	{
		if(L->data[i] == e)	return i;
	}
	return false;
}	


bool ListInsert(Sqlist* L,int i,Elemtype e)		//在线性表L中的第i个位置插入新元素e
{
	int k;
	if(L->length == MAXSIZE)
		return false;
	if(i<1 || i>L->length)
		return false;
	if(i<=L->length)
	{
		for(k=L->length-1;k>=i-1;k--)	//将要插入位置之后的数据依次后移
			L->data[k+1] = L->data[k];
	}
	L->data[i-1] = e;	//插入元素e
	L->length++;		//长度+1
	return true;
}	


bool ListDelete(Sqlist* L,int i,Elemtype* e)		//删除线性表L中的第i个位置元素，并用e返回其值
{
	int k;
	if(L->length == 0)
		return false;
	if(i<1 || i>L->length)
		return false;
	*e = L->data[i-1];
	if(i<L->length)	//删除位置后继元素前移
	{
		for(k=i;k<L->length;k++)
			L->data[k-1] = L->data[k];
	}
	L->length--;
	return true;
}	

int ListLength(Sqlist *L){
	int k=0;
	for(int i=0;i<MAXSIZE;++i)
	{
		if(L->data[i] != 0) ++k;
	}
	L->length = k;
	return k;
}	//返回线性表L的元素个数

int main()
{
	int a;
	Elemtype* e = &a;
	Sqlist lista;
	lista = InitList(&lista);
	for(int i=0;i<10;++i)
		{lista.data[i] = i;lista.length++;}
	for(int i=0;i<lista.length;++i)
		printf("%d",lista.data[i]);
	return 0;
	
}