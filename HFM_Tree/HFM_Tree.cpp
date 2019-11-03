#include<bits/stdc++.h>
using namespace std;

typedef struct //hfm树的节点 
{
    int par,l,r;	//分别代表父亲，左子树，右子树,权重
	int weight;
	char c;
}node;

//找两个最小权的下标min1, min2
void Select(node *Htree, int m, int &min1, int &min2)	//Htree，m表示结点个数 
{
    min1 = min2 = 0;
    Htree[0].weight = 1e9;
    for(int i = 1; i <= m; i++)
    {
        if(!Htree[i].par && Htree[i].weight < Htree[min1].weight)	//1-m号查找，如果是孤立的结点并且当前权小于目前最小，则更新最小值 
            min1 = i;
    }
    Htree[min1].par = -1;	//将当前找到的最小结点父亲标记为-1，在之后调用上述方法则找到的是第二小的结点 
    for(int i = 1; i <= m; i++)
    {
        if(!Htree[i].par && Htree[i].weight < Htree[min2].weight)
            min2 = i;
    }
}

void CreateTree(node *Htree, int n)	//创建哈夫曼树,n表示结点个数 
{
    int min1 = 0, min2 = 0;
    int now = n+1, m = n; //now是新节点的下标，m是寻找的上限
    for(int i = 1; i < n; i++)
    {
        Select(Htree, m, min1, min2); //在[1,m]中找两个最小权的下标组成now
        //printf("第%d次找到了now ： %d \n",i,Htree[min1].weight + Htree[min2].weight);
        Htree[now].weight = Htree[min1].weight + Htree[min2].weight;
        Htree[now].l = min1, Htree[now].r = min2;
        Htree[min1].par = now, Htree[min2].par = now;
        now++;
        m++;
    }
}

char* ReadFile(char *s)	//文件的读取 
{
	FILE* FileInput = fopen(s,"r");
	char ReadBuffer[1024] = {0};
	if (FileInput)
	{
	    fread(ReadBuffer,1,1024,FileInput);
	    return ReadBuffer;
	    fclose(FileInput);
	}
	return "file-read error";
}


  //打印树
void print(node *t,int next)
{
    printf("%d\n",t[next].weight);
    if(t[next].l)
        print(t, t[next].l);
    if(t[next].r)
        print(t, t[next].r);
}


void Initialization(char* input_c,int *input_w,int len)	//len表示字符的个数 
{
	node* Htree;
	Htree = (node*)malloc((2*len)*sizeof(node));
	Htree[0].l=Htree[0].par=Htree[0].r=Htree[0].weight=0;
	for(int i=1;i<=len;++i){
		Htree[i].l=Htree[i].par=Htree[i].r=0;
		Htree[i].weight=input_w[i-1]; 
		Htree[i].c=input_c[i-1];
	} 
	CreateTree(Htree,len);
	print(Htree,2*len-1);
}

int main(){
	//char file[1024]="hfmTree.txt";
	char input_char[100]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int input_weight[100]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
//	char input_char[100]="ABCDEFGH";
//	int input_weight[100]={5,29,7,8,14,23,3,11};
	Initialization(input_char,input_weight,27);
	return 0;
}
