#include"Seqlist.h"

int main()
{
	SeqList s;
	int ret = 0;
	//Init
	InitSeqList(&s);

	//PushBack
	PushBack(&s, 1);
	PushBack(&s, 8);
	PushBack(&s, 3);
	PushBack(&s, 0);
	PushBack(&s, 9);
	PushBack(&s, 7);
	PushBack(&s, 2);
	PushBack(&s, 4);

	PrintSeqList(&s);

	//Popback
	PopBack(&s);
	PopBack(&s);

	PrintSeqList(&s);

	//PushFront
	PushFront(&s, 0);
	PushFront(&s, 4);

	PrintSeqList(&s);

	//PopFront
	PopFront(&s);
	PopFront(&s);

	PrintSeqList(&s);

	//Insert
	Insert(&s, 2, 1);
	Insert(&s, 4, 6);
	Insert(&s, 6, 2);

	PrintSeqList(&s);

	//Erase
	Erase(&s, 4);

	PrintSeqList(&s);

	//Find
	//ret = Find(&s, 1);
	//printf("%d\n", ret);
	
	//Modify(
	Modify(&s, 4, 6);

	PrintSeqList(&s);

	//Remove
	Remove(&s, 1);

	PrintSeqList(&s);

	//RemoveAll
	RemoveAll(&s, 2);

	PrintSeqList(&s);

	//BubbleSort
	//BubbleSort(&s);

	//PrintSeqList(&s);

	//SelectSort
	//SelectSort(&s);

	//PrintSeqList(&s);

	//SelectSort_OP
	SelectSort_OP(&s);

	PrintSeqList(&s);
	
	//BinarySearch
	ret = BinarySearch(&s, 3);
	printf("\n%d\n", ret);

	system("pause");
	return 0;
}