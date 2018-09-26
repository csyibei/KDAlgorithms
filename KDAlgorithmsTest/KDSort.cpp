#include <stdio.h>
#include <iostream>
using namespace std;

void KDPrintfArray(int *array1,int lenght)
{
	for (int i = 0; i < lenght; ++i)
	{
		cout<<array1[i]<<endl;
	}
}

void KDSwap(int *numbers,int i,int j)
{
	int temp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = temp;
}

//选择排序
int *KDSelectSort(int *numbers,int lenght)
{
	for (int i = 0; i < lenght - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < lenght; ++j)
		{
			if (numbers[j] < numbers[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			KDSwap(numbers,i,min);
		}
	}
	return numbers;
}

//冒泡排序
int *KDBubbleSort(int *numbers,int lenght)
{
	for (int i = 0; i < lenght - 1; ++i)
	{
		for (int j = lenght - 1; j > i; --j)
		{
			if (numbers[j] < numbers[j - 1])
			{
				KDSwap(numbers,j,j - 1);
				// int temp = numbers[j];
				// numbers[j] = numbers[j - 1];
				// numbers[j - 1] = temp;
			}
		}
	}
	return numbers;
}

//插入排序
int *KDInsertSort(int *numbers,int lenght)
{
	 for (int i = 1; i < lenght; ++i)
	 {
	 	int temp = numbers[i];
	 	while(i > 0 && numbers[i - 1] > temp)
	 	{
	 		numbers[i] = numbers[i - 1];
	 		i--;
	 	}
	 	numbers[i] = temp;
	 }
	 return numbers;
}

//堆排序
void KDHeapAdjust(int *numbers,int rootIndex,int lenght)
{
	int temp = numbers[rootIndex];
	for (int i = 2*rootIndex + 1; i < lenght; i = 2 * i + 1)
	{
		if (i+1 < lenght && numbers[i] < numbers[i + 1])
		{
			 i = i + 1;
		}

		if (numbers[i] > temp)
		{
			//这里面是重点（要想清为什么不swap）
			// KDSwap(numbers,i,rootIndex);
			numbers[rootIndex] = numbers[i];
			rootIndex = i;
		}
	}
	numbers[rootIndex] = temp;
}

int *KDHeapSort(int *numbers,int lenght)
{
	for (int i = lenght / 2 - 1; i >= 0; --i)
	{
		KDHeapAdjust(numbers,i,lenght);
	}

	for (int i = lenght - 1; i > 0; --i)
	{
		KDSwap(numbers,0,i);
		KDHeapAdjust(numbers,0,i);
	}
	return numbers;
}

//归并排序
void KDMerge(int *numbers,int left,int middle,int right,int sortedArr[])
{
		int i = left;
		int j = middle + 1;
		int index = 0;
		while(i <= middle && j <= right)
		{
			if (numbers[i] <= numbers[j])
			{
				sortedArr[index++] = numbers[i++];
			}else
			{
				sortedArr[index++] = numbers[j++];
			}
		}


		while (i <= middle)
		{
			sortedArr[index ++] = numbers[i++];
		}

		while(j <= right)
		{
			sortedArr[index ++] = numbers[j++];
		}

		//下面这个是重点
		index= 0;
		while(left <= right)
		{
			numbers[left++] = sortedArr[index++];
		}
}

int * KDMergeSort(int *numbers,int left,int right,int sortedArr[])
{
	if (left < right)
	{
		int middle = (right - left) / 2 + left;
		KDMergeSort(numbers,left,middle,sortedArr);
		KDMergeSort(numbers,middle + 1,right,sortedArr);
		KDMerge(numbers,left,middle,right,sortedArr);
	}
	return numbers;
}

//快排


int main()
{
	// int numbers[] = [2,3,4,56 6,8,7,1];
	int numbers[]  = {14,99,10,56,8,7,-1};
	KDPrintfArray(numbers,7);
	// int *newnumbers = KDInsertSort(numbers,7);
	// int *newnumbers = KDBubbleSort(numbers,7);
	// int *newnumbers = KDSelectSort(numbers,7);
	//int *newnumbers = KDHeapSort(numbers,7);
	int sortedArr[] = {0,0,0,0,0,0,0};
	int  *newnumbers = KDMergeSort(numbers,0,6,sortedArr);
	cout<<"----"<<endl;
	KDPrintfArray(newnumbers,7);
}














