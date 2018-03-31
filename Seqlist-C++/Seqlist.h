#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>
using namespace std;

typedef int DataType;

class SeqList
{
public:
	SeqList()
		:array(NULL)
		, _size(0)
		, _capacity(0)
	{}

	SeqList(const SeqList& list)
		:array(new DataType[list._capacity])
		, _size(list._size)
		, _capacity(list._capacity)
	{
		memcpy(array, list.array, sizeof(DataType)*list._size);
	}

	void PushBack(DataType x)
	{
		CheckCapcacity();
		array[_size] = x;
		_size++;
	}

	void PopBack()
	{
		assert(array!=NULL);
		_size--;
	}

	void Pushfront(DataType x)
	{
		assert(array != NULL);
		Insert(0, x);
	}

	void Popfront()
	{
		assert(array != NULL);
		Erase(0);
	}

	size_t Find(DataType x)
	{
		assert(array != NULL);
		size_t i = 0;
		while (i<_size)
		{
			if (x==array[i])
			{
				return i;
			}
			i++;
		}
		return -1;
	}

	void Insert(size_t pos, DataType x)
	{
		assert(pos >= 0 && pos <= _size);

		CheckCapcacity();
		int end = _size;
		while (end >= (int)pos)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[pos] = x;
		++_size;
	}

	void Erase(size_t pos)
	{
		assert(pos >= 0 && pos <= _size);
		int end = _size;
		if (_size == 1)
		{
			Clear();
			return;
		}
		while (end >= (int)pos)
		{
			array[pos] = array[pos+1];
			pos++;
		}
		_size--;
	}

	DataType& operator[](size_t pos)
	{
		assert(pos >= 0 && pos <= _size && array != NULL);
		return array[pos];
	}

	SeqList & operator=(const SeqList& list)
	{
		if (this != &list)
		{
			SeqList tmp(list);
			Swap(tmp);
			tmp.Clear();
		}
		return *this;
	}

	void CheckCapcacity()
	{
		if (_size >= _capacity)
		{
			_capacity == 0 ? _capacity += 3 : _capacity *= 2;
			DataType * tmp = new DataType[_capacity];
			memcpy(tmp, array, sizeof(DataType)*_size);
			delete array;
			array = tmp;
		}
	}

	void Swap(SeqList& list)
	{
		array = new DataType[list._capacity];
		memcpy(array, list.array, sizeof(DataType)*list._size);
		_size = list._size;
		_capacity = list._capacity;
	}

	void Clear()
	{
		if (_size != 0)
		{
			delete[] array;
			_size = 0;
			_capacity = 0;
		}
	}

	void prit()
	{
		int i = 0;
		while (i < (int)_size)
		{
			cout << array[i] << " ";
			i++;
		}
		cout << endl;
	}

	~SeqList()
	{
		Clear();
	}

private:
	DataType* array;
	size_t _size;
	size_t _capacity;
};