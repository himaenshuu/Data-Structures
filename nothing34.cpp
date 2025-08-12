#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

bool is_balanced(const vector<vector<int>> &prefix, int L, int R)
{
    int freq = -1;
    for (int c = 0; c < ALPHABET_SIZE; ++c)
    {
        int count = prefix[R][c] - prefix[L - 1][c];
        if (count > 0)
        {
            if (freq == -1)
            {
                freq = count;
            }
            else if (freq != count)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;
    S = " " + S; // 1-indexed

    vector<vector<int>> prefix(N + 1, vector<int>(ALPHABET_SIZE, 0));
    for (int i = 1; i <= N; ++i)
    {
        for (int c = 0; c < ALPHABET_SIZE; ++c)
        {
            prefix[i][c] = prefix[i - 1][c];
        }
        prefix[i][S[i] - 'a']++;
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int L, R;
        cin >> L >> R;
        cout << (is_balanced(prefix, L, R) ? "YES" : "NO") << endl;
    }

    return 0;
}
