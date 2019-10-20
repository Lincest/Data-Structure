#include<bits/stdc++.h>
using namespace std;

int n;
int check[15];

typedef struct tree{
	int left;
	int right;
	char element;
}tree;

tree tree1[15],tree2[15];

int BuildTree(struct tree *tree){
	cin>>n;
	char l,r,ele;
	for(int i=0;i<n;++i){
		cin>>ele;tree[i].element=ele;
		cin>>l;
		if(l!='-')
			tree[i].left=l-'0';
		else
			tree[i].left=-1;
		cin>>r;
		if(r!='-')
			tree[i].right=r-'0';
		else
			tree[i].right=-1;
	}
	for(int i=0;i<n;++i){
		if(tree[i].right!=-1)
			check[tree[i].right]=1;
		if(tree[i].left!=-1)
			check[tree[i].left]=1;
	}
	for(int i=0;i<n;++i)
	{
		if(check[i]!=1)
			return i;
	}
	return -1;
}

bool JudgeTree(int t1,int t2){
	if(t1==-1&&t2==-1)return true;	//两个皆空 
	if((t1==-1&&t2!=-1)||(t1!=-1&&t2==-1))return false;	//一个空一个不空
	if(tree1[t1].element!=tree2[t2].element)return false;
	//cout<<"我还没死"<<endl;
	//cout<<tree1[t1].left<<" "<<tree1[t1].right<<" "<<tree2[t2].left<<" "<<tree2[t2].right<<endl;
	if(tree1[t1].left==-1&&tree2[t2].left==-1)
		return JudgeTree(tree1[t1].right,tree2[t2].right);
	else if(tree1[tree1[t1].left].element==tree2[tree2[t2].left].element){	//如果树1号的左边等于树2号的左边，则比较右边是否相同，若都相同则分别比较左边和右边是否同构 
		if(tree1[tree1[t1].right].element==tree2[tree2[t2].right].element){
		//	cout<<"左左等右右"<<endl;			
			return JudgeTree(tree1[t1].left,tree2[t2].left)&&JudgeTree(tree1[t1].right,tree2[t2].right);
		}
		else 
			return false;
	}
	else{
		if(tree1[tree1[t1].right].element==tree2[tree2[t2].left].element){
		//	cout<<"嘿嘿"<<endl;
			return JudgeTree(tree1[t1].left,tree2[t2].right)&&JudgeTree(tree1[t1].right,tree2[t2].left);
		}
		else
			return false;
	}
}


int main(){
	int root1 = BuildTree(tree1);
	memset(check,0,sizeof(check));
	int root2 = BuildTree(tree2);
	bool flag=JudgeTree(root1,root2);
	if(flag==true)cout<<"Yes";
	else cout<<"No";
	return 0;
}


