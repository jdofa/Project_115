
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
void fillSame(int a[], int size, int fillWith);
void print(int a[], int n);

//The google document has Question 1 answered. Use those answers to fill in switch cases below.

int main()
{

	// ----- Variable Used For Testing ----- //
	const int size = 10000;


	// ----- Initializing Arrays ----- //
	//Initializes a sorted array
	int sorted[size];
	fillSorted(sorted, size);

	//Initializes a half sorted array
	int halfsorted[size];
	fillHalfsorted(halfsorted, size);;

	//Initializes a reversed array
	int reverse[size];
	fillReverse(reverse, size);

	//Initializes a random array
	int random[size];
	fillRandom(random, size);

	//Initializes an array with the same number, the repeated number is determined by the 3rd parameter
	int identical[size];
	fillSame(identical, size, 1);

	//Empty Array for Counting Sort
	int result[size] = { 0 };
	int resultSize = sizeof(result) / sizeof(result[0]);

	// ----- Printing Information For User ----- //
	int choice;
	cout << "Choose 1 - 20" << endl;
	cout << "Choice 1: Insertion Sort's Worst Case" << endl;
	cout << "Choice 2: Insertion Sort's Average Case" << endl;
	cout << "Choice 3: Insertion Sort's Best Case" << endl;
	cout << "Choice 4: Selection Sort's Worst/Average/Best Cases" << endl;
	cout << "Choice 5: Bubble Sort's Worst Case" << endl;
	cout << "Choice 6: Bubble Sort's Average Case" << endl;
	cout << "Choice 7: Bubble Sort's Best Case" << endl;
	cout << "Choice 8: Merge Sort's Worst/Average/Best Cases" << endl;
	cout << "Choice 9: Quick Sort's Worst Case" << endl;
	cout << "(logical error in algorithm?) Choice 10: Quick Sort's Average Case" << endl;
	cout << "Choice 11: Quick Sort's Best Case" << endl;
	cout << "(not done) Choice 12: Heap Sort's Worst Case" << endl;
	cout << "(not done) Choice 13: Heap Sort's Average Case" << endl;
	cout << "(not done) Choice 14: Heap Sort's Best Case" << endl;
	cout << "(not done) Choice 15: Counting Sort's Worst Case" << endl;
	cout << "Choice 16: Counting Sort's Average Case" << endl;
	cout << "Choice 17: Counting Sort's Best Case" << endl;
	cout << "(not done) Choice 18: Radix Sort's Worst Case" << endl;
	cout << "(not done) Choice 19: Radix Sort's Average Case" << endl;
	cout << "(not done) Choice 20: Radix Sort's Best Case" << endl;


	// ----- Switch Case In While Loop For Infinite Testing ----- //
	while (true) {
		cout << "user>> ";
		cin >> choice;
		cout << endl;

		//need to define these variables outside of switch first
		auto start = high_resolution_clock::now();
		auto stop = high_resolution_clock::now();
		auto executionTime = duration_cast<microseconds>(stop - start);

		switch (choice) {
		case 1: // <----------------------------------- use this case as an outline for rest of cases

			//give name to the choice
			cout << "Choice 1: Insertion's Sort Worst Case" << endl;

			//print array to be sorted
			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, size); //use arrayInfo, only prints first 10 and last 10 elements of n size array 

			//measure algorithm's time
			start = high_resolution_clock::now();
			insertionSort(reverse, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			//print out the array after being sorted
			cout << "Sorted Array: ";
			arrayInfo(reverse, size); //use arrayInfo, only prints first 10 and last 10 elements of n size array 

			//Finally print out execution time of the algorithm
			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 2:
			cout << "Choice 2: Insertion Sort's Average Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(random, size);

			start = high_resolution_clock::now();
			insertionSort(random, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(random, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 3:
			cout << "Choice 3: Insertion Sort's Best Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(sorted, size);

			start = high_resolution_clock::now();
			insertionSort(sorted, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(sorted, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 4:
			cout << "Choice 4: Selection Sort's Worst/Average/Best Cases" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, size);

			start = high_resolution_clock::now();
			selectionSort(reverse, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(reverse, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 5:
			cout << "Choice 5: Bubble Sort's Worst Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, size);

			start = high_resolution_clock::now();
			bubbleSort(reverse, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(reverse, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 6:
			cout << "Choice 6: Bubble Sort's Average Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(random, size);

			start = high_resolution_clock::now();
			bubbleSort(random, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(random, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 7:
			cout << "Choice 7: Bubble Sort's Best Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(sorted, size);

			start = high_resolution_clock::now();
			bubbleSort(sorted, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(sorted, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 8:
			cout << "Choice 4: Merge Sort's Worst/Average/Best Cases" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(random, size);

			start = high_resolution_clock::now();
			mergeSort(random, 0, size - 1);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(random, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 9: //Quicksort with first element as pivot sorting a sorted array
			cout << "Choice 9: Quick Sort's Worst Case" << endl; // for some reason, there is overflow when size is 10k 

			cout << "Array To Be Sorted: ";
			arrayInfo(sorted, size);

			start = high_resolution_clock::now();
			quickSort(sorted, 0, size - 1);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(sorted, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 10: //Quicksort with median pivot sorting random array
			cout << "Choice 10: Quick Sort's Average Case" << endl; // <--- logical error in medianpivot quicksort ------

			cout << "Array To Be Sorted: ";
			arrayInfo(random, size);

			start = high_resolution_clock::now();
			quickSort_medianpivot(random, 0, size - 1);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(random, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 11: //Quicksort with median pivot sorting sorted array
			cout << "Choice 11: Quick Sort's Best Case" << endl;

			cout << "Sorted Array: ";
			arrayInfo(sorted, size);

			start = high_resolution_clock::now();
			quickSort_medianpivot(sorted, 0, size - 1);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(sorted, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 12:
			cout << "Choice 12: Heap Sort's Worst Case" << endl;
			break;
		case 13:
			cout << "Choice 13: Heap Sort's Average Case" << endl; //Not sure yet of how arrays should look like for heapsort
			break;
		case 14:
			cout << "Choice 14: Heap Sort's Best Case" << endl;
			break;
		case 15:
			cout << "Choice 15: Counting Sort's Worst Case" << endl;
			//skewed data <-- not exactly sure how to generate this array
			break;
		case 16: // Counting Sort where the biggest number in the array is the size of it, n = k
			cout << "Choice 16: Counting Sort's Average Case" << endl;

			cout << "Sorted Array: ";
			arrayInfo(reverse, size);

			start = high_resolution_clock::now();
			countingSort(reverse, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 17: //Counting Sort sorting an array where all elements are identical
			cout << "Choice 17: Counting Sort's Best Case" << endl;

			cout << "Sorted Array: ";
			arrayInfo(identical, size);

			start = high_resolution_clock::now();
			countingSort(identical, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 18:
			cout << "Choice 18: Radix Sort's Worst Case" << endl;
			//all elements have same digits except for one, where that one has a lot more digits
			break;
		case 19:
			cout << "Choice 19: Radix Sort's Average Case" << endl;
			break;
		case 20:
			cout << "Choice 20: Radix Sort's Best Case" << endl;
			//all numbers in array have same amount of digits
			break;
		default:
			cout << "Invalid Choice" << endl;
		}
		cout << endl << endl;

		//Ensures all arrays go back to their initial state after being sorted
		fillSorted(sorted, size);
		fillHalfsorted(halfsorted, size);
		fillReverse(reverse, size);
		fillRandom(random, size);
		fillSame(identical, size, 1);
	}
	return 0;
}

// ----- Defining Helper Functions ----- //
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

	for (int i = 0; i < size; i++) {
		a[i] = i + 1;

	}
	srand(time(NULL));
	for (int i = size - 1; i > 0; i--) {
		int randNum = rand() % i;
		int temp = a[i];
		a[i] = a[randNum];
		a[randNum] = temp;
	}
	return;
}

void fillSame(int a[], int size, int fillWith) {
	for (int i = 0; i < size; i++) {
		a[i] = fillWith;
	}
	return;
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
