#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 100 //��󶥵���
#define MAX_INT 10000 //����� 




typedef int AdjType; 


typedef struct{
    int pi[MAX_VERTEX_NUM];//���v��vi��һ�����·��
    int end;
}PathType;
 
typedef char VType; //�趥��Ϊ�ַ�����


typedef struct{
    VType V[MAX_VERTEX_NUM]; //����洢�ռ� 
    AdjType A[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //�ڽӾ��� 
}MGraph;//�ڽӾ����ʾ��ͼ


//Floyd�㷨
//����G�����ڽӾ����ʾ����������������·�� 
//D[][]�����·�����Ⱦ���path[][]���·����־���� 
void Floyd(MGraph * G,int path[][MAX_VERTEX_NUM],int D[][MAX_VERTEX_NUM],int n){ 
    int i,j,k;
    for(i=0;i<n;i++){//��ʼ�� 
        for(j=0;j<n;j++){
            if(G->A[i][j]<MAX_INT){
                path[i][j]=j;
            }else{
                path[i][j]=-1;
            }
            D[i][j]=G->A[i][j];
        }
    } 
    
    for(k=0;k<n;k++){//����n����̽ 
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];//ȡС�� 
                    path[i][j]=path[i][k];//��Vi�ĺ�� k; //
                }
            }
        }
    }
}




int main(){
    int i,j,k,v=0,n,adjm;//vΪ��㣬nΪ������� ,n=6
    MGraph G;
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//v������������·������
    int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//v�����������·���������� 
    scanf("%d", &n);
    //��ʼ�� a
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

	k=path[x][y];//ȡ·����Vi�ĺ���Vk
	if (k<0)
	{
		printf("NO\n");
		continue;
	}
	printf("%d\n",D[x][y]);
	
    printf("%d ",x);//���Vi�����i
                while(k!=y){//k������·���յ�jʱ 
                    printf("%d ",k);//���k
                    k=path[k][y];//��·������һ������� 
                }
                printf("%d\n",y);//���·���յ���� 
	}

    return 0;
}