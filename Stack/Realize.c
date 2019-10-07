#include "Stack.h"

void StackInit(Stack* s)
{
	assert(s);
	//空栈
	s->_s = NULL;
	s->_top = 0;
	s->_capacity = 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	if (s->_s)
	{
		s->_s = NULL;
		s->_top = s->_capacity = 0;
		free(s->_s);
	}
}

void StackPush(Stack* s, Datatype x)
{
	assert(s);
	///入栈:顺序表尾插
	//检查容量
	if (s->_top == s->_capacity)
	{
		size_t newcapacity = s->_capacity == 0 ? 10 : 2 * s->_capacity;
		//realloc不需要自行拷贝原有空间内容
		s->_s = (Datatype*)realloc(s->_s, newcapacity * sizeof(Datatype));
		s->_capacity = newcapacity;
	}
	s->_s[s->_top++] = x;
}

void StackPop(Stack* s)
{
	assert(s);
	//尾删
	if (s->_top > 0)
		--s->_top;
}

Datatype StackTop(Stack* s)
{
	assert(s);
	return s->_s[s->_top - 1];
}

size_t StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0 ? 1 : 0;
}

size_t StackSize(Stack* s)
{
	return s->_top;
}

void StackPrint(Stack* s)
{
	assert(s);
	while (!StackEmpty(s))
	{
		printf("%d ", StackTop(s));
		StackPop(s);
	}
	printf("\n");
}
