#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Datatype;
typedef struct Stack
{
	Datatype* _s;
	size_t _top;
	size_t _capacity;
}Stack;

//初始化
void StackInit(Stack* s);
//销毁
void StackDestory(Stack* s);
//入栈
void StackPush(Stack* s, Datatype x);
//出栈
void StackPop(Stack* s);
//返回栈顶元素
Datatype StackTop(Stack* s);
//判空
size_t StackEmpty(Stack* s);
//返回栈的大小
size_t StackSize(Stack* s);
//打印栈
void StackPrint(Stack* s);
