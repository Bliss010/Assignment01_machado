#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAttendMeetings(vector<vector<int>> meetings)
{
    if (meetings.empty())
    {
        return true;
    }
    sort(meetings.begin(), meetings.end());
    for (int i = 1; i < meetings.size(); i++)
    {
        if (meetings[i][0] < meetings[i - 1][1])
        {
        return false;
        }
    }

    return true;
}

void printMeetings(vector<vector<int>> meetings)
{
    cout << "[";

    for (int i = 0; i < meetings.size(); i++)
    {
    cout << "[" << meetings[i][0]
             << "," << meetings[i][1] << "]";

        if (i < meetings.size() - 1)
        {
            cout << ",";
        }
    }

cout << "]" << endl;
}

int main()
{
    //vector<vector<int>> meetings = {
      //  {1, 4},
      //  {6, 9},
      //  {10, 13}
    //};
//testcase2
  //  vector<vector<int>> meetings = {
   // {2, 7},
   // {5, 9},
    //{10, 12}
//};

//testcase3
vector<vector<int>> meetings = {
    {3, 6},
    {6, 8},
    {8, 11}
};

    cout << "Input: ";
    printMeetings(meetings);

    bool result = canAttendMeetings(meetings);

    cout << "Output: ";

    if (result)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}