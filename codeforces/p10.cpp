#include <bits/stdc++.h>
using namespace std;

struct FastScanner
{
    static const int BUFSIZE = 1 << 20;
    int idx = 0, size = 0;
    char buf[BUFSIZE];

    inline char getChar()
    {
        if (idx >= size)
        {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0)
                return 0;
        }
        return buf[idx++];
    }

    template <typename T>
    bool readInt(T &out)
    {
        char c;
        T sign = 1, val = 0;
        c = getChar();
        if (!c)
            return false;
        while (c != '-' && (c < '0' || c > '9'))
        {
            c = getChar();
            if (!c)
                return false;
        }
        if (c == '-')
        {
            sign = -1;
            c = getChar();
        }
        for (; c >= '0' && c <= '9'; c = getChar())
        {
            val = val * 10 + (c - '0');
        }
        out = val * sign;
        return true;
    }
};

int main()
{
    FastScanner fs;

    int t = 0;
    if (!fs.readInt(t))
        return 0;

    static double keep[101];
    for (int i = 0; i <= 100; ++i)
        keep[i] = 1.0 - i / 100.0;

    cout.setf(std::ios::fixed);
    cout << setprecision(10);

    while (t--)
    {
        int n = 0;
        fs.readInt(n);

        vector<int> c(n + 1), p(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            fs.readInt(c[i]);
            fs.readInt(p[i]);
        }

        double dp = 0.0;

        for (int i = n; i >= 1; --i)
        {
            double take = c[i] + keep[p[i]] * dp;
            if (take > dp)
                dp = take;
        }

        cout << dp << '\n';
    }

    return 0;
}
