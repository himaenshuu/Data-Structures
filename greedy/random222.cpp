#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= 1000000007;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> m(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
    }

    long long MOD = 1e9 + 7;
    int half_n = n / 2;

    // --- Step 1: Calculate the total number of valid arrays ---
    long long total_count = 1;
    for (int i = 0; i < n; ++i)
    {
        long long row_ones = 0;
        for (char c : m[i])
        {
            if (c == '1')
            {
                row_ones++;
            }
        }
        total_count = (total_count * row_ones) % MOD;
    }

    // --- Step 2: Count "bad" arrays using an O(N^3) Dynamic Programming approach ---
    // An array is "bad" if for all k, D_k >= D_{N/2}/2, where D_k is the prefix sum
    // of differences B_i = A[i] - A[i+N/2].

    // Precompute counts for each possible difference B_i = A[i] - A[i+N/2]
    // This part is O(N^3)
    int diff_range = n - 1;
    vector<vector<long long>> diff_counts(half_n, vector<long long>(2 * diff_range + 1, 0));
    for (int i = 0; i < half_n; ++i)
    {
        for (int v = 1; v <= n; ++v)
        {
            if (m[i][v - 1] == '1')
            {
                for (int w = 1; w <= n; ++w)
                {
                    if (m[i + half_n][w - 1] == '1')
                    {
                        diff_counts[i][v - w + diff_range]++;
                    }
                }
            }
        }
    }

    // DP state: dp[i][s] = number of ways to choose first i difference terms (B_0..B_{i-1})
    // such that their sum is s.
    // This DP calculates the number of unconstrained paths.
    int max_sum_diff = half_n * diff_range;
    vector<vector<long long>> dp(half_n + 1, vector<long long>(2 * max_sum_diff + 1, 0));
    dp[0][max_sum_diff] = 1;

    // This DP is O(N^4) naively, but O(N^3) because the range of sums grows with i.
    // At step i, the sum is at most i * diff_range.
    for (int i = 0; i < half_n; ++i)
    {
        for (int s = -i * diff_range; s <= i * diff_range; ++s)
        {
            if (dp[i][s + max_sum_diff] == 0)
                continue;
            for (int d = -diff_range; d <= diff_range; ++d)
            {
                if (diff_counts[i][d + diff_range] > 0)
                {
                    int next_s = s + d;
                    dp[i + 1][next_s + max_sum_diff] = (dp[i + 1][next_s + max_sum_diff] + dp[i][s + max_sum_diff] * diff_counts[i][d + diff_range]) % MOD;
                }
            }
        }
    }

    // Now, count bad paths using another DP with the Reflection Principle.
    // Let f(i, s, L) be the number of paths of length i to sum s that stay at or above barrier L.
    // f(i, s, L) = dp[i][s] - (# paths from (0, 2L-s_0) to (i,s))
    // This is complex. A simpler DP is to count constrained paths directly.
    long long bad_count = 0;

    // Iterate over all possible final sums D_{N/2}
    for (int final_sum = -max_sum_diff; final_sum <= 0; ++final_sum)
    {
        if (dp[half_n][final_sum + max_sum_diff] == 0)
            continue;

        // For a given final_sum, the barrier is L = ceil(final_sum / 2.0)
        int lower_bound = (final_sum + 1) / 2; // Equivalent to ceil
        if (final_sum % 2 != 0 && final_sum < 0)
        { // C++ integer division behavior
            lower_bound = final_sum / 2;
        }
        if (final_sum % 2 == 0)
        {
            lower_bound = final_sum / 2;
        }

        vector<vector<long long>> constrained_dp(half_n + 1, vector<long long>(2 * max_sum_diff + 1, 0));

        if (0 >= lower_bound)
        {
            constrained_dp[0][max_sum_diff] = 1;
        }

        for (int i = 0; i < half_n; ++i)
        {
            for (int s = -i * diff_range; s <= i * diff_range; ++s)
            {
                if (constrained_dp[i][s + max_sum_diff] == 0)
                    continue;
                for (int d = -diff_range; d <= diff_range; ++d)
                {
                    if (diff_counts[i][d + diff_range] > 0)
                    {
                        int next_s = s + d;
                        if (next_s >= lower_bound)
                        {
                            constrained_dp[i + 1][next_s + max_sum_diff] = (constrained_dp[i + 1][next_s + max_sum_diff] + constrained_dp[i][s + max_sum_diff] * diff_counts[i][d + diff_range]) % MOD;
                        }
                    }
                }
            }
        }
        bad_count = (bad_count + constrained_dp[half_n][final_sum + max_sum_diff]) % MOD;
    }

    long long good_count = (total_count - bad_count + MOD) % MOD;
    cout << good_count << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
