//Problems: empty array is thorwing errors in the cases
//cout issues had to use std::cout
//Missing:coutingand radix arrays
//check the time not modified

#include "algorithms.h"
#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace std::chrono;

//void arrayInfo(int arr[], int size);
//void fillSorted(int a[], int size);
//void fillHalfsorted(int a[], int size);
//void fillReverse(int a[], int size);
//void fillRandom(int a[], int size);
//void print(int a[], int n);
// 

//****************************SORTED ARRAY***************************//
void fillSorted(int a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i] = i + 1;
	}
	return;
}
// ***************************HALF SORTED ARRAY**********************//
void fillHalfsorted(int a[], int size) {
	int g = size;
	for (int i = 0; i < size; i++) {
		if (i < size / 2) {
			a[i] = i + 1;
		}
		else {
			a[i] = g;
			g--;
		}
	}
	return;
}
//****************************REVERSE ARRAY**************************//
void fillReverse(int a[], int n) { // (pass an unitialized array, pass the size wanted)
	int g = n;
	for (int i = 0; i < n; i++) {
		a[i] = g;
		g--;
	}
	return; // lets say n = 10, array output: [10,9,8,7,6,5,4,3,2,1]
}
//****************************RANDOM ARRAY***************************//
int* fillRandom(int* arr, int size)//worst case
{
	srand(time(NULL));
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % size + 1;
	}
	printUnsortedarry(arr, size);
	return arr;
}
void prntArr(int arr[], int start, int end) {
	for (int i = start; i < end; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\nStart: " << start << " End: " << end << endl;

}
void printUnsortedarry(int arr[], int size)
{
	for (int i = 0; i < 20; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "........";
	for (int i = size - 20; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << endl;
}
void printArr(int* arr, int start, int end) {

	std::cout << "Start: " << start << " End: " << endl;
	while (start < end) {
		std::cout << arr[start++] << " ";
		if (start % 50 == 0) std::cout << "\n";
	}
	std::cout << endl;
}

void printResults(string functionName, double runTime, int* arr, int start, int end) {
	std::cout << "Algorithm: " << functionName << endl;
	printArr(arr, start, end);
	std::cout << "Run Time: " << runTime << endl;
}

void setArrElements(int* arr, int size, int seed) {

	srand(seed);
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size + 1;
	}
}

//*******************CHECK THE TIME************************//
void getRunTime(int choice, int* arr, int start, int end) {

	cin >> choice;
	int sorted[20];
	int sortedSize = sizeof(sorted) / sizeof(sorted[0]);
	//fillSorted(sorted, sortedSize);

	int halfsorted[20];
	int halfSortedSize = sizeof(halfsorted) / sizeof(halfsorted[0]);
	//fillHalfsorted(halfsorted, halfSortedSize);

	int reverse[20];
	int reverseSize = sizeof(reverse) / sizeof(reverse[0]);
	fillReverse(reverse, reverseSize);

	int random[20];
	int randomSize = sizeof(random) / sizeof(random[0]);
	fillRandom(random, randomSize);
	printArr(random,0, randomSize);
	std::cout << endl;
	//get start start time
	time_point < system_clock > s, e;
	s = system_clock::now();
	switch (choice) {
		int size = 10;
		int empty[size] = { 0 };
		std::cout << "Choose 1 - 7" << endl;
		std::cout << "Choice 1: Insertion Sort Worst Case" << endl;
		std::cout << "Choice 2: Insertion Sort Average Case" << endl;
		std::cout << "Choice 3: Insertion Sort Best Case" << endl;
		std::cout << "Choice 4: Merge Sort Worst/Average/Best Cases" << endl;
		std::cout << "Choice 5: ?" << endl;
		std::cout << "Choice 6: ?" << endl;
		std::cout << "Choice 7: ?" << endl;
		std::cout << "user>> ";
		cin >> choice;
		std::cout << endl;
	case 1:
		std::cout << "Choice 1: Insertion Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		InsertionSort(sorted, sizeof(sorted[0]));
	case 2:
		std::cout << "Choice 2: Insertion Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		InsertionSort(halfsorted, sizeof(halfsorted[0]));
	case 3:
		std::cout << "Choice 3: Insertion Sort on Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		InsertionSort(reverse, sizeof(reverse[0]));
	case 4:
		std::cout << "Choice 4: Insertion Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		InsertionSort(random, sizeof(random[0]));
	case 5:
		std::cout << "Choice 5: Selection Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		selectionSort(sorted);
	case 6:
		std::cout << "Choice 6: Selection Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		selectionSort(halfsorted);
	case 7:
		std::cout << "Choice 7: Selection Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		selectionSort(reverse);
	case 8:
		std::cout << "Choice 8: Selection Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		selectionSort(random);
	case 9:
		std::cout << "Choice 9: Bubble Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		BubbleSort(sorted, sizeof(sorted[0]));
	case 10:
		std::cout << "Choice 10: Bubble Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		BubbleSort(halfsorted, sizeof(halfsorted[0]));
	case 11:
		std::cout << "Choice 11: Bubble Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		BubbleSort(reverse, sizeof(reverse[0]));
	case 12:
		std::cout << "Choice 12: Bubble Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		BubbleSort(random, sizeof(random));
	case 13:
		std::cout << "Choice 13: Merge Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		mergeSort(sorted, 0, sizeof(sorted[0]));
	case 14:
		std::cout << "Choice 14: Merge Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		mergeSort(halfsorted, 0, sizeof(halfsorted[0]));
	case 15:
		std::cout << "Choice 15: Merge Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		mergeSort(reverse, 0, sizeof(reverse[0]));
	case 16:
		std::cout << "Choice 16: Merge Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		mergeSort(random, 0, sizeof(random[0]));
	case 17:
		std::cout << "Choice 17: Quick Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		quickSort(sorted, 0, sizeof(sorted[0]));
	case 18:
		std::cout << "Choice 18: Quick Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		quickSort(halfsorted, 0, sizeof(halfsorted[0]));
	case 19:
		std::cout << "Choice 19: Quick Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		quickSort(reverse, 0, sizeof(reverse[0]));
	case 20:
		std::cout << "Choice 20: Quick Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		quickSort(random, 0, sizeof(random[0]));
	case 21:
		std::cout << "Choice 21: Heap Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		heapSort(sorted, sizeof(sorted[0]));
	case 22:
		std::cout << "Choice 22: Heap Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		heapSort(halfsorted, sizeof(halfsorted[0]));
	case 23:
		std::cout << "Choice 23: Heap Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		heapSort(reverse, sizeof(reverse[0]));
	case 24:
		std::cout << "Choice 24: Heap Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		heapSort(random, sizeof(random));
	case 25:
		std::cout << "Choice 25: Counting Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		countingSort(sorted,empty,sortedSize);
	case 26:
		std::cout << "Choice 26: Counting Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		countingSort(halfsorted,empty,halfSortedSize);
	case 27:
		std::cout << "Choice 27: Counting Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		countingSort(reverse,empty,reverseSize);
	case 28:
		std::cout << "Choice 28: Counting Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		countingSort(random,empty,reverseSize);
	case 29:
		std::cout << "Choice 29: Radix Sort on Already Sorted Array" << endl;
		fillSorted(sorted,sortedSize);
		radixSort(sorted,empty,sortedSize);
	case 30:
		std::cout << "Choice 30: Radix Sort on Half Sorted Array" << endl;
		fillHalfsorted(halfsorted,halfSortedSize);
		quickSort(halfsorted,empty,sortedSize);
	case 31:
		std::cout << "Choice 31: Radix Sort on a Reversed Array" << endl;
		fillReverse(reverse, reverseSize);
		radixSort(reverse,empty, sortedSize);
	case 32:
		std::cout << "Choice 32: Radix Sort on a Random Array" << endl;
		fillRandom(random, randomSize);
		radixSort(random, empty, sortedSize);
	default:
		std::cout << "Invalid Choice";
	}
	std::cout << endl << endl;

	e = system_clock::now();

	duration < double > elapsed_seconds = e - s;

	std::cout << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;
}



int main()
{
	int size = 100000;
	int sorted[10];
	int sortedSize = sizeof(sorted) / sizeof(sorted[0]);
	fillSorted(sorted, sortedSize);

	int halfsorted[20];
	int halfSortedSize = sizeof(halfsorted) / sizeof(halfsorted[0]);
	fillHalfsorted(halfsorted, halfSortedSize);

	int reverse[20];
	int reverseSize = sizeof(reverse) / sizeof(reverse[0]);
	fillReverse(reverse, reverseSize);

	int random[20];
	int randomSize = sizeof(random) / sizeof(random[0]);
	fillRandom(random, randomSize);
	printArr(random,0, randomSize);
	std::cout << endl;
	/*int empty[size] = { 0 }
	while (true) {
		int choice;
		*/
		
	return 0;
}
