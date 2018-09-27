#include <stdio.h>
#include <iostream>
using namespace std;

struct KDListNode
{
	KDListNode *nextNode;
	int nodeValue;
};

KDListNode *KDlist()
{
	KDListNode *listHead = NULL;
	KDListNode *node = NULL;
	KDListNode *prenode = NULL;
	for (int i = 0; i < 5; ++i)
	{
		node = (KDListNode *)malloc(sizeof(KDListNode));
		node->nodeValue = i;
		node->nextNode = NULL;
		if (i == 0)
		{
			listHead = node;
		}
		if (i != 0)
		{
			prenode->nextNode = node;
		}
		prenode = node;
	}
	return listHead;
}

//第六题 倒序打印链表
void KDPrintListReverse(KDListNode *list)
{
	if (list == NULL)
		return;

	if (list->nextNode != NULL)
	{
		KDPrintListReverse(list->nextNode);
	}
	printf("%d\n",list->nodeValue);
}



int main()
{
   KDListNode *list = KDlist();
   // for (int i = 0; i < 5; ++i)
   // {
   // 		printf("%d\n",list->nodeValue);
   // 		list = list->nextNode;
   // }

   KDPrintListReverse(list);
}