#include <bits/stdc++.h>
using namespace std;

static const int MAXV = 900000;
static vector<string> allSuf(MAXV + 1);
static vector<int> sufLen(MAXV + 1), sufSum(MAXV + 1);
static vector<array<int, 10>> sufCnt(MAXV + 1);

static inline int digitSumInt(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

static void precompute()
{
    for (int v = 1; v <= 9; ++v)
    {
        allSuf[v] = to_string(v);
        sufLen[v] = 1;
        sufSum[v] = v;
        sufCnt[v].fill(0);
        sufCnt[v][v] = 1;
    }

    for (int v = 10; v <= MAXV; ++v)
    {
        int ds = digitSumInt(v);
        string head = to_string(v);
        allSuf[v] = head + allSuf[ds];
        sufLen[v] = (int)head.size() + sufLen[ds];
        sufSum[v] = ds + sufSum[ds];
        sufCnt[v] = sufCnt[ds];
        for (char c : head)
            sufCnt[v][c - '0']++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = (int)s.size();

        array<int, 10> cnt{};
        long long totalSum = 0;
        for (char c : s)
        {
            int d = c - '0';
            cnt[d]++;
            totalSum += d;
        }

        if (n == 1)
        {
            cout << s << '\n';
            continue;
        }

        bool found = false;
        string answer;

        for (int v = 1; v <= 9 * n && !found; ++v)
        {
            int remLen = n - sufLen[v];
            if (remLen < 2)
                continue;

            bool ok = true;
            for (int d = 0; d <= 9; ++d)
            {
                if (sufCnt[v][d] > cnt[d])
                {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;

            long long remSum = totalSum - sufSum[v];
            if (remSum != v)
                continue;

            array<int, 10> rem = cnt;
            for (int d = 0; d <= 9; ++d)
                rem[d] -= sufCnt[v][d];

            int first = -1;
            for (int d = 1; d <= 9; ++d)
            {
                if (rem[d] > 0)
                {
                    first = d;
                    break;
                }
            }
            if (first == -1)
                continue;

            string x0;
            x0.reserve(remLen);
            x0.push_back(char('0' + first));
            rem[first]--;

            for (int d = 0; d <= 9; ++d)
            {
                x0.append(rem[d], char('0' + d));
            }

            answer = x0 + allSuf[v];
            found = true;
        }

        cout << answer << '\n';
    }

    return 0;
}
