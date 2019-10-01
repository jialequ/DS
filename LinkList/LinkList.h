#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Datatype;
typedef struct ListNode
{
	Datatype _data;
	struct ListNode* _next;
}ListNode;

typedef struct LinkList
{
	ListNode* _head;
}List;


//初始化
void ListInit(List* ls);

//销毁
void ListDestroy(List* ls);

//创建结点
ListNode* BuyListNode(Datatype data);

//头插
void ListPushFront(List* ls, Datatype data);

//头删
void ListPopFront(List* ls);

//尾插
void ListPushBack(List* ls, Datatype data);

//尾删
void ListPopBack(List* plist);

//查找值为data的结点
ListNode* ListFind(List* plist, Datatype data);

//在pos的后面进行插入
void ListInsertAfter(ListNode* pos, Datatype data);


//删除POS后面的第一个结点
void ListEraseAfter(ListNode* pos);

//移除值为data的结点
void ListRemove(List* ls, Datatype data);

//打印
void ListPrint(List* ls);
