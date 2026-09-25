#include <iostream>
#include <vector>
using namespace std;

int quickSelect(vector<int>& arr, int k)
{
    int target = arr.size() - k;

int left = 0;
int right = arr.size() - 1;

    while (left <= right)
    {
    int pivot = arr[right];

    int index = left;

        for (int i = left; i < right; i++)
        {
            if (arr[i] < pivot)
            {
                swap(arr[i], arr[index]);
                index++;
            }
        }

        swap(arr[index], arr[right]);

        if (index == target)
        {
            return arr[index];
        }
        else if (index < target)
        {
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }

    return -1;
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
    //NOTE: All test case in single output here.
    // Test Case 1
    vector<int> arr1 = {10,4,7,2,9,6};
    int k1 = 3;

    cout << "Test Case 1" << endl;
    cout << "Input: ";
    printArray(arr1);
    cout << ", k = " << k1 << endl;

    int result1 = quickSelect(arr1, k1);

    cout << "Output: " << result1 << endl;
    cout << endl;


    // Test Case 2
    vector<int> arr2 = {6,3,6,2,9};
    int k2 = 2;

    cout << "Test Case 2" << endl;
    cout << "Input: ";
    printArray(arr2);
    cout << ", k = " << k2 << endl;

    int result2 = quickSelect(arr2, k2);

    cout << "Output: " << result2 << endl;
    cout << endl;


    // Test Case 3
    vector<int> arr3 = {4};
    int k3 = 1;

    cout << "Test Case 3" << endl;
    cout << "Input: ";
    printArray(arr3);
    cout << ", k = " << k3 << endl;

    int result3 = quickSelect(arr3, k3);

    cout << "Output: " << result3 << endl;

    return 0;
}