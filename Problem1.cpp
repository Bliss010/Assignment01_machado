#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
if (intervals.empty())
    {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= current[1])
        {
            current[1] = max(current[1], intervals[i][1]);
        }
    else
        {
            result.push_back(current);
            current = intervals[i];
        }
    }

    result.push_back(current);

    return result;
}

    void printIntervals(vector<vector<int>> intervals)
{
    cout << "[";

    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "[" << intervals[i][0]
             << "," << intervals[i][1] << "]";

        if (i < intervals.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]" << endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
vector<vector<int>> intervals = {
       // {1, 3},
       // {6, 8},
       // {10, 12}
       //test case 2 
       //{1,3}, {6,8}, {10,12}
       //test case 3
       {2,4}, {4,7}
    };

vector<vector<int>> result = mergeIntervals(intervals);

cout << "Input: ";
printIntervals(intervals);

cout << "Output: ";
printIntervals(result);

    return 0;
}