#include <iostream>
using namespace std;

void selectionSort(int a[], int n);
void fillReverse(int a[], int n);

int main() {
	int arraySize = 10000; //Should only change this when testing
	
	//Make following into loop
	//1. What sorting algorithm do you want to use?
	//2. How should the array come sorted before-hand? Sorted, half-sorted, reversed, random

	return 0;
}

void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	return;
}

void fillReverse(int a[], int n) {
	int g = n;
	for (int i = 0; i < n; i++) {
		a[i] = g;
		g--;
	}
	return;
}