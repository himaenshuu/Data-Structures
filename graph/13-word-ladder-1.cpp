/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 127. Word Ladder
 * Difficulty: Hard
 * LeetCode Link: https://leetcode.com/problems/word-ladder/
 *
 * PROBLEM STATEMENT:
 * Given two words beginWord and endWord, and a dictionary wordList, return
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that: 1) only one letter can be changed at a time, 2) each
 * transformed word must exist in wordList. Return 0 if no sequence exists.
 * Constraints: 1 <= beginWord.length <= 10, wordList.length <= 5000.
 *
 * Example:
 * Input: beginWord = "hit", endWord = "cog",
 *        wordList = ["hot","dot","dog","lot","log","cog"]
 * Output: 5 (hit -> hot -> dot -> dog -> cog)
 *
 * APPROACH:
 * Algorithm: Breadth-First Search (BFS) with word transformations
 * Strategy: Use BFS to find shortest path. For each word, try changing each
 *           character to 'a'-'z' to generate neighbors. Track visited words
 *           using set for O(1) lookup. BFS level represents path length.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(M² × N) - M = word length, N = wordList size
 *                  For each word, try M positions × 26 letters, check in set
 * Space Complexity: O(M × N) - Queue + set storing all words
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Amazon, Meta, Google, Microsoft, Apple
 * Tier 2 (Tech): LinkedIn, Bloomberg, Adobe, Uber, Oracle, Salesforce
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 4/5 - Highly Recommended
 * Why: Classic BFS shortest path problem with string transformations. Tests
 *      graph modeling skills and BFS mastery. Common in mid to senior level
 *      interviews, good stretch problem for entry-level preparation.
 *
 * SIMILAR PROBLEMS: LC 126, LC 433, LC 752, LC 1129, LC 2812
 *
 * DATE SOLVED: 2026-03-23
 * LAST REVIEWED: 2026-03-23
 ******************************************************************************/

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