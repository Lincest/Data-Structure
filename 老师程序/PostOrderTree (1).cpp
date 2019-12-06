#include<stdio.h>

bool VerifySquenceOfBST(int *sequence, int length)
{
    int root = sequence[length - 1];
    // 在二叉排序树中左子树的结点小于根结点
    int i = 0;
    for(; i < length - 1; ++ i)
    {
        if(sequence[i] > root)
            break;
    }
	// 在二叉排序树中右子树的结点大于根结点
    int j = i;
    for(; j < length - 1; ++ j)
    {
        if(sequence[j] < root)
            return false;
    }

    // 判断左子树是不是二叉排序树
    bool left = true;
    if(i > 1)
        left = VerifySquenceOfBST(sequence, i);

    // 判断右子树是不是二叉排序树
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
