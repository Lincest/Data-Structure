#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
struct node{
	ll l,r,lmx,rmx,mx,sum;
}a[200000];
ll num[50001];
void update(ll k){
	a[k].sum=a[k<<1].sum+a[k<<1|1].sum;
	a[k].lmx=max(a[k<<1].sum+a[k<<1|1].lmx,a[k<<1].lmx);
	a[k].rmx=max(a[k<<1|1].sum+a[k<<1].rmx,a[k<<1|1].rmx);
	a[k].mx=max(max(a[k<<1].mx,a[k<<1|1].mx),a[k<<1].rmx+a[k<<1|1].lmx);
}
void build(ll k,ll l,ll r){
	a[k].l=l;a[k].r=r;
	if(l==r){
		a[k].sum=a[k].lmx=a[k].rmx=a[k].mx=num[l];
		return ;
	}
	ll mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	update(k);
	return ;
}
 
void change(ll k,ll pos,ll cnt){
	if(a[k].l==a[k].r){
		a[k].sum=a[k].lmx=a[k].rmx=a[k].mx=cnt;
		return ;
	}
	ll mid=(a[k].l+a[k].r)>>1;
	if(pos<=mid){
		change(k<<1,pos,cnt);
	}
	else {
		change(k<<1|1,pos,cnt);
	}
	update(k);
	return ;
}
 
node query(ll k,ll l,ll r){
	if(a[k].l>=l&&a[k].r<=r){
		return a[k];
	}
	ll mid=(a[k].l+a[k].r)>>1;
	if(r<=mid)return query(k<<1,l,r);
	else if(l>mid)return query(k<<1|1,l,r);
	else{
		node la=query(k<<1,l,mid);
		node lb=query(k<<1|1,mid+1,r);
		node lc;
		lc.l=la.l;
		lc.r=lb.r;
		lc.lmx=max(la.lmx,la.sum+lb.lmx);
		lc.rmx=max(lb.rmx,lb.sum+la.rmx);
		lc.mx=max(max(lb.mx,la.mx),la.rmx+lb.lmx);
		return lc;
	}
}
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>num[i];
	}
	build(1,1,n);
	ll x,y;
	while(m--){
		cin>>x>>y;
		if(x>=y){
			ll temp=x;
			x=y;
			y=temp;
		}
		node t=query(1,x,y);
		cout<<t.mx<<endl;
	}
	return 0;
}
