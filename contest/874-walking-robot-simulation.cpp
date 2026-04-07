#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> block;
        block.reserve(obstacles.size() * 2 + 1);

        for (const auto& ob : obstacles) {
            block.insert(encode(ob[0], ob[1]));
        }

        static const int dx[4] = {0, 1, 0, -1};
        static const int dy[4] = {1, 0, -1, 0};

        int dir = 0;
        int x = 0, y = 0;
        int best = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int step = 0; step < cmd; ++step) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (block.count(encode(nx, ny))) break;
                    x = nx;
                    y = ny;
                    best = max(best, x * x + y * y);
                }
            }
        }

        return best;
    }

private:
    static long long encode(int x, int y) {
        return (static_cast<long long>(x) << 32) ^ static_cast<unsigned int>(y);
    }
};
