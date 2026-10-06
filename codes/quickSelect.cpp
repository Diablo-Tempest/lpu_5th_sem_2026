#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        // Pivot is in its correct position
        if (pivotIndex == k)
            return arr[pivotIndex];

        // Search in left part
        if (k < pivotIndex)
            return quickSelect(arr, low, pivotIndex - 1, k);

        // Search in right part
        return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main()
{
    vector<int> arr = {7, 10, 4, 3, 20, 15};

    int k = 3; // Find 3rd smallest element

    // Convert k-th smallest to 0-based index
    int result = quickSelect(arr, 0, arr.size() - 1, k - 1);

    cout << k << "rd smallest element = " << result << endl;

    return 0;
}