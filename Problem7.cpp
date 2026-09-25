#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int> numbers, int k)
{
    if (k == 0 || numbers.empty())
    {
        return {};
    }

    unordered_map<int, int> frequency;

    for (int number : numbers)
    {
        frequency[number]++;
    }
    vector<pair<int, int>> items;

    for (auto item : frequency)
    {
        items.push_back({item.first, item.second});
    }

    // Sortin
    sort(items.begin(), items.end(),
        [](pair<int, int> a, pair<int, int> b)
        {
            if (a.second != b.second)
            {
                return a.second > b.second;
            }

            return a.first < b.first;
        });

    vector<int> result;

    for (int i = 0; i < k && i < items.size(); i++)
    {
        result.push_back(items[i].first);
    }

    return result;
}

void printArray(vector<int> numbers)
{
    cout << "[";

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i];

        if (i < numbers.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main()
{
    //vector<int> numbers = {
    //    5, 5, 5, 2, 2, 7, 7, 7, 7
    //};

    //int k = 2;
//testcase2
 //   vector<int> numbers = {
 //   6, 6, 3, 3, 9, 9, 1, 1
//};

//int k = 3;
//testcase 3
vector<int> numbers = {};

int k = 0;

    cout << "Input: ";
    printArray(numbers);

    cout << "K: " << k << endl;

    vector<int> result = topKFrequent(numbers, k);

    cout << "Output: ";
    printArray(result);

    return 0;
}