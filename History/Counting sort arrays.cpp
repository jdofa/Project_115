
#include <iostream>
using namespace std;
//best case for counting/radix sort
void multNum_arr(int arr[],int n) {
	const int num = 1;//you can change the number to whatever should display [num,num,num,num,num]
	for (int i = 0; i < n; i++) {
		
		arr[i] = 1;
	}
}
//??
void largestValue_arr(int arr[], int n) {
	arr[0] = 10000;
}
//dont know how
//void excessElements_arr(int arr[], int n) {
	int num;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0){
	}
	}
//}
void printArr(int arr[], int n){
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
int main()
{
	const int passing_size = 7;//change the size here
	int passing_arr[passing_size] = {3,12,93,123,73,66,34};
	/*cout << "Best Case Array:***********" << endl;
	bestCase_arr(passing_arr, passing_size);
	printArr(passing_arr, passing_size);
	cout << endl;*/
	cout << "Avgerage Case Array:********" << endl;
	largestValue_arr(passing_arr,passing_size);
	printArr(passing_arr, passing_size);
	return 0;
}
