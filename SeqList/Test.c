#include "SeqList.h"

//��ʼ��
void SeqListInit(SeqList* s)
{
	assert(s);
	s->_array = NULL;
	s->_capacity = 0;
	s->_size = 0;
}

//����
void SeqListDestory(SeqList* s)
{
	assert(s);
	//������鲻Ϊ��
	if (s->_array)
	{
		//���ÿ����ͷ�, �����ָ�������
		s->_array = NULL;
		s->_size = s->_capacity = 0;
		free(s->_array);
	}
}

//��ɾ�Ĳ�

//ͷ��β��
void SeqListPushFront(SeqList* s, Datatype data)
{
	assert(s);
	SeqListCHECK(s);
	//ͷ��
	//������Ԫ�����Ų��һ��, Ȼ���޸��±�Ϊ0��Ԫ��, ����֮��size++
	for (size_t i = s->_size; i > 0; i--)
	{
		s->_array[i] = s->_array[i - 1];
	}
	s->_array[0] = data;
	s->_size++;
}
void SeqListPushBack(SeqList* s, Datatype data)
{
	//ֱ�Ӳ���, size++
	assert(s);
	SeqListCHECK(s);
	s->_array[s->_size++] = data;
}

//����λ�ò���
void SeqListInsert(SeqList* s, size_t pos, Datatype data)
{
	//��pos��ʼ�����Ԫ��ͬһ���Ų��, ��pos������data
	assert(s);
	SeqListCHECK(s);
	for (size_t i = s->_size; i >= pos; i--)
	{
		s->_array[i] = s->_array[i - 1];
	}
	s->_array[pos - 1] = data;
	s->_size++;
}

//�������
void SeqListCHECK(SeqList* s)
{
	assert(s);
	//���size����capacity�˿϶���������, realloc����ռ�
	if (s->_size == s->_capacity)
	{
		size_t newcapacity = s->_capacity == 0 ? 5 : 2 * s->_capacity;
		//����ע�ⲻҪ�����˺����sizeof(Datatype), ���򿪳���ֻ��newcapacity���ֽ�
		//������ʵ���ٵ���newcapacity��Datatype���͵Ŀռ�
		s->_array = (Datatype*)realloc(s->_array, newcapacity * sizeof(Datatype));
		s->_capacity = newcapacity;
	}
}

//ͷɾβɾ
void SeqListPopFront(SeqList* s)
{
	//ֱ�Ӵӵڶ���Ԫ�ؿ�ʼ����ǰŲһ��, ���±�Ϊ0��Ԫ�ظ��ǵ�, size--������
	assert(s);
	for (size_t i = 0; i < s->_size; i++)
	{
		s->_array[i] = s->_array[i + 1];
	}
	s->_size--;
}
void SeqListPopBack(SeqList* s)
{
	//ֱ��size--,���һ��Ԫ�ؾ�û��
	assert(s);
	s->_size--;
}

//����λ��ɾ��
void SeqListErase(SeqList* s, size_t pos)
{
	assert(s);
	//��pos��������ǰŲ��, ��һ�����ǵĹ���, size--
	for (size_t i = pos - 1; i < s->_size; i++)
	{
		s->_array[i] = s->_array[i + 1];
	}
	s->_size--;
}

//ɾ��ֵΪ����data��Ԫ��
void SeqListRemoveAll(SeqList* s, Datatype data)
{
	assert(s);
	size_t index = 0;
	//���Ƿ�
	for (size_t i = 0; i < s->_size; ++i)
	{
		if (s->_array[i] != data)
			s->_array[index++] = s->_array[i];
	}
	s->_size = index;
}

//���ֲ���
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


//ð������
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
		//�п���û���������Ѿ�����, ֱ����ֹ
		if (flag == 0)
			break;
	}
}

//�޸�
void SeqListModify(SeqList* s, size_t pos, Datatype data)
{
	assert(s);
	s->_array[pos - 1] = data;
}

//��ӡ
void SeqListPrint(SeqList* s)
{
	assert(s);
	for (size_t i = 0; i < s->_size; ++i)
	{
		printf("%d  ", s->_array[i]);
	}
	printf("\n");
}

//���ش�С
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
