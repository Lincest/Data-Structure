#include <bits/stdc++.h>
using namespace std;
map<char, int>M;
map<char, string>M1;
const int N = 500;
char s[N];
struct node
{
    int weight, par, l, r;	//�ֱ����Ȩ�أ����ף��������������� 
    char c;	 
};

//��������СȨ���±�min1, min2
void select(node *Htree, int m, int &min1, int &min2)
{
    min1 = min2 = 0;
    Htree[0].weight = 1e9;
    for(int i = 1; i <= m; i++)
    {
        if(!Htree[i].par && Htree[i].weight < Htree[min1].weight)
            min1 = i;
    }
    Htree[min1].par = -1;
    for(int i = 1; i <= m; i++)
    {
        if(!Htree[i].par && Htree[i].weight < Htree[min2].weight)
            min2 = i;
    }
}

//������������
void H_tree(node *Htree, int n)
{
    int min1 = 0, min2 = 0;
    int now = n+1, m = n;//now���½ڵ���±꣬m��Ѱ�ҵ�����
    for(int i = 1; i < n; i++)
    {
        select(Htree, m, min1, min2);//��[1,m]����������СȨ���±����now
        Htree[now].weight = Htree[min1].weight + Htree[min2].weight;
        Htree[now].l = min1, Htree[now].r = min2;
        Htree[min1].par = now, Htree[min2].par = now;
        now++;
        m++;
    }
}

//��ӡ��
//void print(node *t,int next)
//{
//    printf("%d\n",t[next].weight);
//    if(t[next].l)
//        print(t, t[next].l);
//    if(t[next].r)
//        print(t, t[next].r);
//}

//���й���������
void encode(node *Htree, int n, int len)
{
    char temp[N];//��ʱ���ĳ��Ҷ�ӽڵ�Ĺ���������
    int now = N-1;
    //�����Ƴ����������룬���Ϊ0���ұ�Ϊ1
    temp[now] = '\0';
    puts("�������Ϊ��");
    for(int i = 1; i <= n; i++)
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
        M1[Htree[i].c] = temp1;
    }
    puts("Դ�� -> ������ ��2.txt !");
    //��Դ����ת���ɹ��������뱣���ļ�
    ofstream savefile("2.txt");
    for(int i = 0; i < len; i++)
        savefile << M1[s[i]];
    savefile.close();
}
//���й���������
void decode(node *Htree)
{
    puts("������ -> Դ�� ��3.txt !");
    FILE *fp1, *fp2;
    fp1 = fopen("2.txt", "r");
    fscanf(fp1, "%[^\n]", s);
    fp2 = fopen("3.txt", "w");
    int len = strlen(s), c = 0;
    char str[N];
    for(int i = 0; i < len; i++)
    {
        str[c++] = s[i];
        str[c] = '\0';
        for(map<char, string>::iterator it = M1.begin(); it != M1.end(); it++)
        {
            if(it->second == str)
            {
                fprintf(fp2, "%c", it->first);
                c = 0;
            }
        }
    }
}

int main()
{
    ///�����ڳ���·���д���1.txt������
    FILE *fp = NULL;
    int len = 0;
    char c;
    fp = fopen("1.txt", "r");
    if(!fp)
    {
        puts("������ԴĿ¼����1.txt��");
        return 0;
    }
    while((c = fgetc(fp)) != EOF)
        s[len++] = c;
    fclose(fp);
    node *Htree;
    Htree = (node*)malloc((2*len)*sizeof(node));//Htree��0-2*len-1
    for(int i = 0; i < len; i++)
        M[s[i]]++;              //ͳ��ÿ���ַ���Ƶ��
    int n = 0;
    //n��Ҷ�ӵĹ�����������2*n-1���ڵ�
    for(int i = 0; i < len; i++)
    {
        if(M[s[i]] != 0)
        {
            Htree[++n].weight = M[s[i]];
            M[s[i]] = 0;        //Ƶ����0��ֹ�ظ�����
            Htree[n].par = Htree[n].l = Htree[n].r = 0;
            Htree[n].c = s[i];
        }
    }
    Htree[0].weight = Htree[0].par = Htree[0].l = Htree[0].r = 0;//0�Žڵ�ȫ����ֵΪ0������ʹ��
    for(int i = n+1; i < 2*n; i++)
        Htree[i].weight = Htree[i].par = Htree[i].l = Htree[i].r = 0;
    H_tree(Htree, n);
    //print(Htree,2*n-1);
    encode(Htree, n, len);
    decode(Htree);
    return 0;
}
