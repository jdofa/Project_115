
#include "algorithms.h"
#include <iostream>
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

//The google document has Question 1 answered. Use those answers to fill in switch cases below.

int main()
{
	//variable 'size' can only go up to around 64,000. 

	const int size = 64000; //changes size to all arrays, only variable needed to change when testing

	//Initializes a sorted array
	int sorted[size];
	int sortedSize = sizeof(sorted) / sizeof(sorted[0]);
	fillSorted(sorted, sortedSize);

	//Initializes a half sorted array
	int halfsorted[size];
	int halfSortedSize = sizeof(halfsorted) / sizeof(halfsorted[0]);
	fillHalfsorted(halfsorted, halfSortedSize);;

	//Initializes a reversed array
	int reverse[size];
	int reverseSize = sizeof(reverse) / sizeof(reverse[0]);
	fillReverse(reverse, reverseSize);

	//Initializes a random array
	int random[size];
	int randomSize = sizeof(random) / sizeof(random[0]);
	fillRandom(random, randomSize);

	cout << endl;

	while (true) {

		//All algorithm's best/average/worst cases to time
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

		//need to define these variables outside of switch first
		auto start = high_resolution_clock::now();
		auto stop = high_resolution_clock::now();
		auto executionTime = duration_cast<milliseconds>(stop - start);

		switch (choice) {
		case 1: // <----------------------------------- use this case as an outline for rest of cases

			//give name to the choice
			cout << "Choice 1: Insertion Sort Worst Case" << endl;

			//print array to be sorted
			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, reverseSize); //use arrayInfo, only prints first 10 and last 10 elements of n size array 

			//measure algorithm's time
			start = high_resolution_clock::now();
			insertionSort(reverse, reverseSize);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<milliseconds>(stop - start);

			//print out the array after being sorted
			cout << "Sorted Array: ";
			arrayInfo(reverse, reverseSize); //use arrayInfo, only prints first 10 and last 10 elements of n size array 

			//Finally print out execution time of the algorithm
			cout << "Execution Time: " << executionTime.count() << " milliseconds" << endl;
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

		//This is to ensure that the next iteration, we have correct pre-sorted array
		fillSorted(sorted, sortedSize);
		fillHalfsorted(halfsorted, halfSortedSize);
		fillReverse(reverse, reverseSize);
		fillRandom(random, randomSize);
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
	cout << "Array: {" << a[0];
	for (int i = 1; i < n; i++) {
		cout << ", " << a[i];
	}
	cout << "}" << endl;
	return;
}
