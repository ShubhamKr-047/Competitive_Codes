#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

#include <bits/stdc++.h>
using namespace std;

#define INF 2e18
#define endl '\n'
#define MOD 1000000007
#define int long long int
#define pi pair<int, int>
#define double long double
#define sz(x) ((int)size(x))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

template <class T> void remove_duplicate(vector<T> &vec) { sort(all(vec)); vec.erase(unique(all(vec)), end(vec)); }
template <class T> void operator>>(istream &obj, vector<T> &vec) { for (int i = 0; i < sz(vec); i++) obj >> vec[i]; }
template <class T> void operator<<(ostream &obj, vector<T> &vec) { for (int i = 0; i < sz(vec); i++) obj << vec[i] << " \n"[i == sz(vec) - 1]; }

#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    cin >> v;
    
}

int32_t main()
{
    FAST_IO;
    int test_case;
    cin >> test_case;
    for (int tc = 1; tc <= test_case; tc++)
    {
        solve();
    }
}