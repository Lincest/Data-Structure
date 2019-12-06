#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct {
	char  data;
    int weight;
	int parent ,lchild ,rchild;
}HTNode ,*HuffmanTree;

typedef char **HuffmanCode;

void select(HuffmanTree HT,int i,int &s1,int &s2);

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,char *ch,int *w,int n )
{                   
	int i,c,f,m;
	FILE *treefile;

 	if((treefile = fopen("hfm_Tree.txt","w"))==NULL) {
		printf("Could not open hfm_Tree.txt file\n");
		exit(0);
	}
	if (n <= 1){
		printf("Can not complete a huffmanTree");
	    exit(0);
	}
	
    HuffmanTree p; 

	m = 2*n-1;

	HT=	(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(p=HT+1,i=1; i<=n; ++i,++p,++w,++ch){ //若不用0号单元，p=HT+1
		p->data = *ch;                    
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	//*p={*ch,*w,0,0,0};
	for(;i<=m;++i,++p,ch++){ 
		p->data = '#';
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	//*p={'#',0,0,0,0};
	int s1,s2;
	for(i=n+1;i<=m;++i){ 
		select(HT,(i-1),s1,s2);
		fprintf(treefile, "%c:%-4d %c:%-4d\n", HT[s1].data, HT[s1].weight, HT[s2].data, HT[s2].weight); 
        HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight+HT[s2].weight;
	}
	fclose(treefile);

	HC = (HuffmanCode)malloc((m+1)*sizeof(char*));
	char *cd;
	cd = (char*)malloc(n*sizeof(char));
	cd[n-1] ='\0';
	for(i=1;i<=n;++i){
		int start = n-1;
		for( c=i, f=HT[i].parent;f != 0;c=f,f=HT[f].parent)
			if(HT[f].lchild == c)
				cd[--start] = '0';
			else 
				cd[--start] = '1';
		HC[i] = (char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free (cd);
}

//select函数，寻找从1到i的结点中parent=0而且权最小的两个结点，返回s1和s2
void select(HuffmanTree HT,int i,int &s1,int &s2)
{  
	int w1 = INT_MAX;//最大的有符号整数<limits.h>

	for(int j=1;j<=i;j++){
	    if(HT[j].parent == 0 && HT[j].weight < w1){
			w1 = HT[j].weight;
		    s1 = j;
		}
	}
    HT[s1].parent = 1;
	w1 = INT_MAX;
	for(j=1;j<=i;j++){
	    if(HT[j].parent == 0 && HT[j].weight < w1){   
			w1 = HT[j].weight;
		    s2 = j;
		}
	}
}

void  Encoding(HuffmanCode HC, char *Alphabet)//编码
{
	char ch;
	int k;
	FILE *tranfile, *codefile;

	if((tranfile = fopen("ToBeTran.txt","r"))==NULL) {//打开文件ToBeTran.txt
		printf("Could not open ToBeTran.txt file\n");
		exit(0);
	}
	if((codefile = fopen("CodeFile.txt","w"))==NULL) {//打开文件CodeFile.txt
		printf("Could not open CodeFile.txt file\n");
		exit(0);
	}

	while(fscanf(tranfile, "%c", &ch) != EOF){
		printf("%c:", ch);
		k =  strchr(Alphabet, ch)-Alphabet+1;
		if(k < 1){
			//非法字符，进行错误处理....；
			return;
		}
		printf("%s\n", HC[k]);
		fprintf(codefile, "%s", HC[k]);
	}
	printf("\n");

	fclose(tranfile);
	fclose(codefile);
}

void Decoding(HuffmanTree  HT,int n)//解码
{

	char ch;
	FILE *codefile, *textfile;

	if((codefile = fopen("CodeFile.txt","r"))==NULL) {//打开文件CodeFile.txt
		printf("Could not open CodeFile.txt file\n");
		exit(0);
	}
	if((textfile = fopen("TextFile.txt","w"))==NULL) {//打开文件TextFile.txt
		printf("Could not open TextFile.txt file\n");
		exit(0);
	}

 	int m = 2*n-1;
	while(fscanf(codefile, "%c", &ch) != EOF){
		if(ch == '1')
			m = HT[m].rchild ;
		else
			m = HT[m].lchild ;
		if(HT[m].lchild==0 && HT[m].rchild == 0){
			fprintf(textfile, "%c", HT[m].data);
			m=2*n-1;
		}
	}
   fclose(codefile);
   fclose(textfile);
}

void Printcode()
{
	char ch;int i=0;
	FILE *codefile;

	if((codefile = fopen("CodeFile.txt","r"))==NULL) {//打开文件CodeFile.txt
		printf("Could not open CodeFile.txt file\n");
		exit(0);
	}

	while(fscanf(codefile, "%c", &ch) != EOF){
		printf("%c", ch);
		i++;
		if(i == 50){
			i = 0;
			printf("\n");
		}
	}
	printf("\n");
	fclose(codefile);
}

void TreePrint(HuffmanTree HT, int n, int num)
{
	int i;

	if(HT[n].lchild==0 && HT[n].rchild == 0){
		for(i=0; i<2*num; i++)
			printf("-");
		if(HT[n].data == ' ')
			printf("#\n");
		else
			printf("%c\n", HT[n].data);

		return;
	}
	else{
		for(i=0; i<2*num; i++)
			printf("-");
		printf("%d\n", HT[n].weight);
	}
	TreePrint(HT, HT[n].lchild, num-1);
	TreePrint(HT, HT[n].rchild, num-1);
}

void main ()
{  
	HuffmanTree HT ;
	HuffmanCode HC;
	FILE *chfile;
	int n, i;

	char *Alphabet; //待编码的字符表，27个字符"ABCDEFGHIJKLMNOPQRSTUVWXYZ "
	int *weight;

	if((chfile = fopen("character.txt","r"))==NULL) {//打开文件character.txt
		printf("Could not open character.txt file\n");
		exit(0);
	}

	fscanf(chfile, "%d\n", &n);
	Alphabet = (char *)malloc(n*sizeof(char));
	weight = (int *)malloc(n*sizeof(int));

	for(i=0; i<n; i++)
		Alphabet[i] = fgetc(chfile);
	for(i=0; i<n; i++)
		fscanf(chfile, "%d", &weight[i]);
	fclose(chfile);
	
	HuffmanCoding(HT,HC,Alphabet,weight,n);
	Encoding(HC, Alphabet);
	Decoding(HT,n);
	Printcode();
	TreePrint(HT, 2*n-1, n/2);

	free(Alphabet);
	free(weight);
}