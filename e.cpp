#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

bool r[1 << 9];

ll sum = 0;
int A[9];

int mask[] = {7, 56, 73, 84, 146, 273, 292, 448};

bool f(int x, int y)
{
    if (__builtin_popcountll(y) == 5)
        return !r[y];
    for (int i = 0; i < 9; ++i)
    {
        if ((x | y) & 1 << i)
            continue;
        int z = x | 1 << i;
        for (int m : mask)
            if ((z & m) == m)
                return 1;
    }

    for (int i = 0; i < 9; ++i)
    {
        if ((x | y) & 1 << i)
            continue;
        if (!f(y, x | 1 << i))
            return 1;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 9; ++i)
    {
        cin >> A[i];
        sum += A[i];
    }
    for (int x = 0; x < 1 << 9; ++x)
    {
        ll s = 0;
        for (int i = 0; i < 9; ++i)
            if (x & 1 << i)
                s += A[i];
        r[x] = s * 2 - sum > 0;
    }

    cout << (f(0, 0) ? "Takahashi" : "Aoki") << '\n';
}
