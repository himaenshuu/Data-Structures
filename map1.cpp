#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    map<int, string> m; // map is a container in C++ that stores elements in a key-value pair.
    // Here, int is the key and string is the value. Also u can put vector or any other thing inplace of these two
    m[1] = "abc"; // T.C = O(logn)
    m[2] = "bcd";
    m.insert({4, "efg"});

    for (auto &el : m)
    {
        cout << el.first << " " << el.second << "\n";
    }

    auto it = m.find(3); // basically it returns an iterator and it will return an end eterator if no value found
    if (it != m.end())
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
    else
        cout << "NO VALUE";
    return 0;
}

// further m.erase() -- erases the element from the map
/*
auto it = find(k);
it works like if (it!=m.end()){
    m.erase(it);
}
    delete it only if it exists
*/

/*
1. uses a self balancing tree - rb tree
2. Unique keys are stored and stored in sorted order
*/
use case-->
It is used in where we have to store data in a sorted order and we have to search data in O(logn)

// for double conversion add .0 at the end of the number