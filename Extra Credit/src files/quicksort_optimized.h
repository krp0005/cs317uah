/*
	Filename: prog4list.h
	Author: Tim Prishtina
	Date: 20 November 2014
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "MicroSecondTimer.h"
using namespace std;

#define NUMRECS 15000

#ifndef LIST_H
#define LIST_H

struct SortData
{
	int key;
	char strData[5];
	double numData;
};

class SortDataList
{
	private:
		int head;
		SortData List[NUMRECS];
	public:
		SortDataList();
		void ClearList();
		void ReadFile();
		void printList();
		bool listOrdered();
		bool listOrderedhpr(SortData List1[]);
		void QuickSort();
		void QuickSorthpr(SortData List1[], int startIdx, int endIdx);
		void Partition(SortData List1[], int *I, int *J);
		void QuickSort_Opt();
		void QuickSort_Opthpr(SortData List1[], int startIdx, int endIdx);
		void Partition_Opt(SortData List1[], int *I, int *J);
		void InsertionSort(SortData List1[], int I, int Delta);
};

#endif