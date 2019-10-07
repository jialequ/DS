#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int Datatype;
typedef struct QueueNode
{
	Datatype _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* _front;
	struct QueueNode* _rear;
}Queue;

//初始化
void QueueInit(Queue* q);
//销毁
void QueueDestory(Queue* q);
//创建结点
QueueNode* BuyQueueNode(Datatype x);
//入队
void QueuePush(Queue* q, Datatype x);
//出队
void QueuePop(Queue* q);
//获取队头元素
Datatype QueueFront(Queue* q);
//获取队尾元素
Datatype QueueBack(Queue* q);
//判空
int QueueEmpty(Queue* q);
//判断大小
int QueueSize(Queue* q);
//打印队列
void QueuePrint(Queue* q);
