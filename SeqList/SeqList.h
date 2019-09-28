#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct SeqList
{
	//定义一个动态的数组
	Datatype* _array;
	//大小
	size_t _size;
	//容量
	size_t _capacity;
}SeqList;

//初始化
void SeqListInit(SeqList* s);
//销毁
void SeqListDestory(SeqList* s);
//检查容量
void SeqListCHECK(SeqList* s);
//增删改查

//头插尾插
void SeqListPushBack(SeqList* s, Datatype data);
void SeqListPushFront(SeqList* s, Datatype data);
//任意位置插入
void SeqListInsert(SeqList* s, size_t pos, Datatype data);

//头删尾删
void SeqListPopFront(SeqList* s);
void SeqListPopBack(SeqList* s);
//任意位置删除
void SeqListErase(SeqList* s, size_t pos);
//删除值为所有data的元素
void SeqListRemoveAll(SeqList* s, Datatype data);

//修改
void SeqListModify(SeqList* s, size_t pos, Datatype data);

//查找
void SeqListFind(SeqList* s, Datatype data);

//打印顺序表
void SeqListPrint(SeqList* s);

//打印大小
void SeqListSize(SeqList* s);

//排序
void SeqListBubbleSort(SeqList* s);
