#include <iostream>
#include <chrono>
using namespace std::chrono;

int sumCheckBrute(int A[], int n, int k)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int number = A[i] + A[j];
            if (number == k)                                                    // adds entry for the same indices twice
            {
                total++;
            }
        }
    }

    return total;
}

void buildArray(int* A, int k)
{
    int i = 0;
    while (i < k)
    {
        A[i] = i;
        i++;
    }
}

int main()
{
    const int length = 10000;                                                   // change number for different length of index
    int array[length];
    int target = length;
    int x;                                                                      // variable for the number of iterations two indices add up to target

    buildArray(array, length);

    time_point <system_clock> start, stop;

    start = system_clock::now();
    x = sumCheckBrute(array, length, target);
    stop = system_clock::now();

    duration <double> exe_time = stop - start;

    std::cout << "Brute force method execution time: " << exe_time.count() << " seconds\n";
    std::cout << "Number of times two indices equal target: " << x << " times\n";

    return 0;
}