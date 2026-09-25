#include <iostream>
#include <vector>
using namespace std;

long long mergeArrays(vector<int>& arr, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);

            count += mid - i + 1;

            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = 0; i < temp.size(); i++)
    {
        arr[left + i] = temp[i];
    }

    return count;
}

long long mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = (left + right) / 2;

    long long count = 0;

    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right);

    count += mergeArrays(arr, left, mid, right);

    return count;
}

long long countInversions(vector<int> arr)
{
    if (arr.size() <= 1)
    {
        return 0;
    }

    return mergeSort(arr, 0, arr.size() - 1);
}

void printArray(vector<int> arr)
{
    cout << "[";

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];

        if (i < arr.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]";
}

int main()
{
    // Test Case 1
    vector<int> arr1 = {2, 4, 1, 3, 5};

    cout << "Test Case 1" << endl;
    cout << "Input: ";
    printArray(arr1);
    cout << endl;

    cout << "Output: " << countInversions(arr1) << endl;
    cout << endl;


    // Test Case 2
    vector<int> arr2 = {4, 1, 3, 2};

    cout << "Test Case 2" << endl;
    cout << "Input: ";
    printArray(arr2);
    cout << endl;

    cout << "Output: " << countInversions(arr2) << endl;
    cout << endl;


    // Test Case 3
    vector<int> arr3 = {5, 5, 5};

    cout << "Test Case 3" << endl;
    cout << "Input: ";
    printArray(arr3);
    cout << endl;

    cout << "Output: " << countInversions(arr3) << endl;

    return 0;
}
//all test cases in a single output here.