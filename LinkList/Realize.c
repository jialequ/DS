#include "LinkList.h"

//初始化
void ListInit(List* ls)
{
	assert(ls);
	ls->_head = NULL;
}

//销毁
void ListDestroy(List* ls)
{
	assert(ls);
	ListNode* cur = ls->_head;
	ListNode* next;
	while (cur)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	ls->_head = NULL;
}

//创建结点
ListNode* BuyListNode(Datatype data)
{
	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));
	pNode->_data = data;
	pNode->_next = NULL;
	return pNode;
}

//头插
void ListPushFront(List* ls, Datatype data)
{
	assert(ls);
	ListNode* pNode = BuyListNode(data);
	assert(pNode);
	pNode->_next = ls->_head;
	ls->_head = pNode;
}

//头删
void ListPopFront(List* ls)
{
	assert(ls);
	assert(ls->_head);

	ListNode* cur = ls->_head;
	ListNode* next = cur->_next;
	free(cur);
	ls->_head = next;
}

//尾插
void ListPushBack(List* ls, Datatype data)
{
	assert(ls);
	ListNode* cur = ls->_head;
	while (cur->_next)
	{
		cur = cur->_next;
	}
	ListNode* newNode = BuyListNode(data);
	newNode->_data = data;
	newNode->_next = NULL;
	cur->_next = newNode;
}

//尾删
void ListPopBack(List* ls)
{
	assert(ls);
	assert(ls->_head);
	ListNode* cur = ls->_head;
	ListNode* next = cur->_next;
	if (next == NULL)
	{
		ListPopFront(ls);
		return;
	}
	while (next->_next)
	{
		cur = next;
		next = next->_next;
	}
	free(next);
	cur->_next = NULL;
}

//查找值为data的结点
ListNode* ListFind(List* ls, Datatype data)
{
	assert(ls);
	ListNode* cur = ls->_head;
	while (cur)
	{
		if (cur->_data == data)
		{
			printf("exits\n");
			return cur;
		}
		cur = cur->_next;
	}
	printf(" not exits\n");
	return NULL;
}

//在pos的后面进行插入
void ListInsertAfter(ListNode* pos, Datatype data)
{
	assert(pos);
	ListNode* newNode = BuyListNode(data);
	newNode->_next = pos->_next;
	pos->_next = newNode;
}


//删除POS后面的第一个结点
void ListEraseAfter(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	pos->_next = next->_next;
	free(next);
}

//移除值为data的结点
void ListRemove(List* ls, Datatype data)
{
	assert(ls);
	assert(ls->_head);

	while (ls->_head != NULL && ls->_head->_data == data)
	{
		ListPopFront(ls);
	}
	ListNode* cur = ls->_head->_next;
	ListNode* prev = ls->_head;
	for (; cur != NULL; cur = prev->_next)
	{
		if (cur->_data == data)
		{
			prev->_next = cur->_next;
			free(cur);
		}
		else
		{
			prev = cur;
		}
	}
}

//打印
void ListPrint(List* ls)
{
	assert(ls);
	ListNode* cur = ls->_head;
	while (cur)
	{
		printf("%d -> ", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
