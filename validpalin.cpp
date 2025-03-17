#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

bool checkpalindrone(string s)
{
    int i = 0, j = s.size() - 1;
    while(i<j){
        while(!isalnum(s[i]))
            i++;
        while(!isalnum(s[j]))
            j--;
        
        if(tolower(s[i])!=tolower(s[j])) return false;

        i++;
        j--;
    }
}

int main()
{

    string s;
    cout << "Enter a string" << endl;
    cin >> s;

    if(checkpalindrone(s)) cout << "String is a palindrome" << endl;
    else cout << "String is not a palindrome" << endl;

    return 0;
}