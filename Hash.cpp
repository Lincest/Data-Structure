#include<bits/stdc++.h>
using namespace std;
#define NULLKEY -32768
typedef struct{
	int count;
	char name[30];
}Name;	//������count��ʾ������ascii���������֮�ͣ���Ϊ��ϣ��key�����ϣֵ 

typedef struct{
	Name* elem;//���� 
	int count;//����Ԫ�ظ��� 
}HashTable;


int m=43;//ɢ�б��
int sum=0;//����ͳ��ƽ�����Ҵ���
 
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
	while(H->elem[addr].count!=NULLKEY){//�����ͻ
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
	if(strcmp(H.elem[addr].name,name.name)!=0)	//��ֹcount�ҵ��˵������ֲ���ͬ����� 
		return false;
	return true;
}

int main(){
	HashTable H;
	InitHashTable(&H);
	int key=0;
	Name n;
	cout<<"������ϣ��,������ײ����: "<<endl;
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
	printf("ƽ����ײ����Ϊ: %.2f\n",sum/30.0);
	for(int i=0;i<5;++i){
		printf("��������Ҫ���ҵ�����:\n"); 
		scanf("%s",n.name);
		for(int j=0;j<strlen(n.name);++j){
			key+=n.name[j];
		}
		//cout<<key<<endl;
		n.count=key;
		bool x=SearchHash(H,n);
		cout<<"���ҵ����: "<<x<<endl;
		key=0;
	}
	return 0;
}

/*
data�� 
Richard Brant Azarias Adrian 
Brian Hubert Justin Leon Norbert 
Phoebus Peter Patrick Winfred 
Xanthus Zebediah Victor Timon 
Thomas Sandy Nathan Oliver Kyne 
Jove Isaac Eldred Beverley 
Dominic Ashley Darcy Carol
*/
