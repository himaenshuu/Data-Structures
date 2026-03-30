/*
Problem (design question, paraphrased):
Implement an `EventManager` that tracks events by `eventId` and `priority`.
- Constructor takes an initial list of events `[eventId, priority]`.
- `updatePriority(eventId, newPriority)` updates an existing event's priority.
- `pollHighest()` removes and returns the `eventId` with the highest priority; if multiple share the highest priority, return the smallest `eventId`. If no events remain, return -1.

Difficulty: Medium

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Uber, Bloomberg, LinkedIn, Salesforce, Oracle

Entry-level importance: Medium

Optimal approach used here:
- Max-heap (priority queue) ordered by (priority desc, eventId asc).
- Lazy deletion via a hash map `mp[eventId] = currentPriority` so outdated heap entries are skipped during `pollHighest()`.

Time complexity:
- Constructor: O(n log n)
- `updatePriority`: O(log n)
- `pollHighest`: O(log n) amortized (may pop stale entries)
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class EventManager
{
public:
    vector<vector<int>> ev;
    struct cmp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    unordered_map<int, int> mp;
    EventManager(vector<vector<int>> &events)
    {
        for (int i = 0; i < events.size(); i++)
        {
            pq.push({events[i][0], events[i][1]});
            mp[events[i][0]] = events[i][1];
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        if (mp.count(eventId))
        {
            pq.push({eventId, newPriority});
            mp[eventId] = newPriority;
        }
    }

    int pollHighest()
    {
        while (!pq.empty())
        {
            auto [x, y] = pq.top();
            pq.pop();
            if (mp[x] == y) // If not equal means, it is old one
            {
                mp.erase(x);
                return x;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto expectPoll = [](EventManager &mgr, int expected)
    {
        int got = mgr.pollHighest();
        if (got != expected)
        {
            cerr << "Expected pollHighest()=" << expected << ", got " << got << "\n";
            assert(false);
        }
    };

    // Test case 1: Basic ordering + empty poll.
    {
        vector<vector<int>> events = {{1, 10}, {2, 5}, {3, 7}};
        EventManager mgr(events);
        expectPoll(mgr, 1);
        expectPoll(mgr, 3);
        expectPoll(mgr, 2);
        expectPoll(mgr, -1);
    }

    // Test case 2: Tie-break on same priority (smaller eventId first).
    {
        vector<vector<int>> events = {{10, 3}, {5, 3}, {7, 2}};
        EventManager mgr(events);
        expectPoll(mgr, 5);
        expectPoll(mgr, 10);
        expectPoll(mgr, 7);
        expectPoll(mgr, -1);
    }

    cout << "All 2 test cases passed." << endl;

    return 0;
}
/*
class EventManager
{
public:
    vector<vector<int>> ev;
    struct cmp
    {
        bool operator()(pair<int, int> &a, pair<int, int> &b)
        {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    EventManager(vector<vector<int>> &events)
    {
        for (int i = 0; i < events.size(); i++)
        {
            pq.push({events[i][0], events[i][1]});
        }
    }

    void updatePriority(int eventId, int newPriority)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq1;

        while (!pq.empty())
        {
            int x = pq.top().first;
            int y = pq.top().second;

            pq.pop();

            if (x == eventId)
            {
                pq1.push({x, newPriority});
            }
            else
                pq1.push({x, y});
        }
        pq = pq1;
    }

    int pollHighest()
    {
        if (pq.empty())
            return -1;
        int eventId = pq.top().first;
        pq.pop();
        return eventId;
    }
};
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
*/