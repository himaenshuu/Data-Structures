#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 505;

struct FastScanner {
    static const int SZ = 1 << 20;
    int index = 0, size = 0;
    char buffer[SZ];

    inline char nextChar() {
        if (index >= size) {
            size = (int)fread(buffer, 1, SZ, stdin);
            index = 0;
            if (size == 0) return 0;
        }
        return buffer[index++];
    }

    template <class T>
    bool readInt(T &out) {
        char c = nextChar();
        if (!c) return false;
        while (c <= ' ') {
            c = nextChar();
            if (!c) return false;
        }
        T value = 0;
        while (c >= '0' && c <= '9') {
            value = value * 10 + (c - '0');
            c = nextChar();
        }
        out = value;
        return true;
    }

    void read01(char *line, int n) {
        char c = nextChar();
        while (c <= ' ') {
            c = nextChar();
        }
        for (int i = 1; i <= n; i++) {
            line[i] = c;
            if (i < n) c = nextChar();
        }
    }
};

bitset<MAXN> reachFrom[MAXN], reachTo[MAXN];
char matrixData[MAXN][MAXN];
int visitedAt[MAXN], bfsQueue[MAXN];
vector<int> graphAdj[MAXN];

int main() {
    FastScanner scanner;
    int testCases;
    if (!scanner.readInt(testCases)) return 0;

    string output;
    output.reserve(1 << 20);

    while (testCases--) {
        int n = 0;
        if (!scanner.readInt(n)) break;

        for (int row = 1; row <= n; row++) {
            scanner.read01(matrixData[row], n);
        }

        for (int node = 1; node <= n; node++) {
            reachFrom[node].reset();
            reachTo[node].reset();
            graphAdj[node].clear();
        }

        bool isValid = true;
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if (matrixData[from][to] == '1') {
                    reachFrom[from].set(to);
                    reachTo[to].set(from);
                }
            }
        }

        vector<pair<int, int>> edges;
        if (isValid) {
            edges.reserve(n - 1);
            bitset<MAXN> middleNodes;

            for (int from = 1; from <= n; from++) {
                for (int to = 1; to <= n; to++) {
                    if (from == to || matrixData[from][to] != '1') continue;
                    middleNodes = reachFrom[from] & reachTo[to];
                    middleNodes.reset(from);
                    middleNodes.reset(to);
                    if (!middleNodes.any()) edges.push_back({from, to});
                }
            }

            if ((int)edges.size() != n - 1) isValid = false;
        }

        if (isValid) {
            for (auto &edge : edges) graphAdj[edge.first].push_back(edge.second);

            int bfsStamp = 1;
            for (int start = 1; start <= n && isValid; start++, bfsStamp++) {
                int head = 0, tail = 0;
                bfsQueue[tail++] = start;
                visitedAt[start] = bfsStamp;

                while (head < tail) {
                    int node = bfsQueue[head++];
                    for (int next : graphAdj[node]) {
                        if (visitedAt[next] == bfsStamp) continue;
                        visitedAt[next] = bfsStamp;
                        bfsQueue[tail++] = next;
                    }
                }

                for (int node = 1; node <= n; node++) {
                    char canReach = (visitedAt[node] == bfsStamp ? '1' : '0');
                    if (canReach != matrixData[start][node]) {
                        isValid = false;
                        break;
                    }
                }
            }
        }

        if (!isValid) {
            output += "No\n";
        } else {
            output += "Yes\n";
            for (auto &edge : edges) {
                output += to_string(edge.first);
                output += ' ';
                output += to_string(edge.second);
                output += '\n';
            }
        }
    }

    fwrite(output.c_str(), 1, output.size(), stdout);
    return 0;
}
