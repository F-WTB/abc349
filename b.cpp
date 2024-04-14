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

int main()
{
    map<char, int> mp;
    string s;
    cin >> s;
    for (char c : s)
        ++mp[c];
    map<int, vector<char>> mp2;
    for (auto [c, k] : mp)
        mp2[k].push_back(c);
    for (auto [k, v] : mp2)
        if (v.size() != 0 && v.size() != 2)
        {
            cout << "No" << '\n';
            return 0;
        }
    cout << "Yes\n";
}
