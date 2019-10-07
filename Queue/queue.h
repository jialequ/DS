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

//��ʼ��
void QueueInit(Queue* q);
//����
void QueueDestory(Queue* q);
//�������
QueueNode* BuyQueueNode(Datatype x);
//���
void QueuePush(Queue* q, Datatype x);
//����
void QueuePop(Queue* q);
//��ȡ��ͷԪ��
Datatype QueueFront(Queue* q);
//��ȡ��βԪ��
Datatype QueueBack(Queue* q);
//�п�
int QueueEmpty(Queue* q);
//�жϴ�С
int QueueSize(Queue* q);
//��ӡ����
void QueuePrint(Queue* q);
