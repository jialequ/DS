#include "DList.h"

//初始化
void DListInit(DList* dl)
{
	dl->_head = BuyNode(-1);
	assert(dl);
	dl->_head->_next = dl->_head;
	dl->_head->_prev = dl->_head;
}

//申请一个结点
Node* BuyNode(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	assert(newNode);
	newNode->value = val;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}

//销毁
void DListDestory(DList* dl)
{
	assert(dl);
	Node* cur = dl->_head->_next;
	Node* next = cur->_next;
	for (; cur != dl->_head; cur = next, next = next->_next)
	{
		free(cur);
	}
	free(dl->_head);
	dl->_head = NULL;
}
//头插(1) O(1)
void DListPushFront1(DList* dl, int x)
{
	assert(dl);
	Node* pnode = BuyNode(x);
	Node* next = dl->_head->_next;
	assert(dl);
	pnode->_next = next;
	next->_prev = pnode;

	dl->_head->_next = pnode;
	pnode->_prev = dl->_head;
}

//头插(2)
void DListPushFront2(DList* dl, int x)
{
	DListInsert(dl->_head->_next, x);
}

//头删
void DListPopFront(DList* dl)
{
	Node* next = dl->_head->_next;
	if (next == dl->_head)
		return ;
	dl->_head->_next = next->_next;
	next->_next->_prev = dl->_head;
	free(next);
	next = NULL;
}

//尾插(1)
void DListPushBack1(DList* dl, int x)
{
	assert(dl);
	Node* pnode = BuyNode(x);
	Node* prev = dl->_head->_prev;

	prev->_next = pnode;
	pnode->_prev = prev;
	
	pnode->_next = dl->_head;
	dl->_head->_prev = pnode;
}

//尾插(2)
void DListPushBack2(DList* dl, int x)
{
	DListInsert(dl->_head, x);
}

//尾删
void DListPopBack(DList* dl)
{
	assert(dl);
	Node* prev = dl->_head->_prev;
	if (prev == dl->_head)
		return;
	prev->_prev->_next = dl->_head;
	dl->_head->_prev = prev->_prev;
	free(prev);
	prev = NULL;
}

//随机插入
void DListInsert(Node* pos, int x)
{
	assert(pos);
	Node* pnode = BuyNode(x);
	Node* prev = pos->_prev;

	prev->_next = pnode;
	pnode->_prev = prev;

	pnode->_next = pos;
	pos->_prev = pnode;
}

//随机删除
void DListErase(Node* pos)
{
	assert(pos);
	Node* prev = pos->_prev;
	Node* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

//移除指定value的所有元素
void DListRemove(DList* dl, int x)
{
	assert(dl);
	Node* cur = dl->_head->_next;
	Node* prev = dl->_head;
	for (; cur != dl->_head; cur = prev->_next)
	{
		if (cur->value == x)
			DListErase(cur);
		else
			prev = cur;
	}
}

//查找
Node* DListFind(DList* dl, int x)
{
	assert(dl);
	Node* cur = dl->_head->_next;
	while (cur != dl->_head)
	{
		if (cur->value == x)
		{
			printf("%d is exist!!!\n", x);
			return cur;
		}
		cur = cur->_next;
	}
	printf("%d is not exits!!!\n", x);
	return NULL;
}

//打印
void DListPrint(DList* dl)
{
	assert(dl);
	Node* cur = dl->_head->_next;
	while (cur != dl->_head)
	{
		if (cur->_next == dl->_head)
		{
			printf("%d\n", cur->value);
			return;
		}
		printf("%d <=> ", cur->value);
		cur = cur->_next;
	}
	printf("\n");
}
