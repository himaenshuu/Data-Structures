#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// Approach (Word Ladder II, optimized to avoid TLE):
// 1) Precompute a pattern index: for each word of length L, for each position i, replace
//    char i with '*' to form a wildcard key; map key -> list of words sharing that pattern.
//    Neighbor lookup becomes O(L * degree) instead of 26 * L mutations.
// 2) Run a single-source BFS from beginWord with a distance map. Track parents only along
//    shortest distances. Once endWord is reached at distance d, prune any expansion deeper
//    than d to avoid extra work.
// 3) Parents map stores for each node all predecessors on shortest paths. After BFS, DFS
//    from endWord back to beginWord using parents, collect paths, then reverse each path
//    for output. This enumerates all shortest ladders without exploring longer ones.

class Solution
{
public:
    vector<vector<string>> findLadders(
        string beginWord, string endWord, vector<string> &wordList)
    {

        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
        if (!dict.count(endWord))
            return result;

        unordered_map<string, vector<string>> parents; // child -> list of parents

        // Precompute pattern index for efficient neighbor generation
        const int L = (int)beginWord.size();
        auto patternIndex = buildPatternIndex(wordList, beginWord, endWord, L);

        // Single-side BFS with distance map; only keep shortest parents
        unordered_map<string, int> dist;
        queue<string> q;
        dist[beginWord] = 0;
        q.push(beginWord);
        int shortest = INT_MAX;

        while (!q.empty())
        {
            string word = q.front();
            q.pop();
            int d = dist[word];
            if (d + 1 > shortest)
                continue; // prune levels beyond shortest found

            for (const string &nei : getNeighbors(word, patternIndex, L))
            {
                if (!dict.count(nei) && nei != endWord)
                    continue; // skip words not in dict (except endWord)

                if (!dist.count(nei))
                {
                    dist[nei] = d + 1;
                    q.push(nei);
                    parents[nei].push_back(word);
                    if (nei == endWord)
                        shortest = d + 1;
                }
                else if (dist[nei] == d + 1)
                {
                    parents[nei].push_back(word); // another shortest parent
                }
            }
        }

        if (!dist.count(endWord))
            return result;

        vector<string> path{endWord};
        buildPathsReverse(endWord, beginWord, parents, path, result);
        for (auto &p : result)
            reverse(p.begin(), p.end());
        return result;
    }

private:
    // Build mapping from wildcard patterns to words
    unordered_map<string, vector<string>> buildPatternIndex(const vector<string> &wordList,
                                                            const string &beginWord,
                                                            const string &endWord,
                                                            int L)
    {
        unordered_map<string, vector<string>> index;
        auto addWord = [&](const string &w)
        {
            if ((int)w.size() != L)
                return; // only words of same length
            string pat = w;
            for (int i = 0; i < L; ++i)
            {
                char old = pat[i];
                pat[i] = '*';
                index[pat].push_back(w);
                pat[i] = old;
            }
        };
        for (const auto &w : wordList)
            addWord(w);
        addWord(beginWord);
        addWord(endWord);
        return index;
    }

    // Enumerate neighbors using precomputed patterns
    vector<string> getNeighbors(const string &word,
                                unordered_map<string, vector<string>> &index,
                                int L)
    {
        vector<string> neighbors;
        neighbors.reserve(32);
        string pat = word;
        unordered_set<string> seen;
        for (int i = 0; i < L; ++i)
        {
            char old = pat[i];
            pat[i] = '*';
            auto it = index.find(pat);
            if (it != index.end())
            {
                for (const auto &cand : it->second)
                {
                    if (cand != word && seen.insert(cand).second)
                        neighbors.push_back(cand);
                }
            }
            pat[i] = old;
        }
        return neighbors;
    }
    void addEdge(unordered_map<string, vector<string>> &parents,
                 string from, string to, bool reversed)
    {
        // Always direct edges from begin side toward end side
        // If we expanded the end side (reversed == true), flip the edge
        if (reversed)
            parents[to].push_back(from);
        else
            parents[from].push_back(to);
    }

    void buildPathsReverse(string cur, string &beginWord,
                           unordered_map<string, vector<string>> &parents,
                           vector<string> &path,
                           vector<vector<string>> &result)
    {
        if (cur == beginWord)
        {
            result.push_back(path);
            return;
        }

        for (auto &p : parents[cur])
        {
            path.push_back(p);
            buildPathsReverse(p, beginWord, parents, path, result);
            path.pop_back();
        }
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