// This code has 1 based indexing for tree as well as vectors and inputs
// This is also the solution for question https://cses.fi/problemset/task/2134/

#include <bits/stdc++.h>
using namespace std;
 
int ind = 1;
vector<vector<int>> adj;
vector<int> head, lt, pos, value;
vector<int> sz, parent, depth, heavy;
 
class SGTree
{
public:
    int n;
    vector<int> st;
 
    SGTree(vector<int> &arr)
    {
        n = arr.size();
        st.resize(4 * n);
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
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        st[ind] = max(st[2 * ind + 1], st[2 * ind + 2]);
    }
 
    int query(int ind, int low, int high, int l, int r)
    {
        if (r < low || high < l) return INT_MIN;
        if (low >= l && high <= r) return st[ind];
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return max(left, right);
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
        st[ind] = max(st[2 * ind + 1], st[2 * ind + 2]);
    }
};
 
void dfs(int node)
{
    sz[node] = 1;
    for (int &child : adj[node])
    {
        if (child == parent[node]) continue;
        parent[child] = node;
        depth[child] = depth[node] + 1;
        dfs(child);
        sz[node] += sz[child];
        if (heavy[node] == 0 || sz[child] > sz[heavy[node]]) heavy[node] = child;
    }
}
 
void dfsHLD(int node, int chain)
{
    head[node] = chain;
    lt[ind] = value[node];
    pos[node] = ind++;
    if (heavy[node] != 0) dfsHLD(heavy[node], chain);
    for (int &child : adj[node])
    {
        if (child == parent[node] || child == heavy[node]) continue;
        dfsHLD(child, child);
    }
}
 
int path_max(int u, int v, SGTree &st)
{
    int mx = INT_MIN;
    while (head[u] != head[v])
    {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        mx = max(mx, st.query(pos[head[u]], pos[u]));
        u = parent[head[u]]; 
    }
    if (depth[v] < depth[u]) swap(u, v);
    mx = max(mx, st.query(pos[u], pos[v]));
    return mx;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    lt.resize(n + 1);
    adj.resize(n + 1);
    value.resize(n + 1);
    sz.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    head.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    heavy.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> value[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    dfsHLD(1, 1);
    SGTree st(lt);
    while (q--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) st.update(pos[a], b);
        else
        {
            cout << path_max(a, b, st) << " ";
        }
    }
}