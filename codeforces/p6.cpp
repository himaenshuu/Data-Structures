#include <bits/stdc++.h>
using namespace std;

struct Solver
{
    int n, q;
    int B;
    int words;

    vector<int> deg;
    vector<vector<int>> rowCols;
    set<pair<int, int>> ord; // (degree, row)

    vector<char> isHeavyRow;
    vector<int> heavyId;
    vector<int> heavyRows;
    vector<vector<unsigned long long>> heavyBits; // by heavy id
    vector<vector<int>> miss;                     // miss[a][b] = elements in row a not in row b (heavy-heavy only)
    vector<int> seen;
    int stamp;

    long long badCnt = 0;

    inline bool hasInHeavyById(int hid, int c) const
    {
        int idx = (c - 1) >> 6;
        int off = (c - 1) & 63;
        return (heavyBits[hid][idx] >> off) & 1ULL;
    }

    inline void setInHeavyById(int hid, int c)
    {
        int idx = (c - 1) >> 6;
        int off = (c - 1) & 63;
        heavyBits[hid][idx] |= (1ULL << off);
    }

    bool subsetRow(int u, int v)
    {
        // Is N(u) subset of N(v)?
        if (deg[u] > deg[v])
            return false;
        if (u == v)
            return true;

        if (isHeavyRow[u] && isHeavyRow[v])
        {
            return miss[heavyId[u]][heavyId[v]] == 0;
        }

        if (!isHeavyRow[v])
        {
            // Both are light (or u heavy is already rejected by deg check).
            // Use timestamp markers instead of hash lookup.
            ++stamp;
            if (stamp == INT_MAX)
            {
                fill(seen.begin(), seen.end(), 0);
                stamp = 1;
            }
            for (int c : rowCols[v])
                seen[c] = stamp;
            for (int c : rowCols[u])
            {
                if (seen[c] != stamp)
                    return false;
            }
            return true;
        }

        for (int c : rowCols[u])
        {
            if (!hasInHeavyById(heavyId[v], c))
                return false;
        }
        return true;
    }

    int badEdge(int a, int b)
    {
        if (a == -1 || b == -1)
            return 0;
        return subsetRow(a, b) ? 0 : 1;
    }

    int prevRow(set<pair<int, int>>::iterator it)
    {
        if (it == ord.begin())
            return -1;
        auto jt = it;
        --jt;
        return jt->second;
    }

    int nextRow(set<pair<int, int>>::iterator it)
    {
        auto jt = it;
        ++jt;
        if (jt == ord.end())
            return -1;
        return jt->second;
    }

    void solveOne()
    {
        cin >> n >> q;
        B = 700;
        words = (n + 63) >> 6;

        vector<pair<int, int>> queries(q);
        vector<int> cntRow(n + 1, 0);
        for (int i = 0; i < q; i++)
        {
            int r, c;
            cin >> r >> c;
            queries[i] = {r, c};
            cntRow[r]++;
        }

        deg.assign(n + 1, 0);
        rowCols.assign(n + 1, {});
        ord.clear();
        isHeavyRow.assign(n + 1, 0);
        heavyId.assign(n + 1, -1);
        heavyRows.clear();
        seen.assign(n + 1, 0);
        stamp = 1;
        badCnt = 0;

        for (int r = 1; r <= n; r++)
        {
            if (cntRow[r] > B)
            {
                heavyId[r] = (int)heavyRows.size();
                heavyRows.push_back(r);
                isHeavyRow[r] = 1;
            }
        }
        int H = (int)heavyRows.size();

        heavyBits.assign(H, vector<unsigned long long>(words, 0ULL));
        miss.assign(H, vector<int>(H, 0));

        for (int i = 1; i <= n; i++)
            rowCols[i].reserve(cntRow[i]);

        for (int i = 1; i <= n; i++)
            ord.insert({0, i});

        for (int itq = 0; itq < q; itq++)
        {
            int r = queries[itq].first;
            int c = queries[itq].second;

            // Remove old local adjacency contributions around r (old state).
            auto it = ord.find({deg[r], r});
            int p = prevRow(it);
            int nx = nextRow(it);

            badCnt -= badEdge(p, r);
            badCnt -= badEdge(r, nx);
            if (p != -1 && nx != -1)
                badCnt += badEdge(p, nx);

            ord.erase(it);

            // Apply update.
            rowCols[r].push_back(c);
            deg[r]++;

            if (isHeavyRow[r])
            {
                int hr = heavyId[r];

                // Update miss matrix for all heavy rows before setting bit in r.
                for (int j = 0; j < H; j++)
                {
                    if (j == hr)
                        continue;
                    bool hasJ = hasInHeavyById(j, c);
                    if (!hasJ)
                        miss[hr][j]++; // r \ heavyRows[j] gained c
                    else
                        miss[j][hr]--; // heavyRows[j] \ r lost c
                }

                setInHeavyById(hr, c);
            }

            // Insert and add new local adjacency contributions.
            auto it2 = ord.insert({deg[r], r}).first;
            int p2 = prevRow(it2);
            int nx2 = nextRow(it2);

            if (p2 != -1 && nx2 != -1)
                badCnt -= badEdge(p2, nx2);
            badCnt += badEdge(p2, r);
            badCnt += badEdge(r, nx2);

            cout << (badCnt == 0 ? "YES\n" : "NO\n");
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        Solver s;
        s.solveOne();
    }
    return 0;
}
