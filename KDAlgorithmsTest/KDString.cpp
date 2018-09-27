#include <stdio.h>
#include <iostream>
using namespace std;


// 第五题 将字符串中的空格替换成%20
void KDReplaceSpaceInString(char str[],int lenght)
{
	if (str == NULL)
	{
		return;
	}
	 int spaceCount = 0;
	 int originStrLenght = 0;
	 while (str[originStrLenght] != '\0')
	 {
	 	originStrLenght++;
	 	if (str[originStrLenght] == ' ')
	 	{
	 		spaceCount++;
	 	}
	 }
	 int newlenght = originStrLenght + spaceCount * 3 - 2;
	 if (newlenght > lenght)
	 	return;
	
	 while(newlenght > originStrLenght && originStrLenght >= 0)
	 {
	 	if(str[originStrLenght] != ' ')
	 	{
	 		str[newlenght--] = str[originStrLenght--];
	 	}else{
	 		originStrLenght--;
	 		str[newlenght--] = '0';
	 		str[newlenght--] = '2';
	 		str[newlenght--] = '%';
	 	}	
	 }
}

int main()
{
  int lenght = 100;
  char str[lenght] = "i am kaidi";
  KDReplaceSpaceInString(str,100);
  printf("%s\n",str);
}