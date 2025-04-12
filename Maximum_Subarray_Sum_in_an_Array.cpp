#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
#define endl "\n"

int maxvalue(vector<int> &arr)
{
    int max = INT_MIN;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        int sum = arr[i];
        max = (sum > max) ? sum : max;
        for (int j = i + 1; j < size; j++)
        {
            sum += arr[j];
            if (sum > max)
                max = sum;
        }
    }

    return max > 0 ? max : 0;
}
// T.C = O(n^2) S.C = O(1)

// In previous one while adding we are carrying the negative sum too , 
// but kadane's algorithm says why to carry negative sum , if it 
// do not contribute in the maximum sum .
// We will improve this part and make negative sum zero

int maxvalue1(vector<int> &arr)
{
    int max = INT_MIN;
    int size = arr.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        max = (sum > max) ? sum : max;
    }

    return max > 0 ? max : 0;
}

// T.c = O(n) S.C = O(1)

int main()
{
    vi v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxvalue(v) << endl;
    return 0;
}