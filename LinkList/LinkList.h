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


//��ʼ��
void ListInit(List* ls);

//����
void ListDestroy(List* ls);

//�������
ListNode* BuyListNode(Datatype data);

//ͷ��
void ListPushFront(List* ls, Datatype data);

//ͷɾ
void ListPopFront(List* ls);

//β��
void ListPushBack(List* ls, Datatype data);

//βɾ
void ListPopBack(List* plist);

//����ֵΪdata�Ľ��
ListNode* ListFind(List* plist, Datatype data);

//��pos�ĺ�����в���
void ListInsertAfter(ListNode* pos, Datatype data);


//ɾ��POS����ĵ�һ�����
void ListEraseAfter(ListNode* pos);

//�Ƴ�ֵΪdata�Ľ��
void ListRemove(List* ls, Datatype data);

//��ӡ
void ListPrint(List* ls);
