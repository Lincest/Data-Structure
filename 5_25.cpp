#include<bits/stdc++.h>
using namespace std;

int main(){
	int V1[4] = {15,22,-6,9};
	int V2[6] = {3,4,5,6,7,8};
	int B1[3][4] = {{1,0,0,1},{0,1,0,0},{1,0,0,0}};
	int B2[3][4] = {{1,0,1,1},{0,1,0,1},{0,0,0,1}};
	int C[3][4];
	int V3[15];
	memset(C,0,sizeof(C));
	memset(V3,0,sizeof(V3));
	int cnt1=0,cnt2=0,cnt=0;
	for(int i=0;i<3;++i)
		for(int j=0;j<4;++j){
			if(B1[i][j]==1&&B2[i][j]==1)
			{
				C[i][j]=1;
				V3[cnt++]=V1[cnt1++]+V2[cnt2++];
			}
			else if(B1[i][j]==1&&B2[i][j]==0){
				C[i][j]=1;
				V3[cnt++]=V1[cnt1++];
			}
			else if(B1[i][j]==0&&B2[i][j]==1){
				C[i][j]=1;
				V3[cnt++]=V2[cnt2++];
			}
		}
	for(int i=0;i<15;++i){
		cout<<V3[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<4;++j){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
