#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// array hashing

vector<int> hashing1(const vector<int> &nums)
{
    int max_el = *max_element(nums.begin(), nums.end());

    vector<int> v(max_el + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        v[nums[i]]++;
    }
    return v;
}

// character hashing

vector<int> hashing2(string s)
{
    vector<int> v(256, 0);

    for (int i = 0; i < s.size(); i++)
    {
        v[s[i]]++;
    }
    return v;
}

// here we will see precomputing and hashing

vector<ll> findfactorial(vector<ll> &vect)
{
    // We will precompute the factorial for all

    int N = 1e5; // which means 10 rasie to 5

    ll fact[N + 1];
    fact[0] = fact[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 0; i < vect.size(); i++)
    {
        vect[i] = fact[vect[i]];
    }
    return vect;
}

int main()
{
    // vector<int> v = hashing1({1, 2, 3, 2, 3, 7, 8, 8});
    // cout << v[3] << endl;

    // vector<int> v2 = hashing2("abcabc");
    // cout << v2['a'] << endl;

    vector<ll> v1{1, 2, 15, 4, 5};
    vector<ll> v2 = findfactorial(v1);

    for (auto el : v2)
    {
        cout << el << " ";
    }

    return 0;
}