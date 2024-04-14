#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
ll L, R;

ll msb(ll x)
{
    for (int i = 61; i >= 0; --i)
        if (x & 1ll << i)
            return 1ll << i;
    return 0;
}

ll lsb(ll x)
{
    return x & -x;
}

int main()
{
    cin >> L >> R;
    vector<ll> v;
    v.push_back(L);

    if (!L)
    {
        L += msb(R);
        v.push_back(L);
    }

    while (L + lsb(L) <= R)
    {
        L += lsb(L);
        v.push_back(L);
    }

    while (L < R)
    {
        L += msb(L ^ R);
        v.push_back(L);
    }

    int N = v.size() - 1;
    cout << N << '\n';
    for (int i = 0; i < N; ++i)
        cout << v[i] << ' ' << v[i + 1] << '\n';
}
