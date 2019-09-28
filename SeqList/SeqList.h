#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct SeqList
{
	//����һ����̬������
	Datatype* _array;
	//��С
	size_t _size;
	//����
	size_t _capacity;
}SeqList;

//��ʼ��
void SeqListInit(SeqList* s);
//����
void SeqListDestory(SeqList* s);
//�������
void SeqListCHECK(SeqList* s);
//��ɾ�Ĳ�

//ͷ��β��
void SeqListPushBack(SeqList* s, Datatype data);
void SeqListPushFront(SeqList* s, Datatype data);
//����λ�ò���
void SeqListInsert(SeqList* s, size_t pos, Datatype data);

//ͷɾβɾ
void SeqListPopFront(SeqList* s);
void SeqListPopBack(SeqList* s);
//����λ��ɾ��
void SeqListErase(SeqList* s, size_t pos);
//ɾ��ֵΪ����data��Ԫ��
void SeqListRemoveAll(SeqList* s, Datatype data);

//�޸�
void SeqListModify(SeqList* s, size_t pos, Datatype data);

//����
void SeqListFind(SeqList* s, Datatype data);

//��ӡ˳���
void SeqListPrint(SeqList* s);

//��ӡ��С
void SeqListSize(SeqList* s);

//����
void SeqListBubbleSort(SeqList* s);
