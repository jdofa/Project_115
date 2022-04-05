//Problems: Heap Sort Counting Sort & Radix Sort Algorithms not present
// Quick Sort Algorithm is throwing an infinite loop
//array is not displaying when code is ran
//Merge Sort partition parameters are a problem with random size arr

#include <iostream>
#include <time.h>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

//**********************************SORTING ALGS**********************************//
//**************SORT 1 INSERTION SORT*************//
int InsertionSort(int* arr, int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;
		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
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
//create a method to perform selection sort
int selectionSort(int* my_array) {
	int counter = 0;
	for (int i = 0; i < 6; i++) {
		// array's index starts at 0 
		//if the index is larger then the size of the array you will get a memory leak(segmentation fault 11: (core dumped))
		//traverse through the array by incrementing the index by one
		int min = i;
		//set the current minimum value equal to the index
		for (int j = i + 1; j < 6; j++) {
			//j will always represent the next index in the array
			if (my_array[j] < my_array[min]) {
				// if the array at the next index is larger than the previous index
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
//*****************SORT 5 QUICK SORT************ERRORS NEEDS NEW CODE
//int partition(int arr[], int low, int high) {
//    int i = low;
//    int j = high;
//    int n = 5;
//    /*cout << "Pivot a median:" << endl;
//    int pivotDex = arr[(low + high) / 2];
//    cout << pivotDex << "Pivot Index: " << endl;*/
//     cout << "Pivot a rand:" << endl;
//     int pivotDex = rand() % (n);
//     /*cout << "Pivot a first ele:" << endl;
//     int pivotDex = arr[i];*/
//    bool flag = false;
//    while (!flag) {
//        while (true) {
//            if (arr[i] <= pivotDex) {
//                break;
//            }
//            i++;
//        }
//        while (true) {
//            if (arr[j] >= pivotDex) {
//                break;
//            }
//            j--;
//        }
//        if (i < j) {
//            swap(i, j);
//        }
//        else {
//            flag = true;
//        }
//    }
//    cout << "Here is the pivot at position: " << j << endl;
//    return j;
//}
//int quickSort(int arr[], int low, int high) {
//    if (low < high) {
//        int pivotDex = partition(arr, low, high);
//        quickSort(arr, low, pivotDex);
//        quickSort(arr, pivotDex + 1, high);
//    }
//    return 0;
//}

//******************************SORT 6 HEAP SORT**************************//
//Enter algorithm here

//******************************SORT 7 COUNTING SORT*********************//
//Enter algorithm here

//*****************************SORT 8 RADIX SORT*************************//
// Enter algorithm here

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
	return arr;
	printUnsortedarry(arr, size);
}
//*****************CHECKING THE RUN TIME*******************//
void check_the_time(int* arr, int size)
{
	std::chrono::time_point < std::chrono::system_clock > start, end;
	start = std::chrono::system_clock::now();
	cout << setprecision(50) << '\n';
	//******************INSERTION TIME********************//
	std::cout << "Insertion Sort Running Time: ";
	arr = create_rand_arr(arr, size);
	std::cout << InsertionSort(arr, size) << '\n';
	end = std::chrono::system_clock::now();
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
	std::cout << selectionSort(arr) << '\n';
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
int main()
{
	int i = 0;
	int* arr = new int[i];
	for (i = 2000; i < 10000; i += 2000)
	{
		cout << "***************" << i << " ELEMENTS****************" << endl;
		check_the_time(arr, i);
	}
	return 0;
}
