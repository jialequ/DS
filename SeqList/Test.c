#include "SeqList.h"

//初始化
void SeqListInit(SeqList* s)
{
	assert(s);
	s->_array = NULL;
	s->_capacity = 0;
	s->_size = 0;
}

//销毁
void SeqListDestory(SeqList* s)
{
	assert(s);
	//如果数组不为空
	if (s->_array)
	{
		//先置空再释放, 否则空指针解引用
		s->_array = NULL;
		s->_size = s->_capacity = 0;
		free(s->_array);
	}
}

//增删改查

//头插尾插
void SeqListPushFront(SeqList* s, Datatype data)
{
	assert(s);
	SeqListCHECK(s);
	//头插
	//将所有元素向后挪动一次, 然后修改下标为0的元素, 完了之后size++
	for (size_t i = s->_size; i > 0; i--)
	{
		s->_array[i] = s->_array[i - 1];
	}
	s->_array[0] = data;
	s->_size++;
}
void SeqListPushBack(SeqList* s, Datatype data)
{
	//直接插入, size++
	assert(s);
	SeqListCHECK(s);
	s->_array[s->_size++] = data;
}

//任意位置插入
void SeqListInsert(SeqList* s, size_t pos, Datatype data)
{
	//从pos开始往后的元素同一向后挪动, 在pos处插入data
	assert(s);
	SeqListCHECK(s);
	for (size_t i = s->_size; i >= pos; i--)
	{
		s->_array[i] = s->_array[i - 1];
	}
	s->_array[pos - 1] = data;
	s->_size++;
}

//检查容量
void SeqListCHECK(SeqList* s)
{
	assert(s);
	//如果size等于capacity了肯定就是满了, realloc扩大空间
	if (s->_size == s->_capacity)
	{
		size_t newcapacity = s->_capacity == 0 ? 5 : 2 * s->_capacity;
		//这里注意不要忘记了后面的sizeof(Datatype), 否则开出的只是newcapacity个字节
		//我们其实开辟的是newcapacity个Datatype类型的空间
		s->_array = (Datatype*)realloc(s->_array, newcapacity * sizeof(Datatype));
		s->_capacity = newcapacity;
	}
}

//头删尾删
void SeqListPopFront(SeqList* s)
{
	//直接从第二个元素开始都向前挪一次, 将下标为0的元素覆盖掉, size--就行了
	assert(s);
	for (size_t i = 0; i < s->_size; i++)
	{
		s->_array[i] = s->_array[i + 1];
	}
	s->_size--;
}
void SeqListPopBack(SeqList* s)
{
	//直接size--,最后一个元素就没了
	assert(s);
	s->_size--;
}

//任意位置删除
void SeqListErase(SeqList* s, size_t pos)
{
	assert(s);
	//从pos处往后向前挪动, 是一个覆盖的过程, size--
	for (size_t i = pos - 1; i < s->_size; i++)
	{
		s->_array[i] = s->_array[i + 1];
	}
	s->_size--;
}

//删除值为所有data的元素
void SeqListRemoveAll(SeqList* s, Datatype data)
{
	assert(s);
	size_t index = 0;
	//覆盖法
	for (size_t i = 0; i < s->_size; ++i)
	{
		if (s->_array[i] != data)
			s->_array[index++] = s->_array[i];
	}
	s->_size = index;
}

//二分查找
void SeqListFind(SeqList* s, Datatype data)
{
	assert(s);
	int flag = -1;
	size_t left = 0;
	size_t right = s->_size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (s->_array[mid] > data)
			right = mid - 1;
		else if (s->_array[mid] < data)
			left = mid + 1;
		else
		{
			flag = mid;
			break;
		}
	}
	if (flag == -1)
		printf("%d is not exits\n", data);
	else
		printf("%d is exits, number is %d\n", data, flag);
}


//冒泡排序
void SeqListBubbleSort(SeqList* s)
{
	assert(s);
	for (size_t bound = 0; bound < s->_size; ++bound)
	{
		int flag = 0;
		for (size_t i = s->_size - 1; i > bound; --i)
		{
			if (s->_array[i] < s->_array[i - 1])
			{
				flag = 1;
				Datatype ret = s->_array[i];
				s->_array[i] = s->_array[i - 1];
				s->_array[i - 1] = ret;
			}
		}
		//有可能没有排序完已经有序, 直接终止
		if (flag == 0)
			break;
	}
}

//修改
void SeqListModify(SeqList* s, size_t pos, Datatype data)
{
	assert(s);
	s->_array[pos - 1] = data;
}

//打印
void SeqListPrint(SeqList* s)
{
	assert(s);
	for (size_t i = 0; i < s->_size; ++i)
	{
		printf("%d  ", s->_array[i]);
	}
	printf("\n");
}

//返回大小
void SeqListSize(SeqList* s)
{
	assert(s);
	size_t count = 0;
	for (size_t i = 0; i < s->_size; i++)
	{
		count++;
	}
	printf("size is %lu\n", count);
}
