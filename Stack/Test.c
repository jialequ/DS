#include "Stack.h"

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPop(&s);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPop(&s);
	StackPush(&s, 5);
	StackPrint(&s);
	StackDestory(&s);
}

int main()
{
	TestStack();
	return 0;	
}
