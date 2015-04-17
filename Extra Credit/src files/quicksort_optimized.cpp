/*
	Filename: prog4.cpp
	Author: Tim Prishtina
	Date: 20 November 2014
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "MicroSecondTimer.h"
#include "quicksort_optimized.h"
#include <algorithm>
using namespace std;

SortDataList::SortDataList()
{
	head = -1;
}

void SortDataList::ClearList()
{
	head = -1;
}

void SortDataList::ReadFile()
{
	int key;
	char strData[5];
	double numData;

	ifstream InFile;

	InFile.open("SortData.txt");

	while(head < NUMRECS-1)
	{
		head++;
		InFile>>key;
		List[head].key = key;
		InFile>>strData;
		strcpy(List[head].strData, strData);
		InFile>>numData;
		List[head].numData = numData;
	}
}

void SortDataList::printList()
{
	int i;

	for(i = 0; i < NUMRECS; i++)
	{
		cout<<List[i].key<<" "<<List[i].strData<<" "<<List[i].numData<<endl;
	}
}

bool SortDataList::listOrdered()
{
	return listOrderedhpr(List);
}

bool SortDataList::listOrderedhpr(SortData List1[])
{
	int i = 0;
	while(i < NUMRECS - 1)
	{
		if(List1[i-1].key > List1[i].key)
			return false;
		i++;
	}
	return true;
}

void SortDataList::QuickSort()
{
	int startIdx = 0;
	int endIdx = 14999;
	QuickSorthpr(List, startIdx, endIdx);
}

void SortDataList::QuickSorthpr(SortData List1[], int startIdx, int endIdx)
{
	int i, j;

	if(startIdx < endIdx)
	{
		i = startIdx;
		j = endIdx;
		Partition(List1, &i, &j);
		QuickSorthpr(List1, startIdx, j);
		QuickSorthpr(List1, i, endIdx);
	}
}

void SortDataList::Partition(SortData List1[], int *I, int *J)
{
	int Pivot;
	SortData temp;
	
	int x = (*I + *J)/2;

	Pivot = List1[x].key;
	do
	{
		while(List1[*I].key < Pivot) (*I)++;

		while(List1[*J].key > Pivot) (*J)--;

		if(*I <= *J)
		{
			temp = List1[*I];
			List1[*I] = List1[*J];
			List1[*J] = temp;
			(*I)++;
			(*J)--;
		}
	
	}
	while(*I <= *J);
}

void SortDataList::QuickSort_Opt()
{
	int startIdx = 0;
	int endIdx = 14999;
	QuickSort_Opthpr(List, startIdx, endIdx);
}

void SortDataList::QuickSort_Opthpr(SortData List1[], int startIdx, int endIdx)
{
	int i, j;

	if(startIdx < endIdx)
	{
		if ((endIdx - startIdx) < 20)
        {
			InsertionSort(List1, startIdx, endIdx + 1);
			return;
        }
		i = startIdx;
		j = endIdx;
		Partition_Opt(List1, &i, &j);
		QuickSort_Opthpr(List1, startIdx, j);
		QuickSort_Opthpr(List1, i, endIdx);
	}
}

void SortDataList::Partition_Opt(SortData List1[], int *I, int *J)
{
	int Pivot;
	SortData temp;
	int x = (*I + *J)/2;
	Pivot = List1[x].key;
	do
	{
		while(List1[*I].key < Pivot) (*I)++;

		while(List1[*J].key > Pivot) (*J)--;

		if(*I <= *J)
		{
			temp = List1[*I];
			List1[*I] = List1[*J];
			List1[*J] = temp;
			(*I)++;
			(*J)--;
		}
	
	}
	while(*I <= *J);
}

void SortDataList::InsertionSort(SortData List1[], int I, int Delta)
{
	for (int x = I + 1; x < Delta; x++)
    {
		SortData temp = List1[x];
        int j = x - 1;
        while (j >= 0 && temp.key < List1[j].key)
        {
			List1[j + 1] = List1[j];
            j--;
        }
        List1[j + 1] = temp;
    }
}
