#include "queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

void QueuePush(Queue* q, Datatype x)
{
	assert(q);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;
	if (q->_rear == NULL)
	{
		//如果队列现在是空的, q->front 和 q->rear 要同时改变
		q->_rear = q->_front = newNode;
	}
	else
	{
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front)
	{
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//如果删除最后一个元素, q->rear也需要变化
		if (q->_front == NULL)
			q->_rear = NULL;
	}
}

Datatype QueueFront(Queue* q)
{
	assert(q);
	if (!QueueEmpty(q))
		return q->_front->_data;
	return -1;
}

Datatype QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_data;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL;
}

int QueueSize(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	int count = 0;
	while (cur)
	{
		++count;
		cur = cur->_next;
	}
	return count;
}

void QueuePrint(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}