#include"Seqlist.h"

void InitSeqList(SeqList* s)
{
	assert(s);
	memset(s, 0, sizeof(DataType)*N);
	s->size = 0;
}

void PrintSeqList(SeqList* s)
{
	size_t i = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	for (i = 0; i < s->size; i++)
	{
		printf("%d ", s->array[i]);
	}
	printf("\n");
}

void PushBack(SeqList* s, DataType x)
{
	assert(s);
	if (s->size == N)
	{
		perror("SeqList is full\n");
		return;
	}

	s->array[s->size] = x;
	s->size++;
}

void PopBack(SeqList* s)
{
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	s->size--;
}

void PushFront(SeqList* s, DataType x)
{
	size_t i = 0;
	assert(s);
	if (s->size == N)
	{
		perror("SeqList is full\n");
		return;
	}

	for (i = 0; i < s->size; i++)
	{
		s->array[s->size - i] = s->array[s->size - i - 1];
	}

	s->array[0] = x;
	s->size++;
}

void PopFront(SeqList* s)
{
	size_t i = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	for (i = 0; i < s->size-1; i++)
	{
		s->array[i] = s->array[i + 1];
	}

	s->size--;
}

void Insert(SeqList* s, size_t pos, DataType x)
{
	size_t i = pos;
	assert(s);
	assert(pos >= 0 && pos <= s->size - 1);
	if (s->size == N)
	{
		perror("SeqList is full\n");
		return;
	}
	
	for (i = s->size-1; i >= pos; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = x;
	s->size++;
}

void Erase(SeqList* s, size_t pos)
{
	size_t i = 0;
	assert(s);
	assert(pos >= 0 && pos <= s->size - 1);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	for (i = pos; i < s->size - 1; i++)
	{
		s->array[i] = s->array[i + 1];
	}
	s->size--;
}

int Find(SeqList* s, DataType x)
{
	int i = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	for (i = 0; i < s->size; i++)
	{
		if (s->array[i] == x)
		{
			return i;
		}
	}
	printf("Find failed\n");
	return -1;
}

void Modify(SeqList* s, size_t pos, DataType x)
{
	int i = 0;
	assert(s);
	assert(pos >= 0 && pos <= s->size - 1);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	s->array[pos] = x;
}

void Remove(SeqList* s, DataType x)
{
	size_t i = 0;
	size_t j = 0;
	DataType pos;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	////利用查找函数和擦除函数进行删除
	pos = Find(s, x);
	if (pos == -1)
	{
		return;
	}
	else if (pos != -1)
	{
		Erase(s, pos);
	}

	//利用for循环来进行删除
	//for (i = 0; i < s->size; i++)
	//{
	//	if (s->array[i] == x)
	//	{
	//		for (j = i; j < s->size - 1; j++)
	//		{
	//			s->array[j] = s->array[j + 1];
	//		}
	//		s->size--;
	//		break;
	//	}
	//}
}

void RemoveAll(SeqList* s, DataType x)
{
	DataType i = 0;
	DataType j = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	while (i < s->size)
	{
		if (s->array[i] != x)
		{
			s->array[j] = s->array[i];
			j++;
		}
		i++;
	}
	s->size = j;

	//for (i = 0; i < s->size; i++)
	//{
	//	if (s->array[i] == x)
	//	{
	//		for (j = i; j < s->size - 1; j++)
	//		{
	//			s->array[j] = s->array[j + 1];
	//		}
	//		s->size--;
	//	}
	//}
}


void Swap(DataType *left, DataType *right)
{
	DataType temp = *left;
	*left = *right;
	*right = temp;
}

void BubbleSort(SeqList* s)
{
	size_t i = 0;
	size_t j = 0;
	int flag = 0;
	DataType temp = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList is empty\n");
		return;
	}

	for (i = 0; i < s->size; i++)
	{
		flag = 0;
		for (j = 0; j < s->size - i - 1; j++)
		{
			if (s->array[j] > s->array[j + 1])
			{
				Swap(s->array + j, s->array + j + 1);
				flag = 1;
			}	
		}
		if (flag == 0)
		{
			break;
		}
	}
}

void SelectSort(SeqList* s)
{
	size_t i = 0;
	size_t j = 0;
	size_t min = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList if empty\n");
		return;
	}

	for (i = 0; i < s->size; i++)
	{
		min = i;
		for (j = i; j<s->size; j++)
		{
			if (s->array[min]>s->array[j])
			{
				min = j;
			}
		}
		Swap(s->array + i, s->array + min);
	}
}

void SelectSort_OP(SeqList* s)
{
	size_t i = 0;
	size_t j = 0;
	size_t min = 0;
	size_t max = 0;
	size_t start = 0;
	size_t end = 0;
	assert(s);
	if (s->size == 0)
	{
		perror("SeqList if empty\n");
		return;
	}

	for (start = 0, end = s->size-1; start < end; start++, end--)
	{
		min = start;
		max = end;
		for (i = start; i <= end; i++)
		{
			if (s->array[min] > s->array[i])
			{
				min = i;
			}
			if (s->array[max] < s->array[i])
			{
				max = i;
			}
		}
		Swap(s->array + start, s->array + min);
		if (start == max)
		{
			max = min;
		}
		Swap(s->array + end, s->array + max);
	}
}

int BinarySearch(SeqList* s, DataType x)
{
	size_t left = 0;
	size_t right = s->size - 1;
	size_t mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (s->array[mid] > x)
		{
			right = mid - 1;
		}
		else if (s->array[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
}
