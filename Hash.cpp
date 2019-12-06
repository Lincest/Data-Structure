#include<bits/stdc++.h>
using namespace std;
#define NULLKEY -32768
typedef struct{
	int count;
	char name[30];
}Name;	//人名，count表示人名的ascii按数字相加之和，作为哈希的key计算哈希值 

typedef struct{
	Name* elem;//数据 
	int count;//数据元素个数 
}HashTable;


int m=43;//散列表表长
int sum=0;//用于统计平均查找次数
 
bool InitHashTable(HashTable *H){
	int i;
	H->count=m;
	H->elem=(Name *)malloc(m*sizeof(Name));
	for(int i=0;i<m;++i){
		H->elem[i].count=NULLKEY;
	}
	return true;
} 

int Hash(int key){
	return key%m;
}

void InsertHash(HashTable *H,Name name){
	int addr = Hash(name.count);
	double cnt=0;
	while(H->elem[addr].count!=NULLKEY){//如果冲突
		addr = (addr+1)%m;
		cnt++;
	}
	sum+=cnt;
	//cout<<cnt<<" ";
	H->elem[addr] = name; 
}

int SearchHash(HashTable &H,Name name)
{
	int addr = Hash(name.count);
	while(H.elem[addr].count!=name.count){
		addr = (addr+1)%m;
		if(H.elem[addr].count==NULLKEY||addr == Hash(name.count))
			return false;
	}
	if(strcmp(H.elem[addr].name,name.name)!=0)	//防止count找到了但是名字不相同的情况 
		return false;
	return true;
}

int main(){
	HashTable H;
	InitHashTable(&H);
	int key=0;
	Name n;
	cout<<"建立哈希表,计算碰撞次数: "<<endl;
	for(int i=0;i<30;++i){
		scanf("%s",n.name);
		for(int j=0;j<strlen(n.name);++j){
			key+=n.name[j];
		}
	//	cout<<key<<endl;
		n.count=key;
		InsertHash(&H,n);
		key=0;
	}	
	cout<<endl;
	printf("平均碰撞次数为: %.2f\n",sum/30.0);
	for(int i=0;i<5;++i){
		printf("请输入需要查找的人名:\n"); 
		scanf("%s",n.name);
		for(int j=0;j<strlen(n.name);++j){
			key+=n.name[j];
		}
		//cout<<key<<endl;
		n.count=key;
		bool x=SearchHash(H,n);
		cout<<"查找到与否: "<<x<<endl;
		key=0;
	}
	return 0;
}

/*
data： 
Richard Brant Azarias Adrian 
Brian Hubert Justin Leon Norbert 
Phoebus Peter Patrick Winfred 
Xanthus Zebediah Victor Timon 
Thomas Sandy Nathan Oliver Kyne 
Jove Isaac Eldred Beverley 
Dominic Ashley Darcy Carol
*/
