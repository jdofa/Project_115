#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/* A random array with "length" elements will be created. You can change the length variable if you want to test different scenarios.
Once the program is started, you will choose the target number. Then the execution time and whether the target number was found will be displayed.*/

bool sumCheckBrute(int a[], int size, int target);
bool sumCheckEfficient(int a[], int size, int target);
void merge(int a[], int left, int middle, int right);
void mergeSort(int a[], int left, int right);
void buildArray(int a[], int size);
void print(int a[], int n);

int main()
{
    //Variable that can be changed
    const int length = 100000;

    //Initializing array
    int array[length];
    buildArray(array, length);

    //Initializing time variables
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto executionTime = duration_cast<milliseconds>(stop - start);

    auto start2 = high_resolution_clock::now();
    auto stop2 = high_resolution_clock::now();
    auto executionTime2 = duration_cast<milliseconds>(stop2 - start2);

    //while loop that asks user for target number
    while (true) {
        cout << "Enter the target number. Numbers above " << length << " or negative numbers will not be found.\n" << "Find Number : ";
        int target;
        cin >> target;
        cout << endl;

        start = high_resolution_clock::now();
        sumCheckBrute(array, length, target);
        stop = high_resolution_clock::now();
        executionTime = duration_cast<milliseconds>(stop - start);
        cout << "Brute force method execution time: " << executionTime.count() << " milliseconds\n\n";

        start2 = high_resolution_clock::now();
        sumCheckEfficient(array, length, target);
        stop2 = high_resolution_clock::now();
        executionTime2 = duration_cast<milliseconds>(stop2 - start2);
        cout << "Efficient method execution time: " << executionTime2.count() << " milliseconds\n\n";

        //Printing if target is found
        if (sumCheckEfficient(array, length, target) == true) {
            cout << "The target was found\n";
        }
        else {
            cout << "The target was not found\n";
        }

        //building new unsorted random array
        buildArray(array, length);
    }
    return 0;
}

bool sumCheckBrute(int a[], int size, int target) //O(n^2)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i] + a[j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

bool sumCheckEfficient(int a[], int size, int target) //O(nlogn)
{
    int beg = 0;
    int end = size - 1;
    mergeSort(a, beg, end);

    while (beg < end) {
        if (a[beg] + a[end] == target) {
            return true;
        }
        else if (a[beg] + a[end] < target) {
            beg++;
        }
        else {
            end--;
        }
    }
    return false;
}

void buildArray(int a[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        a[i] = rand() % size;

    }
    return;
}

void print(int a[], int n) {
    cout << "Array: {" << a[0];
    for (int i = 1; i < n; i++) {
        cout << ", " << a[i];
    }
    cout << "}" << endl;
    return;
}

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