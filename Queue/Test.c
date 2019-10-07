#include "queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePrint(&q);
	Datatype cur = QueueFront(&q);
	printf("front is %d\n", cur);
	cur = QueueBack(&q);
	printf("back is %d\n", cur);
	printf("size is %d\n", QueueSize(&q));
	QueuePop(&q);
	QueuePrint(&q);
	printf("size is %d\n", QueueSize(&q));
	QueueDestory(&q);
}

int main()
{
	TestQueue();
	return 0;	
}
