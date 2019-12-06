#include <stdio.h>

int m,n,P;
int *list;

int search(int x,bool print)
{
	int h,hi;
	h=hi=x%P;
	for (int i=2;i<=m/2*2+2;i++)
	{
		if (list[hi]==x || list[hi]==-1)
			break;
		if (print)
			printf("%d ",list[hi]);
		if (i%2==0)
			hi=(h+(i/2)*(i/2))%m;
		else
			hi=((h-(i/2)*(i/2))%m+m)%m;
	}
	if (print)
	{
		if (list[hi]==-1)
			printf("NULL\n");
		if (list[hi]==x)
			printf("%d\n",x);
	}
	return hi;
}

void insert(int x)
{
	int location;
	location=search(x,0);
	if (list[location]==x)
		return;
	if (list[location]==-1)
		list[location]=x;
	else 
		printf("Table FULL!\n");
	
}
int main()
{
	int i,x;
	scanf("%d%d%d",&n,&m,&P);
	list=new int[m];
	for (i=0;i<m;i++)
		list[i]=-1;

	for (i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(x);
	}
/*
	printf("List is: ");
	for (i=0;i<m;i++)
		printf("%d ",list[i]);
	printf("\n");
*/
	for(;;)
	{
		scanf("%d",&x);
		if (x==-1)
			return 0;
		search(x,1);
	}
}