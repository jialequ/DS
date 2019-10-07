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

//��ʼ��
void StackInit(Stack* s);
//����
void StackDestory(Stack* s);
//��ջ
void StackPush(Stack* s, Datatype x);
//��ջ
void StackPop(Stack* s);
//����ջ��Ԫ��
Datatype StackTop(Stack* s);
//�п�
size_t StackEmpty(Stack* s);
//����ջ�Ĵ�С
size_t StackSize(Stack* s);
//��ӡջ
void StackPrint(Stack* s);
