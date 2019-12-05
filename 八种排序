#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//1. 直接插入排序
void InsertSort(vector<int>& v, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		//单个元素的排序
		int end = i;
		int tmp = v[end + 1];
		while (end >= 0 && v[end] > tmp)
		{
			v[end + 1] = v[end];
			--end;
		}
		v[end + 1] = tmp;
	}
}

//2. 希尔排序: 对插排进行优化, 先预排序
void ShellSort(vector<int>& v, int size)
{
	int gap = size;
	while (gap > 1)
	{
		//gap > 1 : 预排序
		//gap == 1 : 排序过程
		//+1 保证最后一次是一个间隔为1的插入排序
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; ++i)
		{
			int end = i;
			int tmp = v[end + gap];
			while (end >= 0 && v[end] > tmp)
			{
				v[end + gap] = v[end];
				end -= gap;
			}
			v[end + gap] = tmp;
		}
	}
}

//3. 直接选择排序
void SelectSort1(vector<int>& v, int size)
{
	//每次选一个最小的
	for (int i = 0; i < size; ++i)
	{
		//保存最小元素的下标
		int Min = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (v[j] < v[Min])
				Min = j;
		}
		//将元素放在指定位置
		swap(v[i], v[Min]);
	}
}

void SelectSort2(vector<int>& v, int size)
{
	//每次选择一个最大一个最小, 放到相应位置
	int begin = 0;
	int end = size - 1;
	while (begin < end)
	{
		int Max, Min;
		Max = Min = begin;
		//小的选第一个, 大的选最后一个, 就稳定了, 相同的元素位置不会发生变化
		for (int i = begin; i <= end; ++i)
		{
			if (v[i] < v[Min])
				Min = i;
			if (v[i] >= v[Max])
				Max = i;
		}
		swap(v[begin], v[Min]);
		//判断最大元素的位置是否发生了变化, 如果变化了, 就是被交换了, 让下标指向被交换的地方
		if (Max == begin)
			Max = Min;
		swap(v[end], v[Max]);
		++begin;
		--end;
	}
}

void SelectSort3(vector<int>& v, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (v[i] > v[j])
				swap(v[i], v[j]);
		}
	}
}

//4. 堆排序
//建堆: O(n)
void ShiftDown(vector<int>& v, int size, int root)
{
	int parent = root;
	int child = 2 * root + 1;
	//判断是否有孩子
	while (child < size)
	{
		//是否有右孩子, 如果有, 选最大
		if (child + 1 < size && v[child] < v[child + 1])
		{
			++child;
		}
		//孩子是否大于父亲
		if (v[child] > v[parent])
		{
			//交换孩子和父亲
			swap(v[child], v[parent]);
			//更新下一个调整的位置
			parent = child;
			child = 2 * child + 1;
		}
		else
			break;
	}
}
//排序: O(n * logn)
void HeapSort(vector<int>& v, int size)
{
	//建堆, 最后一棵子树开始 : (n - 2) / 2
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		ShiftDown(v, size, i);
	}
	//排序: 1. swap  2. ShiftDown
	int end = size - 1;
	while (end)
	{
		swap(v[0], v[end]);
		ShiftDown(v, end, 0);
		--end;
	}
}

//5. 冒泡排序

void BubbleSort_1(vector<int>& v, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j > i; --j)
		{
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
		}
	}
}
//优化一, 加上flag, 如果一次遍历没有发生任何交换, 那就是已经有序了, 排序完成
void BubbleSort_2(vector<int>& v, int size)
{
	for (int i = 0; i < size; ++i)
	{
		bool flag = false;
		for (int j = size - 1; j > i; --j)
		{
			if (v[j] < v[j - 1])
			{
				swap(v[j], v[j - 1]);
				flag = true;
			}
		}
		if (!flag)
			break;
	}
}

//优化二, 增加一个标记, 标记交换的后一个下标, 如果刚开始有: 7,6,4,3,10,11,12,13,14这种情况, 可以减少遍历次数
void BubbleSort_3(vector<int>& v, int size)
{
	for (int i = size; i > 0;)
	{
		int index = 0;
		for (int j = 1; j < i; ++j)
		{
			if (v[j] < v[j - 1])
			{
				swap(v[j], v[j - 1]);
				index = j;
			}
		}
		i = index;
	}
}

void BubbleSort_4(vector<int>& v, int size)
{
	for (int i = size; i > 0; --i)
	{
		for (int j = 1; j < i; ++j)
		{
			if (v[j] < v[j - 1])
				swap(v[j], v[j - 1]);
		}
	}
}

//快速排序
int Partition_1(vector<int>& v, int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = v[right];

	while (begin < end)
	{
		while (begin < end && v[begin] <= pivot)
		{
			begin++;
		}
		//出来说明v[begin] > pivot
		while (begin < end && v[end] >= pivot)
		{
			end--;
		}
		//停下来说明v[end] < pivot

		swap(v[begin], v[end]);
	}

	//把基准值和begin所在的下标交换, 和第一个比pivot大的数交换
	swap(v[begin], v[right]);
	return begin;

}

void QuickSortRecursion(vector<int>& v, int left, int right)
{
	//直到size == 0 || size == 1
	//left > right : 0, left == right : 1.
	if (left >= right)
		return;

	//1. 确定基准值, 目前选最右边
	//2. 遍历区间, 进行切割, 直到小的在左边, 大的在右边
	int index = Partition_1(v, left, right);
	QuickSortRecursion(v, left, index - 1);
	QuickSortRecursion(v, index + 1, right);
}

void QuickSort(vector<int>& v, int size)
{
	QuickSortRecursion(v, 0, size - 1);
}

void Print(vector<int> v)
{
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void TestSort()
{
	srand(time(NULL));
	int num;
	cin >> num;
	vector<int> v(num);
	for (int i = 0; i < num; ++i)
	{
		v[i] = rand();
	}
	vector<int> v1 = v;
	vector<int> v2 = v;
	vector<int> v3 = v;
	vector<int> v4 = v;
	vector<int> v5 = v;
	vector<int> v21 = v;
	vector<int> v23 = v;
	vector<int> v6 = v;
	vector<int> v7 = v;
	vector<int> v8 = v;
	size_t begin1, end1, begin2, end2, begin21, end21, begin23, end23;
	size_t begin3, end3, begin4, end4, begin5, end5;

	//begin3 = clock();
	//InsertSort(v3, v3.size());
	//end3 = clock();
	//cout << "InsertSort: " << end3 - begin3 << endl;

	begin4 = clock();
	ShellSort(v4, v4.size());
	end4 = clock();
	cout << "ShellSort: " << end4 - begin4 << endl;

	//begin2 = clock();
	//SelectSort2(v2, v2.size());
	//end2 = clock();
	//cout << "SelectSort2: " << end2 - begin2 << endl;

	//begin21 = clock();
	//SelectSort1(v21, v21.size());
	//end21 = clock();
	//cout << "SelectSort1: " << end21 - begin21 << endl;

	//begin23 = clock();
	//SelectSort3(v23, v23.size());
	//end23 = clock();
	//cout << "SelectSort3: " << end23 - begin23 << endl;

	//begin1 = clock();
	//HeapSort(v1, v1.size());
	//end1 = clock();
	//cout << "HeapSort: " << end1 - begin1 << endl;



	begin5 = clock();
	BubbleSort_1(v5, v5.size());
	end5 = clock();
	cout << "BubbleSort_1: " << end5 - begin5 << endl;

	begin5 = clock();
	BubbleSort_2(v6, v6.size());
	end5 = clock();
	cout << "BubbleSort_2: " << end5 - begin5 << endl;

	begin5 = clock();
	BubbleSort_3(v7, v7.size());
	end5 = clock();
	cout << "BubbleSort_3: " << end5 - begin5 << endl;
}


int main()
{
	vector<int> v{ 3, 2, 1, 8, 5, 4, 7, 9, 6, 0 };
	Print(v);
	//BubbleSort_1(v, v.size());
	//BubbleSort_2(v, v.size());
	//BubbleSort_3(v, v.size());
	BubbleSort_4(v, v.size());
	//QuickSort(v, v.size());
	Print(v);

	//TestSort();
    system("pause");
	return 0;	
}
