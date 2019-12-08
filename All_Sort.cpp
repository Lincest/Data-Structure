#include<bits/stdc++.h>
using namespace std;
int array[15]={0,1,9,3,5,4,6,8,7,10,2};
void swap(int *arr,int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

void BubbleSort(int *arr,int n){
	int i,j;
	for(i=1;i<=n;++i){
		for(j=n;j>=i;--j){
			if(arr[j]<arr[j-1])
				swap(arr,j,j-1);
		}
	}
}

void SelectSort(int *arr,int n){
	int i,j,min;
	for(i=1;i<n;++i){
		min=i;
		for(j=i+1;j<=n;++j)
		{
			if(arr[j]<arr[min])
				min=j;
		}
		if(i!=min)
			swap(arr,i,min);
		// cout<<"\nThe "<<i<<" sort: ";
		// for(int i=1;i<=10;++i)
		// 	cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void InsertSort(int *arr,int n){
	int i,j;
	for(i=2;i<=n;++i){
		if(arr[i]<arr[i-1])
		{
			arr[0]=arr[i];
			for(j=i-1;arr[j]>arr[0];--j)
				arr[j+1]=arr[j];
			arr[j+1]=arr[0];
		}
		// cout<<"\nThe "<<i-1<<" sort: ";
		// for(int i=1;i<=10;++i)
		// 	cout<<arr[i]<<" ";
	}
}

void ShellSort(int *arr,int n){
	int i,j;
	//int cnt=1;
	int increment = n;
	do{
		increment = increment/3+1;
		for(i=increment+1;i<=n;++i){
			if(arr[i]<arr[i-increment]){
				arr[0]=arr[i];
				for(j=i-increment;j>0&&arr[j]>arr[0];j-=increment)
					arr[j+increment]=arr[j];
				arr[j+increment]=arr[0];
			}
			// cout<<"\nThe "<<cnt++<<" sort: ";
			// for(int i=1;i<=10;++i)
			// 	cout<<arr[i]<<" ";
		}
	}while(increment>1);
}


int Partition(int *arr,int low,int high){
	int pivotkey=arr[low];
	while(low<high){
		while(low<high&&arr[high]>=pivotkey){
			high--;
		}
		swap(arr,low,high);
		while(low<high&&arr[low]<pivotkey){
			low++;
		}
		swap(arr,low,high);
	}
	return low;
}
void QuickSort(int *arr,int low,int high){
	int pivot;
	if(low<high){
		pivot=Partition(arr,low,high);
		// cout<<"\nThe next sort: ";
		// for(int i=1;i<=10;++i)
		// 	cout<<arr[i]<<" ";
		QuickSort(arr,low,pivot-1);
		QuickSort(arr,pivot+1,high);
	}
}


void HeapAdjust(int *arr,int s,int m){
	//调整arr[s...m]使其构成一个大顶堆
	int temp,j;
	temp = arr[s];
	for(j=s*2;j<=m;j*=2){
		if(j<m&&arr[j]<arr[j+1])
			j++;
		if(arr[j]<temp)break;
		arr[s]=arr[j];
		s=j;
	}
	arr[s]=temp;
}
void HeapSort(int* arr,int n){
	int i;
	for(i=n/2;i>0;i--)
		HeapAdjust(arr,i,n);

	for(i=n;i>1;--i){
		swap(arr,1,i);
		cout<<"\nThe next sort: ";
		for(int j=1;j<=10;++j)
			cout<<arr[j]<<" ";
		HeapAdjust(arr,1,i-1);
	}
}


int main(){
	cout<<"Before sort: ";
	for(int i=1;i<=10;++i)
		cout<<array[i]<<" ";
	HeapSort(array,10);
	cout<<"\nAfter sort: ";
	for(int i=1;i<=10;++i)
		cout<<array[i]<<" ";
	return 0;
}