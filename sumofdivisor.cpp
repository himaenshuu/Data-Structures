/*
================================================================================
Sum of All Divisors (GeeksForGeeks / Coding Ninjas)
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- TCS
- Infosys
- Wipro
- Accenture
- Cognizant
- Tech Mahindra

PROBLEM STATEMENT:
Given a positive integer n, calculate the sum of the sum of divisors for all
numbers from 1 to n.

For each number i from 1 to n, find all its divisors, sum them up, and then
return the total sum of all these sums.

CONSTRAINTS:
- 1 <= n <= 10^5

EXAMPLE:
Input: n = 4
Output: 15
Explanation:
- Number 1: divisors = [1], sum = 1
- Number 2: divisors = [1, 2], sum = 3
- Number 3: divisors = [1, 3], sum = 4
- Number 4: divisors = [1, 2, 4], sum = 7
Total sum = 1 + 3 + 4 + 7 = 15

================================================================================
*/

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
        for (int j = i; j <= n; j = j + i)
        {
            divisorSum[j] += i;
        }
    }

    // Compute the final sum
    return accumulate(divisorSum.begin(), divisorSum.end(), 0);
}

// t.c = O(nlog n)

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

// t.c = O(n^2)

int main()
{
    int n = findsum1(4);

    cout << n << endl;

    return 0;
}

/*
Interviewer: "Great! And why is this better than the other approach?"

You: "The naive approach findsum is O(n²) because for each number, I check all potential divisors one by one. But with the sieve method, I'm smarter—I iterate through each divisor once and distribute it to all its multiples efficiently. This is much faster for large n!"
*/