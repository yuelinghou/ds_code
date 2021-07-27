#pragma once

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

// ֱ�Ӳ�������
void InsertSort(int* a, int n)
{
	// i�����Ѿ��ź�����������һ��Ԫ�ص��±�
	for (int i = 0; i < n - 1; ++i)
	{
		// �ѵ�end+1��λ�õ������뵽ǰ[0,end]������
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


// ϣ������
void ShellSort(int* a, int n)
{
	int gap=n;
	// 1��Ԥ����ֱ��gapΪ1������ֱ�Ӳ�������
	while (gap > 1)
	{
		gap = gap / 3 + 1;// ����+1��֤gap������Ϊ1
		// 2����gapΪ�����ÿһ���������
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			// 3������Ԥ����
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

// ֱ��ѡ������
void SelectSort(int* a, int n)
{
	// ������[begin,end]ѡ�����ĺ���С�ķŵ�����
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
		// ���begin==maxIndex��Ҫ����manIndex���±�
		if (begin == maxIndex)
		{
			maxIndex = minIndex;
		}
		swap(a[end], a[maxIndex]);
		++begin;
		--end;
	}
}

// ������
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
	// 1������
	for (int i = n - 1 - 1 / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	// 2���ѶѶ����ݺ����һ��λ�����ݽ������ӶѶ��������µ����ҵ��δ������
	int end = n - 1;
	for (int i = end; i > 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
	}
}

// ð������
void BubbleSort(int* a, int n)
{
	// 1��i����Ԫ�ظ���
	for (int i = n; i > 1; --i)
	{
		// 2������[0,i-1]λ���ϵ�Ԫ�أ��������ֵ����Ƶ�i-1λ��
		int flag = 1;
		for (int j = 0; j < i-1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				flag = 0;
			}
		}
		// ������һ�鵱ǰ���飬����Ѿ������˾Ͳ��������±�����һ����
		if (flag)
		{
			break;
		}
	}
}

// ��������ݹ�ʵ��
// ����ȡ��
int GetMidIndex(int* a, int left, int right)
{
	// �����м�Ԫ�ص��±�
	int mid = left + (right - left) / 2;
	// ��ķ������������
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

// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
	// ����ȡ�У�ʹkey��Ϊ��ֵ
	int midIndex = GetMidIndex(a, left, right);
	swap(a[midIndex], a[right]);
	int key = a[right];// ��¼key��ֵ
	int rightIndex = right;// ��¼��ǰkey����λ�õ��±�
	// �ҵ�key��ȷ������λ�ã�����ʹ����ߵ���С�ڵ���key���ұߵ������ڴ���key
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
	// ��key��������ȷ��λ��
	swap(a[left], a[rightIndex]);
	// ����key���±�
	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right)
{
	// ����ȡ�У�ʹkey��Ϊ��ֵ
	int midIndex = GetMidIndex(a, left, right);
	swap(a[midIndex], a[right]);
	int key = a[right];// ��¼key��ֵ
	int rightIndex = right;// ��¼��ǰkey����λ�õ��±�
	// �ҵ�key��ȷ������λ�ã�����ʹ����ߵ���С�ڵ���key���ұߵ������ڴ���key
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
	// ��key��������ȷ��λ��
	swap(a[left], a[rightIndex]);
	// ����key���±�
	return left;
}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	// ����ȡ�У�ʹkey��Ϊ��ֵ
	int midIndex = GetMidIndex(a, left, right);
	swap(a[right], a[midIndex]);
	int key = a[right];// ��¼key��ֵ
	int rightIndex = right;// ��¼��ǰkey����λ�õ��±�
	int prev = left - 1;
	int cur = left;
	// �ҵ�key��ȷ������λ�ã�����ʹ����ߵ���С��key���ұߵ������ڴ���key
	while (cur < right)
	{
		if (a[cur] < key && a[++prev] != a[cur])
		{
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	// ��key��������ȷ��λ��
	swap(a[++prev], a[rightIndex]);
	// ����key���±�
	return prev;
}

// ��������
void QuickSort(int* a, int left, int right)
{
	// С�����Ż����ò�������
	if (right - left + 1 > 10)
	{
		// �൱�ڶ�������ǰ�����
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

// ���ŷǵݹ�д��
void QuickSortNonR(int* a, int left, int right)
{
	stack<int> s;
	// �Ȱ�����������±���ջ
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		// �ó�һ�����䣬�������һ��PartSort���ź��м�λ�õ���
		int begin = s.top();
		s.pop();
		int end = s.top();
		s.pop();
		int div = PartSort3(a, begin, end);
		// �����м�λ������������������������Ļ�������������������
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
// 1����������Ѿ�����������������Ĺ鲢
void MergeArray(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int i = begin1;// ���tmp���±�
	// left��right�������������������±�
	int left = begin1;
	int right = end2;
	// ������û����ͼ���
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
	// ����û�����Ų��tmp����
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	// ��tmp���Ѿ��ź�������鸲�ǵ�ԭ����ռ�
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

// �ݹ����
void _MergeSort(int* a, int left, int right, int* tmp)
{
	// ֻ��һ��������û�������Ǿ�ʲô������
	if (left >= right)
	{
		return;
	}
	// �൱�ڶ������ĺ������
	int div = left + (right - left) / 2;
	//[left,div] [div+1,right]
	_MergeSort(a, left, div,tmp);
	_MergeSort(a, div + 1, right, tmp);
	MergeArray(a, left, div, div + 1, right, tmp);
}

// �鲢����
void MergeSort(int* a, int n)
{
	// ����ʵ��tmp�Ĵ��������٣��ݹ����������װһ���ӿ�
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
			// ����Ϊ��λ���й鲢����
			// [i,i+gap-1] [i+gap,i+2*gap-1]
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			// �ڶ��鲻���ڵĻ���break�����棨i��󣩿϶�Ҳ�������ˣ���һ��gap����
			if (begin2 >= n)
			{
				break;
			}
			// �ڶ�������ֻ�в��ֵĻ������µڶ�����±�
			if (end2 >= n)
			{
				end2 = n-1;
			}
			// ����������й鲢
			MergeArray(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	delete[] tmp;
}

void CountSort(int* a, int n)
{
	// 1������ԭ���飬�õ����ֵ����Сֵ
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
	// 2������ԭ���飬�Ѹ��������ֵĴ���ͳ�Ƶ�countArray��
	int range = maxNum - minNum + 1;
	int* countArray = new int[range]();
	for (int i = 0; i < n; ++i)
	{
		++countArray[a[i] - minNum];
	}
	// 3������countArray���飬�Ѷ�Ӧ�±�����ݸ��ǵ�ԭ������
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArray[i]--)
		{
			a[index++] = i + minNum;
		}
	}
}

