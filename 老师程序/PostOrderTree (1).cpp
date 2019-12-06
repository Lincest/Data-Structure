#include<stdio.h>

bool VerifySquenceOfBST(int *sequence, int length)
{
    int root = sequence[length - 1];
    // �ڶ������������������Ľ��С�ڸ����
    int i = 0;
    for(; i < length - 1; ++ i)
    {
        if(sequence[i] > root)
            break;
    }
	// �ڶ������������������Ľ����ڸ����
    int j = i;
    for(; j < length - 1; ++ j)
    {
        if(sequence[j] < root)
            return false;
    }

    // �ж��������ǲ��Ƕ���������
    bool left = true;
    if(i > 1)
        left = VerifySquenceOfBST(sequence, i);

    // �ж��������ǲ��Ƕ���������
    bool right = true;
    if(length-i-1 > 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

int main()
{
	int A[100];
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&A[i]);
		if(VerifySquenceOfBST(A, n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
