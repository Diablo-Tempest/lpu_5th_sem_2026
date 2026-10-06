#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        // one position to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}

int main()
{

    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;

    insertionSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}