#include "Seqlist.h"
#include <iostream>
#include <assert.h>

void test1()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);
	list1.prit();

	SeqList list2(list1);
	list2.prit();

	list1.PopBack();
	list1.prit();
}

void test2()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);

	int tmp = list1.Find(1);
	cout << tmp << endl;

	list1.Insert(0, 0);
	list1.prit();

	list1.Erase(0);
	list1.prit();

	list1.Popfront();
	list1.prit();

	list1[0] = 0;
	list1.prit();

}

void test3()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);

	list1.Pushfront(0);
	list1.prit();

	list1.Popfront();
	list1.prit();
}

void test4()
{
	SeqList list1;
	list1.PushBack(1);
	list1.PushBack(2);
	list1.PushBack(3);
	list1.PushBack(4);

	list1[0] = 0;
	list1.prit();

	SeqList list2;
	list2 = list1;
	list2.prit();
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	system("pause");
	return 0;
}