#include <stdio.h>
#include <iostream>
using namespace std;

int *insertSort(int *numbers,int lenght)
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

void printfArray(int *array1,int lenght)
{
	for (int i = 0; i < lenght; ++i)
	{
		cout<<array1[i]<<endl;
	}
}

int main()
{
	// int numbers[] = [2,3,4,56 6,8,7,1];
	int numbers[]  = {2,0,100,56,8,7,1};
	printfArray(numbers,7);
	int *newnumbers = insertSort(numbers,7);
	cout<<"----"<<endl;
	printfArray(newnumbers,7);
}