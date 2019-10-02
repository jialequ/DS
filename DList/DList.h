#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node
{
	int value;
	struct Node* _next;
	struct Node* _prev;
}Node;

typedef struct DList
{
	Node* _head;
}DList;

void DListInit(DList* dl);
Node* BuyNode(int val);
void DListDestory(DList* dl);
void DListPushBack1(DList* dl, int x);
void DListPushBack2(DList* dl, int x);
void DListPopBack(DList* dl);
void DListPushFront1(DList* dl, int x);
void DListPushFront2(DList* dl, int x);
void DListPopFront(DList* dl);
Node* DListFind(DList* dl, int x);
void DListInsert(Node* pos, int x);
void DListErase(Node* pos);
void DListRemove(DList* dl, int x);
void DListPrint(DList* dl);
