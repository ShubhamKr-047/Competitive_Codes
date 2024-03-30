#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#include <bits/stdc++.h>
using namespace std;

#define INF 2e9
#define endl '\n'
#define MOD 1000000007
#define lld long double
#define ll long long int
#define ull unsigned long long
#define tcT template <class T>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define mine(a) (*min_element((a).begin(), (a).end()))
#define maxe(a) (*max_element((a).begin(), (a).end()))
#define cnt(a, x) (count((a).begin(), (a).end(), (x)))
#define sum(a) (accumulate((a).begin(), (a).end(), 0LL))
#define minp(a) (min_element((a).begin(), (a).end()) - (a).begin())
#define maxp(a) (max_element((a).begin(), (a).end()) - (a).begin())

tcT int lb(vector<T> &a, const T &b) { return int(lower_bound(all(a), b) - begin(a)); }
tcT int ub(vector<T> &a, const T &b) { return int(upper_bound(all(a), b) - begin(a)); }

tcT void operator>>(istream &obj, vector<T> &vec)
{
    for (auto &it : vec)
        obj >> it;
}

tcT void operator<<(ostream &obj, vector<T> &vec)
{
    for (auto &it : vec)
        obj << it << ' ';
    cout << endl;
}

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve()
{
    
}

int main()
{
    FASTIO;
    int test_case;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++)
    {
        solve();
    }
}