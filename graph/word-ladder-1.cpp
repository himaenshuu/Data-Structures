#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // set bcoz of O(1) traversal time
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;

        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                string word = q.front();
                q.pop();

                if (word == endWord)
                {
                    return steps;
                }

                for (int j = 0; j < word.size(); j++)
                {
                    char originalchar = word[j];

                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (c == originalchar)
                            continue;

                        word[j] = c;

                        if (dict.find(word) != dict.end())
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = originalchar;
                }
            }
            steps++;
        }
        return 0; // becoz bfs is finished yet we haven't found endword
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    Solution sol;
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << result << endl;

    return 0;
}