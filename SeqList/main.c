#include "SeqList.h"

void test()
{
	SeqList s;
	//��ʼ��
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
	//����
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	//ɾ��
	SeqListErase(&s, 5);
	SeqListPrint(&s);
	//��������5, Ȼ��RemoveAll
	SeqListInsert(&s, 5, 5);
	SeqListInsert(&s, 7, 5);
	SeqListPrint(&s);
	SeqListRemoveAll(&s, 5);
	SeqListPrint(&s);
	//����
	SeqListFind(&s, 7);
	//����
	SeqListDestory(&s);
}
int main()
{
	test();
	return 0;
}
