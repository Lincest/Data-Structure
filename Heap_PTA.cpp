#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int N,M;
	int index;
	vector<int> v;
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>index;
		v.push_back(index);
		make_heap(v.begin(),v.end(),greater<int>());
	}
	int b[1000];
	for(int i=0;i<N;++i)
		b[i+1]=v[i];
	for(int i=1;i<=M;++i){
		cin>>index;
		for(int j=index;j>=1;j/=2){
			if(j!=1)
				cout<<b[j]<<" ";
			if(j==1)
				cout<<b[1];
		}
		if(i!=M)
			cout<<endl;
	}
	return 0;
}	//STLÐ´·¨ 
*/ 

int main(){	//CÓïÑÔÐ´·¨
	int N,M;
	int ele;
	cin>>N>>M;
	int H[1001];
	H[0]=-10001;
	int size=0,j;
	for(int i=1;i<=N;++i){
		if(i==1){
			cin>>ele;
			H[1]=ele;
			size=1;
		}
		else{
		cin>>ele;
		size++;
		for(j=size;H[j/2]>ele;j/=2)
			H[j]=H[j/2];
		H[j]=ele;
		}
	}
	int index;
	for(int i=1;i<=M;++i){
		cin>>index;
		for(int j=index;j>=1;j/=2){
			if(j!=1)
				cout<<H[j]<<" ";
			if(j==1)
				cout<<H[1];
		}
		if(i!=M)
			cout<<endl;
	}
	return 0;
}


