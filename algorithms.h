#pragma once
#include <iostream>
#include <cmath>
using namespace std;

//Swap function
void swap(int arr[], int j, int k)
{
	int temp = arr[j];
	arr[j] = arr[k];
	arr[k] = temp;
	return;
}

//Insertion Sort
int insertionSort(int arr[], int size)
{
	int i;
	int j;
	int k;
	for (i = 1; i < size; i++)
	{
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = k;
	}
	return 0;
}

//Selection Sort
void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a, i, min);
	}
	return;
}

//Bubble Sort
void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
			}
		}
	}
	return;
}

//Merge Sort
void merge(int a[], int left, int middle, int right) {
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int* l = new int[n1];
	int* r = new int[n2];

	for (int p = 0; p < n1; p++) {
		l[p] = a[left + p];
	}
	for (int q = 0; q < n2; q++) {
		r[q] = a[middle + 1 + q];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (l[i] <= r[j]) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		a[k] = l[i];
		i++;
		k++;
	}
	while (j < n2) {
		a[k] = r[j];
		j++;
		k++;
	}
	return;
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSort(a, left, middle);
		mergeSort(a, middle + 1, right);
		merge(a, left, middle, right);
	}
	return;
}

//Quicksort 
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int getMedian(int arr[], int first, int last) {
	int mid = (last - first) / 2;

	if ((arr[first] < arr[mid] and arr[mid] < arr[last]) or (arr[last] < arr[mid] and arr[mid] < arr[first])) {
		return mid;
	}

	if ((arr[mid] < arr[first] and arr[first] < arr[last]) or (arr[last] < arr[first] and arr[first] < arr[mid])) {
		return first;
	}
	else {
		return last;
	}
}

int partition_random(int arr[], int low, int high) {
	srand(high);
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(arr, low, high);
}

int partition_median(int arr[], int low, int high) {
	int median = getMedian(arr, low, high);
	swap(arr[median], arr[high]);
	return partition(arr, low, high);
}

int partition_first(int arr[], int low, int high) {
	swap(arr[low], arr[high]);
	return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high, int choice) {
	if (low < high) {
		int pi;
		if (choice == 1) {
			pi = partition_first(arr, low, high);
		}
		else if (choice == 2) {
			pi = partition_random(arr, low, high);
		}
		else if (choice == 3) {
			pi = partition_median(arr, low, high);
		}
		quickSort(arr, low, pi - 1, choice);
		quickSort(arr, pi + 1, high, choice);
	}
}

//Heapsort
void max_heapify(int a[], int i, int n)
{
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	int largest = i;

	if (leftChild <= n && a[leftChild] > a[i])
	{
		largest = leftChild;
	}

	if (rightChild <= n && a[rightChild] > a[largest])
	{
		largest = rightChild;
	}

	if (largest != i)
	{
		swap(a, i, largest);
		max_heapify(a, largest, n);
	}
	return;
}

void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		max_heapify(a, i, n);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		swap(a, 0, i);
		max_heapify(a, 0, i - 1);
	}
	return;
}

//Counting Sort
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

//Radix Sort using Counting Sort
int getMax(int array[], int n) {
	int maxVal = array[0];
	for (int i = 1; i < n; i++) {
		if (array[i] > maxVal) {
			maxVal = array[i];
		}
	}
	return maxVal;
}

void countSort(int array[], int output[], int n, int exp) {

	int i, count[10] = { 0 };

	for (i = 0; i < n; i++) {
		count[(array[i] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for (i = n - 1; i >= 0; i--) {
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++) {
		array[i] = output[i];
	}
}

void radixSort(int array[], int output[], int n) {

	int m = getMax(array, n);

	for (int exp = 1; m / exp > 0; exp *= 10) {
		countSort(array, output, n, exp);
	}
}