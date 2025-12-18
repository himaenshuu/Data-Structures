#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    void bfs(string beginWord,
             unordered_set<string> &dict,
             unordered_map<string, int> &dist)
    {

        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            int d = dist[word];

            for (int i = 0; i < word.size(); i++)
            {
                char old = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    if (c == old)
                        continue;
                    word[i] = c;

                    if (dict.count(word) && !dist.count(word))
                    {
                        dist[word] = d + 1;
                        q.push(word);
                    }
                }
                word[i] = old;
            }
        }
    }

    void dfs(string cur, string &endWord,
             unordered_map<string, int> &dist,
             vector<string> &path,
             vector<vector<string>> &ans)
    {

        if (cur == endWord)
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < cur.size(); i++)
        {
            string next = cur;
            char old = next[i];

            for (char c = 'a'; c <= 'z'; c++)
            {
                if (c == old)
                    continue;
                next[i] = c;

                if (dist.count(next) &&
                    dist[next] == dist[cur] + 1)
                {

                    path.push_back(next);
                    dfs(next, endWord, dist, path, ans);
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(
        string beginWord, string endWord, vector<string> &wordList)
    {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (!dict.count(endWord))
            return ans;

        unordered_map<string, int> dist;
        bfs(beginWord, dict, dist);

        vector<string> path{beginWord};
        dfs(beginWord, endWord, dist, path, ans);

        return ans;
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
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);

    // print each path on its own line
    for (const auto &path : result)
    {
        for (size_t i = 0; i < path.size(); ++i)
        {
            if (i)
                cout << " ";
            cout << path[i];
        }
        cout << endl;
    }

    return 0;
}