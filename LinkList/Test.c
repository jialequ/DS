#include "LinkList.h"

void test()
{
	List ls;
	ListInit(&ls);
	ListPushFront(&ls, 2);
	ListPushFront(&ls, 1);
	ListPushBack(&ls, 3);
	ListPushBack(&ls, 4);
	ListPrint(&ls);
	ListPopBack(&ls);
	ListPopBack(&ls);
	ListPrint(&ls);

	ListNode* pos = ListFind(&ls, 2);
	ListInsertAfter(pos, 5);
	ListInsertAfter(pos, 4);
	ListInsertAfter(pos, 3);
	ListInsertAfter(pos, 3);
	ListPrint(&ls);
	ListNode* ret = ListFind(&ls, 5);
	ListInsertAfter(ret, 3);
	ListInsertAfter(ret, 3);
	ListPrint(&ls);
	ListRemove(&ls, 3);
	ListPrint(&ls);
	ListDestroy(&ls);
}
int main()
{
	test();
	system("pause");
	return 0;	
}
