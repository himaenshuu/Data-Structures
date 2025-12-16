#ifndef UTILITIES_H
#define UTILITIES_H
#include <vector>
#include <iostream>
using namespace std;

inline void print1darray(vector<int> vect)
{
    for (auto &el : vect)
    {
        cout << el << " ";
    }
    cout << "\n";
}

inline void print2darray(vector<vector<int>> vect)
{
    for (auto &row : vect)
    {
        for (auto &el : row)
        {
            cout << el << " ";
        }
        cout << "\n";
    }
}

#endif