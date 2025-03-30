#include <bits/stdc++.h>
using namespace std;

int main()
{
	// your code goes here
	int t, n, a;
	cin >> t;
	while (t--)
	{
		vector<int> v;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			v.push_back(a);
		}
		if (n % 2 != 0 && n % 3 == 0)
		{
			cout << v[n / 2];
		}
		else
		{
			if (n % 2 == 0 && n % 3 == 0)
			{
				cout << v[0] << " " << v.end();
			}
			else
			{
				cout << v.begin() + v.end();
			}
		}
	}
}
