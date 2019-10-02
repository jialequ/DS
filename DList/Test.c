#include "DList.h"

void test()
{
	DList dl;
	DListInit(&dl);
	DListPushFront1(&dl, 3);
	DListPushFront2(&dl, 2);
	DListPushFront1(&dl, 1);
	DListPushBack1(&dl, 4);
	DListPushBack2(&dl, 5);
	DListPushBack1(&dl, 6);
	DListErase(DListFind(&dl, 6));
	Node* pos = DListFind(&dl, 3);
	DListInsert(pos, 3);
	DListRemove(&dl, 3);
	DListPrint(&dl);
}

int main()
{
	test();
	return 0;	
}
