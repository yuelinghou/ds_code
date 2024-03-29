#pragma once

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

// 直接插入排序
void InsertSort(int* a, int n)
{
	// i代表已经排好序数组的最后一个元素的下标
	for (int i = 0; i < n - 1; ++i)
	{
		// 把第end+1个位置的数插入到前[0,end]的数中
		int end=i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}


// 希尔排序
void ShellSort(int* a, int n)
{
	int gap=n;
	// 1、预排序，直到gap为1，就是直接插入排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;// 最后的+1保证gap最后可以为1
		// 2、对gap为间隔的每一组进行排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			// 3、单次预排序
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

// 直接选择排序
void SelectSort(int* a, int n)
{
	// 从区间[begin,end]选出最大的和最小的放到两端
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxIndex = begin;
		int minIndex = begin;
		for (int i = begin+1; i <= end; ++i)
		{
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}
		swap(a[begin], a[minIndex]);
		// 如果begin==maxIndex就要更新manIndex的下标
		if (begin == maxIndex)
		{
			maxIndex = minIndex;
		}
		swap(a[end], a[maxIndex]);
		++begin;
		--end;
	}
}

// 堆排序
void AdjustDown(int* a, int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}

		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
		}
		else
		{
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

void HeapSort(int* a, int n)
{
	// 1、建堆
	for (int i = n - 1 - 1 / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	// 2、把堆顶数据和最后一个位置数据交换，从堆顶继续向下调整找到次大的数据
	int end = n - 1;
	for (int i = end; i > 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	// 1、i代表元素个数
	for (int i = n; i > 1; --i)
	{
		// 2、调整[0,i-1]位置上的元素，把其最大值最后移到i-1位置
		int flag = 1;
		for (int j = 0; j < i-1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 0;
			}
		}
		// 遍历完一遍当前数组，如果已经有序了就不用再往下遍历下一组了
		if (flag)
		{
			break;
		}
	}
}

// 快速排序递归实现
// 三数取中
int GetMidIndex(int* a, int left, int right)
{
	// 数组中间元素的下标
	int mid = left + (right - left) / 2;
	// 大的分两类情况处理
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[right] < a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[right] > a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	// 三数取中，使key不为最值
	int midIndex = GetMidIndex(a, left, right);
	swap(a[midIndex], a[right]);
	int key = a[right];// 记录key的值
	int rightIndex = right;// 记录当前key所在位置的下标
	// 找到key正确的排序位置，并且使得左边的数小于等于key，右边的数大于大于key
	while (left < right)
	{
		while (left < right&&a[left] <= key)
		{
			++left;
		}
		while (left < right&&a[right] >= key)
		{
			--right;
		}
		swap(a[left], a[right]);
	}
	// 把key交换到正确地位置
	swap(a[left], a[rightIndex]);
	// 返回key的下标
	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	// 三数取中，使key不为最值
	int midIndex = GetMidIndex(a, left, right);
	swap(a[midIndex], a[right]);
	int key = a[right];// 记录key的值
	int rightIndex = right;// 记录当前key所在位置的下标
	// 找到key正确的排序位置，并且使得左边的数小于等于key，右边的数大于大于key
	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			++left;
		}
		swap(a[left], a[right]);
		while (left < right && a[right]>=key)
		{
			--right;
		}
		swap(a[left], a[right]);
	}
	// 把key交换到正确地位置
	swap(a[left], a[rightIndex]);
	// 返回key的下标
	return left;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	// 三数取中，使key不为最值
	int midIndex = GetMidIndex(a, left, right);
	swap(a[right], a[midIndex]);
	int key = a[right];// 记录key的值
	int rightIndex = right;// 记录当前key所在位置的下标
	int prev = left - 1;
	int cur = left;
	// 找到key正确的排序位置，并且使得左边的数小于key，右边的数大于大于key
	while (cur < right)
	{
		if (a[cur] < key && a[++prev] != a[cur])
		{
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	// 把key交换到正确地位置
	swap(a[++prev], a[rightIndex]);
	// 返回key的下标
	return prev;
}

// 快速排序
void QuickSort(int* a, int left, int right)
{
	// 小区间优化，用插入排序
	if (right - left + 1 > 10)
	{
		// 相当于二叉树的前序遍历
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

// 快排非递归写法
void QuickSortNonR(int* a, int left, int right)
{
	stack<int> s;
	// 先把整个区间的下标入栈
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		// 拿出一个区间，对其进行一次PartSort，排好中间位置的数
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		int div = PartSort3(a, begin, end);
		// 对于中间位置这个数，如果还有左右区间的话继续入他的左右区间
		if (div+1<end)
		{
			s.push(end);
			s.push(div+1);
		}
		if (begin < div - 1)
		{
			s.push(div - 1);
			s.push(begin);
		}
	}
}
// 1、完成两个已经有序并且连续的数组的归并
void MergeArray(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int i = begin1;// 标记tmp的下标
	// left和right代表整个数组的区间的下标
	int left = begin1;
	int right = end2;
	// 两个都没走完就继续
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	// 最终没走完的挪到tmp后面
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	// 把tmp上已经排好序的数组覆盖到原数组空间
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

// 递归操作
void _MergeSort(int* a, int left, int right, int* tmp)
{
	// 只有一个数或者没有数，那就什么都不干
	if (left >= right)
	{
		return;
	}
	// 相当于二叉树的后序遍历
	int div = left + (right - left) / 2;
	//[left,div] [div+1,right]
	_MergeSort(a, left, div,tmp);
	_MergeSort(a, div + 1, right, tmp);
	MergeArray(a, left, div, div + 1, right, tmp);
}

// 归并排序
void MergeSort(int* a, int n)
{
	// 这里实现tmp的创建和销毁，递归操作单独封装一个接口
	int* tmp = new int[n];
	_MergeSort(a, 0, n - 1, tmp);
	delete[] tmp;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = new int[n];
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2*gap)
		{
			// 两组为单位进行归并操作
			// [i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			// 第二组不存在的话就break，后面（i变大）肯定也不存在了，下一个gap继续
			if (begin2 >= n)
			{
				break;
			}
			// 第二组区间只有部分的话，更新第二组的下标
			if (end2 >= n)
			{
				end2 = n-1;
			}
			// 对这两组进行归并
			MergeArray(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	delete[] tmp;
}

void CountSort(int* a, int n)
{
	// 1、遍历原数组，得到最大值和最小值
	int maxNum = a[0];
	int minNum = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < minNum)
		{
			minNum = a[i];
		}

		if (a[i] > maxNum)
		{
			maxNum = a[i];
		}
	}
	// 2、遍历原数组，把各个数出现的次数统计到countArray中
	int range = maxNum - minNum + 1;
	int* countArray = new int[range]();
	for (int i = 0; i < n; ++i)
	{
		++countArray[a[i] - minNum];
	}
	// 3、遍历countArray数组，把对应下标的数据覆盖到原数组中
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArray[i]--)
		{
			a[index++] = i + minNum;
		}
	}
}

