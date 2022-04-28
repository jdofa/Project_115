#include "algorithms.h" //make sure you also have included this file in your project
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

/*
This program measures the execution time of 8 different algorithms and it's cases. You can change the variable size in order to have these
algorithms sort larger lists. Once the program is started, you only need to choose what algorithm you'd like to see in action. This is determined
by entering an integer according with the choice number displayed. To exit the program, enter the number 20.
*/

void arrayInfo(int arr[], int size); //prints first and last 10 elements
void fillSorted(int a[], int size); //fills an array in sorted manner
void fillHalfsorted(int a[], int size); //fills an array in half-sorted manner
void fillReverse(int a[], int size); //fills an array in reversed manner
void fillRandom(int a[], int size);  //fills an array in random manner
void fillSame(int a[], int size, int fillWith); //fills an array where all elments are identical
void fillSkewed(int a[], int size); //fills an array where data is skewed to the left
void fillSig(int a[], int size); //fills an array where one number has significantly more digits than the rest
void print(int a[], int n); //fully prints out an array

int main()
{

	// ----- Variable Used For Testing ----- //
	const int size = 30000;


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

	//Initializes an array that is skewed with big range
	int skewed[size];
	fillSkewed(skewed, size);

	//Empty Array for Counting Sort
	int result[size] = { 0 };

	//Initializing array for Radix Worst Case
	int significant[size];
	fillSig(significant, size);


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
	cout << "Choice 10: Quick Sort's Average Case" << endl;
	cout << "Choice 11: Quick Sort's Best Case" << endl;
	cout << "Choice 12: Heap Sort's Worst/Average Cases" << endl;
	cout << "Choice 13: Heap Sort's Best Case" << endl;
	cout << "Choice 14: Counting Sort's Worst Case" << endl;
	cout << "Choice 15: Counting Sort's Average Case" << endl;
	cout << "Choice 16: Counting Sort's Best Case" << endl;
	cout << "Choice 17: Radix Sort's Worst Case" << endl;
	cout << "Choice 18: Radix Sort's Average Case" << endl;
	cout << "Choice 19: Radix Sort's Best Case" << endl;
	cout << "Choice 20: Exit" << endl;

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
		case 1://Insertion Sort sorting a reversed array

			//give name to the choice
			cout << "Choice 1: Insertion's Sort Worst Case" << endl;

			//print array to be sorted
			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, size); //arrayInfo only prints first 10 and last 10 elements to provide insight

			//measure algorithm's execution time
			start = high_resolution_clock::now();
			insertionSort(reverse, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			//print out the array after being sorted
			cout << "Sorted Array: ";
			arrayInfo(reverse, size); //arrayInfo only prints first 10 and last 10 elements to provide insight

			//Finally print out execution time of the algorithm
			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 2://Insertion Sort sorting a random array
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

		case 3://Insertion Sort sorting a sorted array
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

		case 4://Selection Sort sorting a reversed array
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

		case 5://Bubble Sort sorting a reversed array
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

		case 6://Bubble Sort sorting a random array
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

		case 7://Bubble Sort sorting a sorted array
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

		case 8://Merge Sort sorting a random array
			cout << "Choice 8: Merge Sort's Worst/Average/Best Cases" << endl;

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
			cout << "Choice 9: Quick Sort's Worst Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(sorted, size);

			start = high_resolution_clock::now();
			quickSort1(sorted, 0, size - 1);
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
			quickSort2(random, 0, size - 1);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(random, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 11: //Quicksort with median pivot sorting sorted array
			cout << "Choice 11: Quick Sort's Best Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(sorted, size);

			start = high_resolution_clock::now();
			quickSort2(sorted, 0, size - 1);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(sorted, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 12://Heap Sort sorting random array
			cout << "Choice 12: Heap Sort's Worst/Average Cases" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(random, size);

			start = high_resolution_clock::now();
			heapSort(random, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(random, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 13://Heap Sort sorting array with identical elements
			cout << "Choice 13: Heap Sort's Best Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(identical, size);

			start = high_resolution_clock::now();
			heapSort(identical, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(identical, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 14://Counting Sort sorting skewed array
			cout << "Choice 14: Counting Sort's Worst Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(skewed, size);

			start = high_resolution_clock::now();
			countingSort(skewed, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 15: // Counting Sort where the biggest number in the array is the size of it, n = k
			cout << "Choice 15: Counting Sort's Average Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(reverse, size);

			start = high_resolution_clock::now();
			countingSort(reverse, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 16: //Counting Sort sorting an array where all elements are identical
			cout << "Choice 16: Counting Sort's Best Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(identical, size);

			start = high_resolution_clock::now();
			countingSort(identical, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 17://Radix Sort sorting an array where one element has significantly more digits than the rest
			cout << "Choice 17: Radix Sort's Worst Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(significant, size);

			start = high_resolution_clock::now();
			radixSort(significant, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 18://Radix Sort sorting random array
			cout << "Choice 18: Radix Sort's Average Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(random, size);

			start = high_resolution_clock::now();
			radixSort(random, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;

		case 19: //Radix Sort sorting array where each element has same amount of digits
			cout << "Choice 19: Radix Sort's Best Case" << endl;

			cout << "Array To Be Sorted: ";
			arrayInfo(identical, size);

			start = high_resolution_clock::now();
			radixSort(identical, result, size);
			stop = high_resolution_clock::now();
			executionTime = duration_cast<microseconds>(stop - start);

			cout << "Sorted Array: ";
			arrayInfo(result, size);

			cout << "Execution Time: " << executionTime.count() << " microseconds" << endl;
			break;
		case 20:
           		return 0;
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
		fillSkewed(skewed, size);
		fillSig(significant, size);

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

void fillSkewed(int a[], int size) {
	for (int i = 0; i < size - ((size * 2) / 10); i++) {
		a[i] = 10;
	}

	for (int i = size - ((size * 2) / 10); i < size; i++) {
		a[i] = 10000;
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

void fillSig(int a[], int size) {
	srand(time(NULL));
	for (int i = 0; i < size - 1; i++) {
		a[i] = rand() % 10;
	}
	a[size - 1] = 2147483647; //biggest possible int
	return;
}
