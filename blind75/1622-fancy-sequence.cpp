/*
LeetCode 1622. Fancy Sequence
Optimal approach: maintain global affine transform f(x) = x * mul + add (mod M).
For append(val), store a normalized value so future transforms can be applied lazily.
Each operation is O(1).
*/

#include <bits/stdc++.h>
using namespace std;

class Fancy
{
    static constexpr long long MOD = 1000000007LL;

    vector<long long> base;
    long long mul = 1;
    long long add = 0;

    long long modPow(long long a, long long e)
    {
        long long r = 1;
        a %= MOD;
        while (e > 0)
        {
            if (e & 1LL)
                r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1LL;
        }
        return r;
    }

    long long modInv(long long x)
    {
        return modPow((x % MOD + MOD) % MOD, MOD - 2);
    }

public:
    Fancy() = default;

    void append(int val)
    {
        long long v = (val % MOD + MOD) % MOD;
        long long normalized = (v - add + MOD) % MOD;
        normalized = (normalized * modInv(mul)) % MOD;
        base.push_back(normalized);
    }

    void addAll(int inc)
    {
        add = (add + inc) % MOD;
        if (add < 0)
            add += MOD;
    }

    void multAll(int m)
    {
        long long mm = (m % MOD + MOD) % MOD;
        mul = (mul * mm) % MOD;
        add = (add * mm) % MOD;
    }

    int getIndex(int idx)
    {
        if (idx < 0 || idx >= (int)base.size())
            return -1;
        long long ans = (base[idx] * mul + add) % MOD;
        return (int)ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Quick sanity demo (same style as LC examples)
    Fancy fancy;
    fancy.append(2);                   // [2]
    fancy.addAll(3);                   // [5]
    fancy.append(7);                   // [5,7]
    fancy.multAll(2);                  // [10,14]
    cout << fancy.getIndex(0) << "\n"; // 10
    fancy.addAll(3);                   // [13,17]
    fancy.append(10);                  // [13,17,10]
    fancy.multAll(2);                  // [26,34,20]
    cout << fancy.getIndex(0) << "\n"; // 26
    cout << fancy.getIndex(1) << "\n"; // 34
    cout << fancy.getIndex(2) << "\n"; // 20

    return 0;
}
