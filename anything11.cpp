#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int size;
        cin >> size;

        int b = 0;
        int g = 0;
        cin.ignore();
        string str;
        getline(cin, str);

        for (int i = 0; i < size; i++)
        {
            if (str[i] = 'B')
                b++;
            else
                g++;

            if (b > 2 * g)
                break;
        }
        cout << b + g << "\n";
    }
    return 0;
}
