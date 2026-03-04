// This code has 1 based indexing for tree as well as vectors and inputs
// The eular tour vector has 0 based indexing but it does not matter since we are operating on sg tree using ledt ind and right ind vectors
// This is also the solution for question https://cses.fi/problemset/task/2134/ if the question is to find sum and not max

#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
 
int size_eular;
const int LOG = 20;
vector<vector<int>> adj, up;
vector<int> val, eular, left_ind, right_ind;
 
class SGTree
{
public:
    int n;
    vector<int> st;

    SGTree(vector<int> &arr)
    {
        n = arr.size();
        st.resize(4 * n + 1);
        build(0, 0, n - 1, arr);
    }
    
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }

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
        if (r < low || high < l) return 0;
        if (low >= l && high <= r) return st[ind];
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    void update(int ind, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            st[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (idx <= mid) update(2 * ind + 1, low, mid, idx, val);
        else update(2 * ind + 2, mid + 1, high, idx, val);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }
};
 
void dfs(int node, int par)
{
    up[node][0] = par;
    eular.push_back(val[node]);
    left_ind[node] = size_eular++;
    for (int i = 1; i < LOG; i++) up[node][i] = up[up[node][i - 1]][i - 1];
    for (int &child : adj[node])
    {
        if (child == par) continue;
        dfs(child, node);
    }
    eular.push_back(val[node]);
    right_ind[node] = size_eular++;
}
 
bool is_ancestor(int u, int v)
{
    return (left_ind[u] <= left_ind[v] && right_ind[u] >= right_ind[v]);
}
 
int lca(int u, int v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (!is_ancestor(up[u][i], v))
        {
            u = up[u][i];
        }
    }
    return up[u][0];
}
 
int32_t main()
{
    int n, q;
    cin >> n >> q;
    val.resize(n + 1);
    adj.resize(n + 1);
    left_ind.resize(n + 1);
    right_ind.resize(n + 1);
    up.resize(n + 1, vector<int> (LOG));
    for (int i = 1; i <= n; i++) cin >> val[i]; 
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    size_eular = 0;
    dfs(1, 1);
    SGTree st(eular);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int s, x;
            cin >> s >> x;
            st.update(left_ind[s], x);
            st.update(right_ind[s], x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int com = lca(a, b);
            int res = max(st.query(left_ind[com], left_ind[a]), st.query(left_ind[com], left_ind[b]));
            cout << res << ' ';
        }
    }
}
