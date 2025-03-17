// In this code we are gonna find sum of the sum of divisors upto n 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int findsum1(int n)
{
    vector<int> divisorSum(n + 1, 0);

    // Compute sum of divisors for each number using a sieve-like method 
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisorSum[j] += i;
        }
    }

    // Compute the final sum
    return accumulate(divisorSum.begin(), divisorSum.end(), 0);
}

//t.c = O(nlog n)

int findsum(int n)
{
    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        int num = i;
        int sum = 0;

        for (int j = 1; j <= num; j++)
        {
            if (num % j == 0)
            {
                sum += j;
            }
        }
        v.push_back(sum);
    }

    int final_sum = accumulate(v.begin(), v.end(), 0);

    return final_sum;
}

//t.c = O(n^2)

int main()
{
    int n = findsum1(4);

    cout << n << endl;

    return 0;
}
