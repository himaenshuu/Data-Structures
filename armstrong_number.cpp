#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

bool checkarmstrong(int n)
{
    int size = log10(n) + 1;
    cout << "size is " << size << endl;

    int sum = 0;
    int flag = n;

    while (n > 0) // t.c = O(log n);
    {
        int digit = n % 10;
        // int z = pow(digit, size);
        int z = 1;
        for (int i = 0; i < size; i++)
        {
            z = z * digit;
        }
        sum = sum + z;
        n = n / 10;
    }

    return sum == flag;
}

//t.c = O(log n)^2

int main()
{
    int n;
    cin >> n;
    // checkarmstrong(n);
    if (checkarmstrong(n))
    {
        cout << "it is a armstrong number" << endl;
    }
    else
    {
        cout << "Not a armstrong number" << endl;
    }

    return 0;
}