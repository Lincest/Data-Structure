#include <stdio.h>

int vset[1000];
int findset(int x)
{
	while(vset[x]!=0)
		x=vset[x];
	return x;
}

int main()
{
	int m,n,i,a,b,va,vb,count;
	
	scanf("%i",&n);
	for (i=1;i<=n;i++)
		vset[i]=0;
	scanf("%i",&m);
	for (i=0;i<m;i++){
		scanf("%i%i",&a,&b);
		va=findset(a);
		vb=findset(b);
		if (va!=vb)
			vset[va]=vb;
	}
	count=0;
	for (i=1;i<=n;i++)	
		if (vset[i]==0)
			count++;
	printf("%i\n",count-1);
	return 0;
}
