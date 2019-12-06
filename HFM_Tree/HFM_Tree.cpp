#include<bits/stdc++.h>
using namespace std;
const int N=500;
map<char, string>M;//����map�洢�ַ��͹���������֮��Ĺ�ϵ 

typedef struct //hfm���Ľڵ� 
{
    int par,l,r;	//�ֱ�����ף���������������,Ȩ��
	int weight;
	char c;
}node;

//��������СȨ���±�min1, min2
void Select(node *Htree, int m, int &min1, int &min2)	//Htree��m��ʾ������ 
{
    min1 = min2 = 0;
    Htree[0].weight = 1e9;
    for(int i = 1; i <= m; i++)
    {
        if(!Htree[i].par && Htree[i].weight < Htree[min1].weight)	//1-m�Ų��ң�����ǹ����Ľ�㲢�ҵ�ǰȨС��Ŀǰ��С���������Сֵ 
            min1 = i;
    }
    Htree[min1].par = -1;	//����ǰ�ҵ�����С��㸸�ױ��Ϊ-1����֮����������������ҵ����ǵڶ�С�Ľ�� 
    for(int i = 1; i <= m; i++)
    {
        if(!Htree[i].par && Htree[i].weight < Htree[min2].weight)
            min2 = i;
    }
}

void CreateTree(node *Htree, int n)	//������������,n��ʾ������ 
{
    int min1 = 0, min2 = 0;
    int now = n+1, m = n; //now���½ڵ���±꣬m��Ѱ�ҵ�����
    for(int i = 1; i < n; i++)
    {
        Select(Htree, m, min1, min2); //��[1,m]����������СȨ���±����now
        //printf("��%d���ҵ���now �� %d \n",i,Htree[min1].weight + Htree[min2].weight);
        Htree[now].weight = Htree[min1].weight + Htree[min2].weight;
        Htree[now].l = min1, Htree[now].r = min2;
        Htree[now].c = '#';
        Htree[min1].par = now, Htree[min2].par = now;
        now++;
        m++;
    }
}

//��ӡ��
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
	cout<<"\n�ѽ������Ĺ�������д��hfmTree.txt�ļ���\n"<<endl;
	fclose(fp);
}

node* Initialization(char* input_c,int *input_w,int len)	//len��ʾ�ַ��ĸ��� 
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

string ReadFile()	//��ȡCodeFile�ļ� 
{
	ifstream in("CodeFile.txt");
	string out;
	in>>out;
	return out;
	in.close();
}

void Encode(node *Htree, int n)	//len=2n-1 
{
    char temp[N];//��ʱ���ĳ��Ҷ�ӽڵ�Ĺ���������
    int now = N-1;
    //�����Ƴ����������룬���Ϊ0���ұ�Ϊ1
    puts("�������Ϊ��");
    for(int i = 1; i <= n; i++)	//��1�ŵ�n�������Ƴ����������� 
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

//���й���������
void Decode()
{
	string s = ReadFile();
	FILE *fp = fopen("CodePrin.txt","w");
    int len = s.size(), c = 0;
    char str[N];
    cout<<"��CodeFile��������Ϊ��"<<endl;
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
    cout<<"\n�ѽ��������CodePrin.txt��"<<endl;
    fclose(fp);
}


string Save_encodeFile(string str){	//��������ΪҪ���ܵ�string 
	string str_encode="";
	for(int i=0;i<str.size();++i)
	{
		str_encode+=M[str[i]];
	}
	ofstream savefile("CodeFile.txt");
    savefile<<str_encode;
    savefile.close();
    cout<<"str���ܺ�Ϊ: "<<str_encode<<endl;
    cout<<"�ѽ����ܺ������д���ļ�CodeFile.txt��\n";
    return str_encode;
}



int main(){
//	char input_char[100]=" ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	int input_weight[100]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};
//	int n=27;	//n��ʾ�ַ����� 
	//char input_char[100]="ABCDEFGH";
	//int input_weight[100]={5,29,7,8,14,23,3,11};
	char input_char[100]="ABCDEFG";
	int input_weight[100]={1,13,38,8,15,5,20};
	int n=7;	//n��ʾ�ַ����� 
	cout<<"�ַ�Ƶ��Ϊ: \n";
	for(int i=0;i<n;++i){
		printf("%c : %d\n",input_char[i],input_weight[i]);
	}
	node* Htree = Initialization(input_char,input_weight,n);
	Encode(Htree,n); //�Թ����������� 
	
	
	//����Ϊ���������ĳ�ʼ�� 
	
	char x;
	cout<<"\n���������������ϵͳ����:\nQ �˳�\nD ��CodeFile���ļ����벢�����ݴ���CodePrin\nP ��ӡCodeFile��Դ��\nE ���벢����������CodeFile�ļ�\n\n\n" ;
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
				cout<<"��������Ҫ���ܵ��ַ���: ";
				string str;
				getchar();
				getline(cin,str);
				string str_encode = Save_encodeFile(str);
				cout<<"\n\n";
			}
	}

	return 0;
}
