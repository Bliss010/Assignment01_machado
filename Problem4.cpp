#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words)
{
    unordered_map<string, vector<string>> groups;

    for (string word : words)
    {
        string key = word;
        sort(key.begin(), key.end());
        groups[key].push_back(word);
    }

    vector<vector<string>> result;

    
    for (auto group : groups)
    {
        result.push_back(group.second);
    }

    return result;
}

void printGroups(vector<vector<string>> groups)
{
    cout << "[" << endl;

    for (int i = 0; i < groups.size(); i++)
    {
        cout << "  [";

        for (int j = 0; j < groups[i].size(); j++)
        {
            cout << "\"" << groups[i][j] << "\"";

            if (j < groups[i].size() - 1)
            {
                cout << ", ";
            }
        }

        cout << "]";

        if (i < groups.size() - 1)
        {
            cout << ",";
        }

        cout << endl;
    }

    cout << "]" << endl;
}

int main()
//{
   // vector<string> words = {
     //   "dust",
      //  "stud",
      //  "loop",
      //  "pool",
      //  "cat",
       // "tac"
   // };

    {
    vector<string> words = {
        "save", "vase", "evil", "live", "stone"
    };

    cout << "Input: [";

    for (int i = 0; i < words.size(); i++)
    {
        cout << "\"" << words[i] << "\"";

        if (i < words.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    vector<vector<string>> result = groupAnagrams(words);

    cout << "Output:" << endl;
    printGroups(result);

    return 0;
}