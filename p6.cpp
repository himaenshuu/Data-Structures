#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vect = {1, 2, 3, 3, 6, 4};
    vector<int> query = {1, 2, 3};
    vector<int> hash;

    int count = 0;
    for (int i = 0; i < query.size(); i++)
    {
        for (int j = 0; j < vect.size(); j++)
        {
            if (query[i] == vect[j])
            {
                count++;
            }
        }

        hash.push_back(count);
        count = 0;
    }

    cout << "Hash_Table" << "\n";
    for (auto el : hash)
    {
        cout << el << " ";
    }

    return 0;
}