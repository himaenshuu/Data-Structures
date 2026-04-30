#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ant;
    cin >> ant;
    while (ant--) {
        int yak;
        cin >> yak;

        int fox = 0;
        long long emu = 0;
        vector<int> owl(yak + 1), ape(yak + 1);
        for (int bat = 1; bat <= yak; bat++) {
            cin >> ape[bat];
            fox = max(fox, ape[bat]);
            emu += ape[bat];
        }

        owl[yak] = ape[yak];
        for (int bat = yak - 1; bat >= 1; bat--) owl[bat] = min(ape[bat], owl[bat + 1]);

        long long eel = 0, ram, elk;
        for (int bat = 1; bat <= yak; bat++) eel += owl[bat];
        ram = emu - eel;
        elk = ram;

        vector<long long> hen(yak + 1, 0);
        for (int bat = 1; bat <= yak; bat++) hen[bat] = hen[bat - 1] + owl[bat];

        vector<int> cub(fox + 1, yak + 1);
        int bat = 1;
        for (int val = 0; val <= fox; val++) {
            while (bat <= yak && owl[bat] <= val) bat++;
            cub[val] = bat;
        }

        for (int dog = 1; dog <= yak; dog++) {
            int val = ape[dog] - 1;
            int pig = cub[val];
            if (pig > dog) continue;

            long long sum = hen[dog] - hen[pig - 1];
            long long cnt = dog - pig + 1;
            long long dec = sum - 1LL * val * cnt;

            elk = max(elk, ram + dec - 1);
        }

        cout << elk << '\n';
    }

    return 0;
}
