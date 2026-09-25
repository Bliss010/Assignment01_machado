#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compareNumbers(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> numbers)
{
    if (numbers.empty())
    {
        return "";
    }

    vector<string> nums;
    for (int number : numbers)
    {
        nums.push_back(to_string(number));
    }

sort(nums.begin(), nums.end(), compareNumbers);

    string answer = "";

    // Join all the strings
    for (string number : nums)
    {
        answer += number;
    }

    // when all no's 0
if (answer[0] == '0')
    {
        return "0";
    }

    return answer;
}

void printNumbers(vector<int> numbers)
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
    // Test Case 1
    //vector<int> numbers = {12, 121, 9};

    //testcase2
    //vector<int> numbers = {8, 80, 88};

    //test case3
    vector<int> numbers = {0, 0, 0};

    cout << "Input: ";
    printNumbers(numbers);

    string answer = largestNumber(numbers);

    cout << "Output: " << answer << endl;

    return 0;
}