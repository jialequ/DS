#include "SeqList.h"

void test()
{
	SeqList s;
	//初始化
	SeqListInit(&s);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 3);
	SeqListPushFront(&s, 0);
	SeqListInsert(&s, 3, 5);
	SeqListInsert(&s, 3, 2);
	SeqListInsert(&s, 3, 6);
	SeqListInsert(&s, 3, 1);
	//排序
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	//删除
	SeqListErase(&s, 5);
	SeqListPrint(&s);
	//插入两个5, 然后RemoveAll
	SeqListInsert(&s, 5, 5);
	SeqListInsert(&s, 7, 5);
	SeqListPrint(&s);
	SeqListRemoveAll(&s, 5);
	SeqListPrint(&s);
	//查找
	SeqListFind(&s, 7);
	//销毁
	SeqListDestory(&s);
}
int main()
{
	test();
	return 0;
}
