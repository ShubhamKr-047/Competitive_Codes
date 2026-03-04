// This code has 1 based indexing for tree as well as vectors and inputs
// The eular tour vector has 0 based indexing but it does not matter since we are operating on sg tree using ledt ind and right ind vectors
// This is also the solution for question https://cses.fi/problemset/task/1138/

#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
int size_eular = 0;
vector<vector<int>> adj;
vector<int> val, eular, left_ind, right_ind;
 
class SGTree
{
 
public:
 
    int n;
    vector<int> st, lazy;
 
    SGTree(vector<int> &arr)
    {
        n = size(arr);
        st.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        build(0, 0, n - 1, arr);
    }
    
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int l, int r, int val) { update(0, 0, n - 1, l, r, val); }
 
private:
 
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            st[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }
 
    int query(int ind, int low, int high, int l, int r)
    {
        if (lazy[ind] != 0)
        {
            st[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || high < l) return 0;
        if (low >= l && high <= r) return st[ind];
        int mid = (low + high) >> 1;
        int left_ind = query(2 * ind + 1, low, mid, l, r);
        int right_ind = query(2 * ind + 2, mid + 1, high, l, r);
        return left_ind + right_ind;
    }
 
    void update(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            st[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || r < low) return;
        if (low >= l && high <= r)
        {
            st[ind] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }
};
 
void dfs(int node, int par)
{
    eular.push_back(val[node]);
    left_ind[node] = size_eular++;
    for (int &child : adj[node])
    {
        if (child == par) continue;
        dfs(child, node);
    }
    eular.push_back(-val[node]);
    right_ind[node] = size_eular++;
}
 
int32_t main()
{
    int n, q;
    cin >> n >> q;
    val.resize(n + 1);
    adj.resize(n + 1);
    left_ind.resize(n + 1);
    right_ind.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i]; 
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    SGTree st(eular);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int s, x;
            cin >> s >> x;
            int diff = x - val[s];
            val[s] = x; 
            st.update(left_ind[s], left_ind[s], diff);
            st.update(right_ind[s], right_ind[s], -diff);
        }
        else
        {
            int s;
            cin >> s;
            cout << st.query(0, left_ind[s]) << endl;
        }
    }
}
