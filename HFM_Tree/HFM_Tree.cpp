#include<bits/stdc++.h>
using namespace std;
const int N=500;
map<char, string>M;//利用map存储字符和哈夫曼编码之间的关系 

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
        Htree[now].c = '#';
        Htree[min1].par = now, Htree[min2].par = now;
        now++;
        m++;
    }
}

//打印树
void print(node *t,int next)
{
	queue<node> q;
	q.push(t[next]);
	node out;
	FILE *fp;
	fp = fopen("hfmTree.txt", "w");
	while(!q.empty()){
		out=q.front();
		q.pop();
	    fprintf(fp,"%c %d	",out.c,out.weight);
	    if(out.l&&out.r){
	        q.push(t[out.l]);
	        q.push(t[out.r]);
	    }
	}
	cout<<"\n已将建立的哈夫曼树写入hfmTree.txt文件中\n"<<endl;
	fclose(fp);
}

node* Initialization(char* input_c,int *input_w,int len)	//len表示字符的个数 
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
	return Htree;
}

string ReadFile()	//读取CodeFile文件 
{
	ifstream in("CodeFile.txt");
	string out;
	in>>out;
	return out;
	in.close();
}

void Encode(node *Htree, int n)	//len=2n-1 
{
    char temp[N];//临时存放某个叶子节点的哈夫曼编码
    int now = N-1;
    //逆序推出哈夫曼编码，左边为0，右边为1
    puts("编码规则为：");
    for(int i = 1; i <= n; i++)	//从1号到n号依次推出哈夫曼编码 
    {
        now = N-1;
        for(int j = i; Htree[j].par != 0; j = Htree[j].par)
        {
            int p = Htree[j].par;
            if(Htree[p].l == j) temp[--now] = '0';
            else temp[--now] = '1';
        }
        printf("%c : %s\n", Htree[i].c, temp+now);
        string temp1(temp+now);
        M[Htree[i].c] = temp1;
    } 
}

//进行哈夫曼解码
void Decode()
{
	string s = ReadFile();
	FILE *fp = fopen("CodePrin.txt","w");
    int len = s.size(), c = 0;
    char str[N];
    cout<<"对CodeFile的译码结果为："<<endl;
    for(int i = 0; i < len; i++)
    {
        str[c++] = s[i];
        str[c] = '\0';
        for(map<char, string>::iterator it = M.begin(); it != M.end(); it++)
        {
            if(it->second == str)
            {
                printf("%c", it->first);
                fprintf(fp,"%c", it->first);
                c = 0;
            }
        }
    }
    cout<<"\n已将结果存入CodePrin.txt中"<<endl;
    fclose(fp);
}


string Save_encodeFile(string str){	//输入内容为要加密的string 
	string str_encode="";
	for(int i=0;i<str.size();++i)
	{
		str_encode+=M[str[i]];
	}
	ofstream savefile("CodeFile.txt");
    savefile<<str_encode;
    savefile.close();
    cout<<"str加密后为: "<<str_encode<<endl;
    cout<<"已将加密后的内容写入文件CodeFile.txt中\n";
    return str_encode;
}



int main(){
//	char input_char[100]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	int input_weight[100]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
//	int n=27;	//n表示字符个数 
	//char input_char[100]="ABCDEFGH";
	//int input_weight[100]={5,29,7,8,14,23,3,11};
	char input_char[100]="ABCDEFG";
	int input_weight[100]={1,13,38,8,15,5,20};
	int n=7;	//n表示字符个数 
	cout<<"字符频度为: \n";
	for(int i=0;i<n;++i){
		printf("%c : %d\n",input_char[i],input_weight[i]);
	}
	node* Htree = Initialization(input_char,input_weight,n);
	Encode(Htree,n); //对哈夫曼树编码 
	
	
	//以上为哈夫曼树的初始化 
	
	char x;
	cout<<"\n进入哈夫曼树编码系统，按:\nQ 退出\nD 对CodeFile中文件译码并将内容存入CodePrin\nP 打印CodeFile中源码\nE 输入并编码内容至CodeFile文件\n\n\n" ;
	while(scanf("%c",&x)&&x!='Q')
	{
			if(x=='D'){
				Decode();
				cout<<"\n\n";
			}
			else if(x=='P'){
				string s = ReadFile();
				cout<<s<<endl;
				cout<<"\n\n";
			}
			else if(x=='E'){
				cout<<"请输入需要加密的字符串: ";
				string str;
				getchar();
				getline(cin,str);
				string str_encode = Save_encodeFile(str);
				cout<<"\n\n";
			}
	}

	return 0;
}
