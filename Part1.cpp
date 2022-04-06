#include "algorithms.h"
#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

void arrayInfo(int arr[], int size);
void fillSorted(int a[], int size);
void fillHalfsorted(int a[], int size);
void fillReverse(int a[], int size);
void fillRandom(int a[], int size);
void print(int a[], int n);


int main()
{
	int sorted[20];
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
	print(random, randomSize);
	cout << endl;

	while (true) {
		int choice;
		cout << "Choose 1 - 7" << endl;
		cout << "Choice 1: Insertion Sort Worst Case" << endl;
		cout << "Choice 2: Insertion Sort Average Case" << endl;
		cout << "Choice 3: Insertion Sort Best Case" << endl;
		cout << "Choice 4: Merge Sort Worst/Average/Best Cases" << endl;
		cout << "Choice 5: ?" << endl;
		cout << "Choice 6: ?" << endl;
		cout << "Choice 7: ?" << endl;
		cout << "user>> ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			cout << "Choice 1: Insertion Sort Worst Case" << endl;
			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, reverseSize);
			//start time
			insertionSort(reverse, reverseSize);
			//end time
			//executionTime = end time - start time
			cout << "Sorted Array: ";
			arrayInfo(reverse, reverseSize);
			cout << "Execution Time: " << /*executionTime << */"[unit of measurement]" << endl;
			break;

		case 2:
			cout << "Choice 2: Insertion Sort's Average Case";
			//feed random array to insertion srot
			break;

		case 3:
			cout << "Choice 3: Insertion Sort's Best Case";
			//feed sorted array to insertion sort
			break;

		case 4:
			cout << "Choice 4: Merge Sort's Worst/Average/Best Cases";
			//feed random array to merge sort
			break;

		case 5:
			cout << "Choice 5";
			break;

		case 6:
			cout << "Choice 6";
			break;

		case 7:
			cout << "Choice 7";
			break;

		default:
			cout << "Invalid Choice";
		}
		cout << endl << endl;
	}
	return 0;
}

void fillSorted(int a[], int size) {
	for (int i = 0; i < size; i++) {
		a[i] = i + 1;
	}
	return;
}

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

void fillReverse(int a[], int size) {
	int g = size;
	for (int i = 0; i < size; i++) {
		a[i] = g;
		g--;
	}
	return;
}

void fillRandom(int a[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size; ++i) {
		a[i] = rand() % size;
	}
}

void arrayInfo(int arr[], int size)
{
	cout << "{ ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "........ ";
	for (int i = size - 10; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << "}" << endl;
}

void print(int a[], int n) {
	cout << "Printing Array: {" << a[0];
	for (int i = 1; i < n; i++) {
		cout << ", " << a[i];
	}
	cout << "}" << endl;
	return;
}
