#include <iostream>
#include <vector>

using namespace std;

void sortCounting(vector<int>& arr)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    // Count 0, 1 and 2
    for (int value : arr)
    {
        if (value == 0)
        {
            count0++;
        }
        else if (value == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

  
int index = 0;

for (int i = 0; i < count0; i++)
    {
        arr[index] = 0;
        index++;
    }

for (int i = 0; i < count1; i++)
    {
        arr[index] = 1;
        index++;
    }

    for (int i = 0; i < count2; i++)
    {
        arr[index] = 2;
        index++;
    }
}

//dutch
void sortDutch(vector<int>& arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
    else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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

    cout << "]" << endl;
}

int main()
{
    // Test Case 1
    //vector<int> arr = {1, 2, 0, 2, 1, 0};
    //Test case 2
//   vector<int> arr = {2, 1, 0, 2, 0, 1};
    //test case 3
    vector<int> arr = {2};
    cout << "Input: ";
    printArray(arr);

    vector<int> countingArray = arr;
    vector<int> dutchArray = arr;

    sortCounting(countingArray);
    sortDutch(dutchArray);

    cout << "Counting Output: ";
    printArray(countingArray);

    cout << "Dutch National Flag Output: ";
    printArray(dutchArray);

    return 0;
}