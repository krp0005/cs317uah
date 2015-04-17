/*
	Filename: main.cpp
	Author: Tim Prishtina
	Date: 20 November 2014
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "MicroSecondTimer.h"
#include "quicksort_optimized.h"
using namespace std;

int main(void)
{
	int choice = 0;
	SortDataList sortobj;

	double run1, run2;

	MicroSecondTimer timer;

	sortobj.ReadFile();

	printf("Welcome to sort algorithm exploration. We will compare\n");
	printf("different sorting algorithms for speed and complexity here.\n");

	while(choice != -1)
	{
		printf("Please enter a choice from the menu below.(-1 to end)\n");
		printf("1. QuickSort\n");
		printf("2. QuickSort Optimized\n");
		printf("3. Clear List\n");
		printf("4. Print List\n");
		printf(">");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1: timer.Start();
				sortobj.QuickSort();
				timer.Stop();
				run1 = timer.getTime();
				printf("Runtime is: %lf\n", run1);
				if(sortobj.listOrdered() == true)
					cout<<"List is ordered.\n";
				else
					cout<<"List is not ordered properly.\n";
				break;
			case 2: timer.Start();
				sortobj.QuickSort_Opt();
				timer.Stop();
				run2 = timer.getTime();
				printf("Runtime is: %lf\n", run2);
				if(sortobj.listOrdered() == true)
					cout<<"List is ordered.\n";
				else
					cout<<"List is not ordered properly.\n";
				break;
			case 3: sortobj.ClearList();
					sortobj.ReadFile();
					if(sortobj.listOrdered() == true)
					cout<<"List is ordered.\n";
				else
					cout<<"List is not ordered properly.\n";
				break;
			case 4: sortobj.printList();
				break;
		}
	}
	return 0;
}
