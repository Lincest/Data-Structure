#include<stdio.h>
#include <stdlib.h>

void main()
{ 
	int i,j,n,count;
	int G[100][100];
	int stack[100], top;
	int indegree[100] = {0};
	int ve[100] = {0};

	scanf("%d", &n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &G[i][j]);
			if(G[i][j])
				indegree[j]++;
		}
	}

	top = -1;
	for(i=0;i<n;i++)
		if(!indegree[i])
			stack[++top] = i; 
	count = 0;
    while(top>-1){
		i=stack[top--];
        ++count;
        for(j=0;j<n;j++){
			if(G[i][j]){
				if(!(--indegree[j]))
					stack[++top] = j;
				if((ve[i]+G[i][j])>ve[j])
					ve[j] = ve[i]+G[i][j];
			}
		}
	}
	if(count<n)
		printf("NO");
	else
		printf("%d", ve[n-1]);
} 