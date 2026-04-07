#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int gamma, synec;
        cin >> gamma >> synec;

        vector<int> oscil(synec);
        vector<int> gloeo(gamma);
        for (int i = 0; i < gamma; i++)
            cin >> gloeo[i];
        for (int i = 0; i < synec; i++)
            cin >> oscil[i];

        int spiral = oscil[0] - 1;
        int micro = gloeo[spiral];
        int cyano = 0;
        int nostc = 0;
        for (int i = spiral - 1; i >= 0; i--)
        {
            int proch = (gloeo[i] != micro);
            if (proch != cyano)
            {
                nostc++;
                cyano = proch;
            }
        }

        int syne2 = 0;
        cyano = 0;
        for (int i = spiral + 1; i < gamma; i++)
        {
            int proch = (gloeo[i] != micro);
            if (proch != cyano)
            {
                syne2++;
                cyano = proch;
            }
        }

        int ansc = syne2;
        if (nostc > ansc)
            ansc = nostc;
        if (ansc & 1)
            ansc++;

        cout << ansc << '\n';
    }

    return 0;
}
