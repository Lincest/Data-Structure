#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 100 //最大顶点数
#define MAX_INT 10000 //无穷大 




typedef int AdjType; 


typedef struct{
    int pi[MAX_VERTEX_NUM];//存放v到vi的一条最短路径
    int end;
}PathType;
 
typedef char VType; //设顶点为字符类型


typedef struct{
    VType V[MAX_VERTEX_NUM]; //顶点存储空间 
    AdjType A[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵 
}MGraph;//邻接矩阵表示的图


//Floyd算法
//求网G（用邻接矩阵表示）中任意两点间最短路径 
//D[][]是最短路径长度矩阵，path[][]最短路径标志矩阵 
void Floyd(MGraph * G,int path[][MAX_VERTEX_NUM],int D[][MAX_VERTEX_NUM],int n){ 
    int i,j,k;
    for(i=0;i<n;i++){//初始化 
        for(j=0;j<n;j++){
            if(G->A[i][j]<MAX_INT){
                path[i][j]=j;
            }else{
                path[i][j]=-1;
            }
            D[i][j]=G->A[i][j];
        }
    } 
    
    for(k=0;k<n;k++){//进行n次试探 
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];//取小者 
                    path[i][j]=path[i][k];//改Vi的后继 k; //
                }
            }
        }
    }
}




int main(){
    int i,j,k,v=0,n,adjm;//v为起点，n为顶点个数 ,n=6
    MGraph G;
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//v到各顶点的最短路径向量
    int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//v到各顶点最短路径长度向量 
    scanf("%d", &n);
    //初始化 a
    /*AdjType a[MAX_VERTEX_NUM][MAX_VERTEX_NUM]={
        {0,12,18,MAX_INT,17,MAX_INT},
        {12,0,10,3,MAX_INT,5},
        {18,10,0,MAX_INT,21,11},
        {MAX_INT,3,MAX_INT,0,MAX_INT,8},
        {17,MAX_INT,21,MAX_INT,0,16},
        {MAX_INT,5,11,8,16,0} 
        };*/
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &adjm);
            G.A[i][j]=adjm;
        }
    } 
    
    Floyd(&G,path,D,n);

	int x, y;
	for (;;)
	{
	scanf("%d %d",&x,&y);
	if (x==-1 && y==-1)
		break;

	k=path[x][y];//取路径上Vi的后续Vk
	if (k<0)
	{
		printf("NO\n");
		continue;
	}
	printf("%d\n",D[x][y]);
	
    printf("%d ",x);//输出Vi的序号i
                while(k!=y){//k不等于路径终点j时 
                    printf("%d ",k);//输出k
                    k=path[k][y];//求路径上下一顶点序号 
                }
                printf("%d\n",y);//输出路径终点序号 
	}

    return 0;
}