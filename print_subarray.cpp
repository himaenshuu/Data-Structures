// We are finding subarray with maximum sum

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> printsubarray(vector<int> &vect)
{
    int n = vect.size();

    int max = INT_MIN;
    int sum = 0;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        vector<int> v1;
        for (int j = i; j < n; j++)
        {
            v1.push_back(vect[j]);
            sum += vect[j];
            if (sum > max)
            {
                v = v1;
                max = sum;
            }
        }
    }
    return v;
}

int subarraySum(vector<int> &vect)
{
    int n = vect.size();

    int max = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += vect[j];
            if (sum > max)
                max = sum;
        }

        // max = (sum > max) ? sum : max;
    }
    return max;
}

int main()
{
    int size;
    cin >> size;
    vector<int> vect(size);

    for (int i = 0; i < size; i++)
    {
        cin >> vect[i];
    }

    vector<int> v = printsubarray(vect);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
