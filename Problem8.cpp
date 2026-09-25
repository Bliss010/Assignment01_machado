#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct HeapNode
{
    int value;
    int arrayIndex;
    int elementIndex;

    bool operator>(const HeapNode& other) const
    {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> arrays)
{
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;

    vector<int> result;

    for (int i = 0; i < arrays.size(); i++)
    {
        if (!arrays[i].empty())
        {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    while (!minHeap.empty())
    {
        HeapNode current = minHeap.top();
        minHeap.pop();

        result.push_back(current.value);

        int nextIndex = current.elementIndex + 1;

        if (nextIndex < arrays[current.arrayIndex].size())
        {
            minHeap.push({
                arrays[current.arrayIndex][nextIndex],
                current.arrayIndex,
                nextIndex
            });
        }
    }

    return result;
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

void printInput(vector<vector<int>> arrays)
{
    cout << "[";

    for (int i = 0; i < arrays.size(); i++)
    {
        printArray(arrays[i]);

        if (i < arrays.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main()
{
    // Test Case 1
    vector<vector<int>> arrays1 =
    {
        {1,5,9},
        {2,6,10},
        {3,4,8}
    };

    cout << "Test Case 1" << endl;
    cout << "Input: ";
    printInput(arrays1);

    vector<int> result1 = mergeKSortedArrays(arrays1);

    cout << "Output: ";
    printArray(result1);

    cout << endl;


    // Test Case 2
    vector<vector<int>> arrays2 =
    {
        {2,7},
        {},
        {1,3,8},
        {4,6}
    };

    cout << "Test Case 2" << endl;
    cout << "Input: ";
    printInput(arrays2);

    vector<int> result2 = mergeKSortedArrays(arrays2);

    cout << "Output: ";
    printArray(result2);

    cout << endl;


    // Test Case 3
    vector<vector<int>> arrays3 = {};

    cout << "Test Case 3" << endl;
    cout << "Input: ";
    printInput(arrays3);

    vector<int> result3 = mergeKSortedArrays(arrays3);

    cout << "Output: ";
    printArray(result3);

    return 0;
}//all test cases in single output here