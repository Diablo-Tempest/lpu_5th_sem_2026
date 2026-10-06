#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    // Copy elements into temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    // Merge both arrays
    while (i < n1 && j < n2)
    {

        if (left[i] <= right[j])
            arr[k++] = left[i++];

        else
            arr[k++] = right[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int low, int high)
{

    if (low < high)
    {

        int mid = low + (high - low) / 2;

        // Divide
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Conquer
        merge(arr, low, mid, high);
    }
}

int main()
{

    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}