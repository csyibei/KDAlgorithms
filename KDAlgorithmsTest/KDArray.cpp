#include <stdio.h>
#include <iostream>
using namespace std;


void KDSwap(int *numbers,int indexa,int indexb)
{
	int temp = numbers[indexa];
	numbers[indexa] = numbers[indexb];
	numbers[indexb] = temp;
}

//第三题1 数组中找重复数字
int KDFindDuplicateNumberInArr1(int *numbers,int arrLenght)
{
    for (int i = 0; i < arrLenght; ++i)
    {
    	while(numbers[i] != i)
    	{
    		KDSwap(numbers,numbers[i],i);
    		if (numbers[i] == numbers[numbers[i]])
    		{
    			return numbers[i];
    		}
    	}
    }
	return 0;
}

//第三题2 数组中找重复数字 不能改变数组
int KDFindDuplicateNumberInArr2(int *numbers,int arrLenght)
{

	return 0;
}

//面试题4 递增二维数组中找整数
bool KDFindNumberInArr(int *numbers,int rows,int columns,int number)
{
	int currentRow = 0;
	int currentColumn =  columns - 1;
	//下面注释掉了错误写法 不能比完列再比行  因为这样会直接错过存在的数 必须行列变化交替进行 建议自己画图分析
	// while(number <= numbers[currentRow*columns+currentColumn] && currentColumn >= 0)
	// {
	// 	if (number == numbers[currentRow*columns+currentColumn])
	// 	{
	// 		return true;
	// 	}
	// 	currentColumn--;
	// }

	// while(number >= numbers[currentRow*columns+currentColumn] && currentRow < rows)
	// {
	// 	if (number == numbers[currentRow*columns+currentColumn])
	// 	{
	// 		return true;
	// 	}
	// 	currentRow++;
	// }
	while(currentColumn >= 0 && currentRow < rows)
	{
		if (number == numbers[currentRow*columns+currentColumn])
		{
			return true;
		}

		if (number < numbers[currentRow*columns+currentColumn])
		{
			currentColumn--;
		}else{
			currentRow++;
		}

	}
	return false;
}



int main()
{
	int nums[] = {1,2,3,4,
				  3,5,6,7,
				  4,6,7,8,};
	// int result = KDFindDuplicateNumberInArr1(nums,8);
	bool result = KDFindNumberInArr(nums,3,4,9);
	printf("%d\n",result);
}

