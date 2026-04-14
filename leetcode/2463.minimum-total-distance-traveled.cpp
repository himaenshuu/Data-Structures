/*
 * @lc app=leetcode id=2463 lang=cpp
 *
 * [2463] Minimum Total Distance Traveled
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <deque>
#include <limits>
#include <utility>
#include <vector>

class Solution {
public:
    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());

        const int n = static_cast<int>(robot.size());
        const long long INF = std::numeric_limits<long long>::max() / 4;

        std::vector<long long> prev(n + 1, INF), cur(n + 1, INF), prefix(n + 1, 0);
        prev[0] = 0;

        for (const auto& f : factory) {
            const int pos = f[0];
            const int limit = f[1];

            for (int j = 1; j <= n; ++j) {
                prefix[j] = prefix[j - 1] + std::llabs(static_cast<long long>(robot[j - 1]) - pos);
            }

            std::deque<std::pair<int, long long>> dq;
            std::fill(cur.begin(), cur.end(), INF);

            for (int j = 0; j <= n; ++j) {
                const long long candidate = prev[j] - prefix[j];
                while (!dq.empty() && dq.back().second >= candidate) dq.pop_back();
                dq.push_back({j, candidate});

                while (!dq.empty() && dq.front().first < j - limit) dq.pop_front();

                cur[j] = prefix[j] + dq.front().second;
            }

            prev.swap(cur);
        }

        return prev[n];
    }
};
// @lc code=end

