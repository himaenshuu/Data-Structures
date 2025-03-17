#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<int> selection_sort(vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size - 1; i++)
    {
        /* int min = *min_element(v.begin() + i, v.end());
           auto it = find(v.begin() + i, v.end(), min);
           swap(v[i], *it);
        */
        int min = v[i], k = i;
        for (int j = i; j < size; j++)
        {
            if (v[j] < min)
            {
                min = v[j];
                k = j;
            }
        }
        swap(v[i], v[k]);
    }
    return v;
}

vector<int> bubble_sort(vector<int> &v)
{
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
    return v;
}
// t.c=O(n^2)

vector<int> insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i <= n; i++)
    {
        int j = i;

        while (j > 0 && v[j - 1] > v[j])
        {
            swap(v[j - 1], v[j]);
            j--;
        }
    }
    return v;
}
// t.c=O(n^2)

int main()
{
    vector<int> v = {5, 2, 8, 1, 9};
    vector<int> v1 = selection_sort(v);
    vector<int> v2 = bubble_sort(v);
    vector<int> v3 = insertion_sort(v);

    for (auto el : v3)
    {
        cout << el << " ";
    }

    return 0;
}