#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int distanceSquared(vector<int> point)
{
    return point[0] * point[0] + point[1] * point[1];
}

// Sorting solution
vector<vector<int>> kClosestBySorting(vector<vector<int>> points, int k)
{
    if (k == 0)
    {
        return {};
    }

    sort(points.begin(), points.end(),
        [](vector<int> a, vector<int> b)
        {
            return distanceSquared(a) < distanceSquared(b);
        });

    vector<vector<int>> result;

    for (int i = 0; i < k; i++)
    {
        result.push_back(points[i]);
    }

    return result;
}

// Heap solution here
vector<vector<int>> kClosestByHeap(vector<vector<int>> points, int k)
{
    if (k == 0)
    {
        return {};
    }

    priority_queue<pair<int, vector<int>>> maxHeap;

    for (vector<int> point : points)
    {
        int distance = distanceSquared(point);

        maxHeap.push({distance, point});

        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }

    vector<vector<int>> result;

    while (!maxHeap.empty())
    {
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return result;
}

void printPoints(vector<vector<int>> points)
{
    cout << "[";

    for (int i = 0; i < points.size(); i++)
    {
        cout << "(" << points[i][0]
             << "," << points[i][1] << ")";

        if (i < points.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "]" << endl;
}

int main()
{
  //  vector<vector<int>> points = {
     //   {4, 1},
     //   {-1, 1},
      //  {5, 2}
   // };

   // int k = 1;

    //test case 2
   // vector<vector<int>> points = {
  //  {2, 2},
   // {-3, 1},
   // {1, 0},
   // {4, -2}
//};

//int k = 2;

//testcase 3
vector<vector<int>> points = {
    {3, 4},
    {1, 1}
};

int k = 0;
    cout << "Input: ";
    printPoints(points);

    cout << "K: " << k << endl;

    vector<vector<int>> sortingResult =
        kClosestBySorting(points, k);

    vector<vector<int>> heapResult =
        kClosestByHeap(points, k);

    cout << "Sorting Output: ";
    printPoints(sortingResult);

    cout << "Heap Output: ";
    printPoints(heapResult);

    return 0;
}