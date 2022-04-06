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
	for (int i = 0; i < size-1; i++)
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
		swap(a, i, j);
	}
	else {
		return j;
	}
	return 0;
}

void quickSort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quickSort(a, p, q);
		quickSort(a, q + 1, r);
	}
	return;
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

//Radix Sort
void radixSort(int a[], int b[], int n) {
	int largest = a[0];
	for (int i = 1; i < n; i++) {
		if (largest < a[i]) {
			largest = a[i];
		}
	}
	double d = floor(log10(largest) + 1);
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