#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void merge(vector<int> &v, int low, int mid, int high)
{
    vector<int> temp; // create a temporary array to store the merged array
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (v[left] < v[right])
        {
            temp.push_back(v[left]);
            left++;
        }

        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(v[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(v[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        v[i] = temp[i - low];
    }
}

void mergesort(vector<int> &v, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;

    mergesort(v, low, mid);
    mergesort(v, mid + 1, high);
    merge(v, low, mid, high);
}
// It is a postorder-traversal
// T.c = O(n log n) - it uses binary tree

int main()
{
    vector<int> v = {4, 2, 5, 1, 3, 6,5,1};
    mergesort(v, 0, v.size() - 1);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
