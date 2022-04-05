/* Rodolfo
1. I found errors in your check_the_time function. I will put comments there with my concerns.
2. I added recommendations in your main function
*/

#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace std::chrono;

//algorithms
int InsertionSort(int* arr, int size);
int selectionSort(int* my_array);
int BubbleSort(int* arr, int size);
void merge(int* orignal_array, int start, int mid, int end);
int mergeSort(int* orignal_array, int start, int end);
void quickSort(int a[], int p, int r);
int partition(int a[], int low, int high);
/*need heapsort*/
void countingSort(int a[], int b[], int n);
void radixSort(int a[], int b[], int n);

//helper functions
void printUnsortedarry(int arr[], int size);
int* create_rand_arr(int* arr, int size);
void fillReverse(int a[], int n); // could use this template to make arrays
void check_the_time(int* arr, int size);
//reference functions here so we don't have to scroll down to find the main function

int main()
{
	//Merge Sort partition parameters are a problem with random size arr
	int* arr = new int[0]; //We could use regular arrays instead of dynamic
	for (int i = 2000; i < 10000; i += 2000)
	{
		cout << "***************" << i << " ELEMENTS****************" << endl;
		check_the_time(arr, i);
	}
	/*We could ask the user which array they want sorted.Because if we do all at once then it can be possible
	 that when collecting data, one algorithm may take way too long and make gathering data hard.
	 Also, we need options for algorithms to sort either sorted, unsorted, or random array. Because
	 we need Insertion Sort's worst case. We need Insertion Sort to sort an unsorted array. So we should also ask
	 the user what kind of array they want along with the algorithm they want.

	 Example of possible interface)

	 Choose your algorithm. Enter a number 1 - 8. 
	 1. Insertion
	 2. Selection
	 3. Bubble
	 4. Merge Sort
	 5. Quicksort
	 6. Heapsort
	 7. Counting Sort
	 8. Radix Sort

	 user>> 1 // The user chose one so we use insertion sort

	 How would you like your array sorted?
	 1. Sorted
	 2. Unsorted
	 3. Random
	 4. Idk if we need other options

	 user>> 2 // The user wants an unsorted array

	 Choose the size of the array. Enter '0' to exit the program.
	 
	 user>> 10000

	 Execution Time: ?s

	 Choose the size of the array. Enter '0' to exit the program.

	 user>> 0

	 //program terminated

	 You could make a while loop out of asking the user for the size of the array. So we can easily get data
	 for the chosen algorithm and it's worst/best case. 
	*/
	return 0;
}

void fillReverse(int a[], int n) { // (pass an unitialized array, pass the size wanted)
	int g = n;
	for (int i = 0; i < n; i++) {
		a[i] = g; 
		g--;
	}
	return; // lets say n = 10, array output: [10,9,8,7,6,5,4,3,2,1]
}

//**********************************SORTING ALGS**********************************//
//**************SORT 1 INSERTION SORT*************//
int InsertionSort(int* arr, int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	return 0;
}
//*****************SORT 2 SELECTION SORT************//
int selectionSort(int* my_array) {
	int counter = 0;
	for (int i = 0; i < 6; i++) {
		int min = i;
		for (int j = i + 1; j < 6; j++) {
			if (my_array[j] < my_array[min]) {
				min = j;
			}
			counter = counter + 1;
		}
		swap(my_array[i], my_array[min]);

	}
	return 0;
}

//*****************SORT 3 BUBBLE SORT************//
int BubbleSort(int* arr, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return 0;
}
//*****************SORT 4 MERGE SORT************//
void merge(int* orignal_array, int start, int mid, int end) {
	int left_size = mid - start + 1;
	int* left_array = new int[left_size];
	for (int i = 0; i < left_size; i++) {
		left_array[i] = orignal_array[i + start];
	}
	int right_size = end - mid;
	int* right_array = new int[right_size];
	for (int j = 0; j < right_size; j++) {
		right_array[j] = orignal_array[j + mid + 1];
	}
	int right_index = 0, left_index = 0, original_index = start;
	while ((right_index < left_size) && (left_index < right_size)) {
		if (left_array[right_index] < right_array[left_index]) {
			orignal_array[original_index] = left_array[right_index];
			right_index++;
		}
		else {
			orignal_array[original_index] = right_array[left_index];
			left_index++;
		}
		original_index++;
	}
	if (right_index < left_size) {
		for (int k = right_index; k < left_size; k++) {
			orignal_array[original_index] = left_array[k];
			original_index++;
		}
	}
	else {
		for (int i = left_index; i < right_size; i++) {
			orignal_array[original_index] = right_array[i];
			original_index++;
		}
		delete[] left_array;
		delete[] right_array;
	}

}
int mergeSort(int* orignal_array, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(orignal_array, start, mid);
		mergeSort(orignal_array, mid + 1, end);
		merge(orignal_array, start, mid, end);
	}
	return 0;
}
//*****************SORT 5 QUICK SORT************
void quickSort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quickSort(a, p, q);
		quickSort(a, q + 1, r);
	}
	return;
}

int partition(int a[], int low, int high) {
	int pivot = a[low];
	int i = low - 1;
	int j = high + 1;
	bool jB = true;
	while (jB) {
		j--;
		if (a[j] <= pivot) {
			jB = false;
		}
	}
	bool iB = true;
	while (iB) {
		i++;
		if (a[i] >= pivot) {
			iB = false;
		}
	}
	if (i < j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	else {
		return j;
	}
	return 0;
}

//******************************SORT 6 HEAP SORT**************************//
//Enter algorithm here

//******************************SORT 7 COUNTING SORT*********************//
void countingSort(int a[], int b[], int n) {
	int largest = a[0];
	for (int i = 1; i < n; i++) {
		if (largest < a[i]) {
			largest = a[i];
		}
	}
	int* aux;
	aux = new int[largest + 1];
	for (int i = 0; i < largest + 1; i++) {
		aux[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		aux[a[i]]++;
	}
	for (int i = 1; i < largest + 1; i++) {
		aux[i] = aux[i] + aux[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		b[aux[a[i]] - 1] = a[i];
		aux[a[i]]--;
	}
	return;
}

//*****************************SORT 8 RADIX SORT*************************//
void radixSort(int a[], int b[], int n) {
	int largest = a[0];
	for (int i = 1; i < n; i++) {
		if (largest < a[i]) {
			largest = a[i];
		}
	}
	int d = floor(log10(largest) + 1); 
		for (int z = 1; z <= d; z++) { 
				int aux[10];
			for (int i = 0; i < 10; i++) {
				aux[i] = 0;
			}
			for (int i = 0; i < n; i++) { 
					int squish = floor((fmod(a[i], pow(10, z)) / pow(10, z - 1)));
				aux[squish]++;
			}
			for (int i = 1; i < 9; i++) {
				aux[i] = aux[i] + aux[i - 1];
			}
			for (int i = n - 1; i >= 0; i--) {
				int squish = floor((fmod(a[i], pow(10, z)) / pow(10, z - 1)));
				b[aux[squish] - 1] = a[i];
				aux[squish]--;
			}
			for (int i = 0; i < n; i++) {
				a[i] = b[i];
			}
		}
	return;
}

//***********PRINTING ALL ARRAYS*************//
void printUnsortedarry(int arr[], int size)
{
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "........";
	for (int i = size - 20; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int* create_rand_arr(int* arr, int size)//worst case
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
//*****************CHECKING THE RUN TIME*******************//
void check_the_time(int* arr, int size)
{
	std::chrono::time_point < std::chrono::system_clock > start, end; 
	start = std::chrono::system_clock::now(); // <-- You started grabbing time here
	cout << setprecision(50) << '\n';
	//******************INSERTION TIME********************//
	std::cout << "Insertion Sort Running Time: ";
	arr = create_rand_arr(arr, size); // The problem is we only want to record how long Insertion Sort took
	std::cout << InsertionSort(arr, size) << '\n';
	end = std::chrono::system_clock::now(); // <-- You stopped grabbing time here
	std::chrono::duration < double >
		elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	std::cout << "finished computation at " << std::
		time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;
	//******************SELECTION TIME********************//
	start = std::chrono::system_clock::now();
	cout << setprecision(50) << '\n';
	std::cout << "Selection Sort Running Time: ";
	std::cout << selectionSort(arr) << '\n'; // You are passing the array sorted by Insertion Sort
	std::cout << "finished computation at " << std::
		time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;
	//*****************BUBBLE TIME***********************//
	start = std::chrono::system_clock::now();
	cout << setprecision(50) << '\n';
	std::cout << "Bubble Sort Running Time: ";
	std::cout << BubbleSort(arr, size) << '\n';
	std::cout << "finished computation at " << std::
		time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;
	//*****************MERGE TIME************************//
	cout << setprecision(50) << '\n';
	std::cout << "Merge Sort On Reversed Array Running Time: ";
	std::cout << mergeSort(arr, 3, 3) << '\n';//edit
	std::cout << "finished computation at " << std::
		time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;
	//****************QUICK TIME*************************//
   /* start = std::chrono::system_clock::now();
	cout << setprecision(50) << '\n';
	std::cout << "Quick Sort Running Time: ";
	std::cout << QuickSort(arr, size) << '\n';
	std::cout << "finished computation at " << std::
		time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;

	//****************HEAP TIME*************************/
	/* start = std::chrono::system_clock::now();
	cout << setprecision(50) << '\n';
	std::cout << "Heap Sort Running Time: ";
	std::cout << HeapSort(arr??, size) << '\n';
	std::cout << "finished computation at " << std::
		time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
		count() <<
		"s\n" << endl;*/

		//**************COUNTING TIME*********************//
		   /* start = std::chrono::system_clock::now();
		   cout << setprecision(50) << '\n';
		   std::cout << "Counting Sort Running Time: ";
		   std::cout << CountingSort(arr??, size) << '\n';
		   std::cout << "finished computation at " << std::
			   time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
			   count() <<
			   "s\n" << endl;*/

			   //*************RADIX TIME*************************//
				  /* start = std::chrono::system_clock::now();
				  cout << setprecision(50) << '\n';
				  std::cout << "Radix Sort Running Time: ";
				  std::cout << RadixSort(arr, size) << '\n';
				  std::cout << "finished computation at " << std::
					  time(&end_time) << endl << "elapsed time: " << elapsed_seconds.
					  count() <<
					  "s\n" << endl;*/
}

