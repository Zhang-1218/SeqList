#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef int DataType;

typedef struct SeqList
{
	DataType array[N]; // 数组
	size_t size;       // 有效数据的个数
}SeqList;

void InitSeqList(SeqList* s);
void PrintSeqList(SeqList* s);
void PushBack(SeqList* s, DataType x);
void PopBack(SeqList* s);
void PushFront(SeqList* s, DataType x);
void PopFront(SeqList* s);
void Insert(SeqList* s, size_t pos, DataType x);
void Erase(SeqList* s, size_t pos);
int Find(SeqList* s, DataType x);
void Modify(SeqList* s, size_t pos, DataType x);
void Remove(SeqList* s, DataType x);
void RemoveAll(SeqList* s, DataType x);
void BubbleSort(SeqList* s);
void SelectSort(SeqList* s);
void SelectSort_OP(SeqList* s);
int BinarySearch(SeqList* s, DataType x);

#endif //__SEQLIST_H__
