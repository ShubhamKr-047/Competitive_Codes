// This code is for 1 based nodes and indexing
// if we do dfs(1, 1) so even if we try to jump up from 1 we will still be at one. This is ok when we need to find just lca.
// if we need to find the kth ancestor and if for a node there are no kth ancestor above it then this code fails as it will return the root. In that case
// use dfs(1, 0) and if we get ancestor as 0 then just return -1

int timer;
vector<vector<int>> up, adj;
vector<int> time_in, time_out;

bool is_ancestor(int u, int v)
{
    return (time_in[u] <= time_in[v] && time_out[u] >= time_out[v]);
}

void dfs(int node, int par)
{
    time_in[node] = timer++;
    up[node][0] = par;
    for (int i = 1; i < 20; i++) up[node][i] = up[up[node][i - 1]][i - 1];
    for (int &child : adj[node])
    {
        if (child == par) continue;
        dfs(child, node);
    } 
    time_out[node] = timer++;
}

int lca(int u, int v)
{
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 19; i >= 0; i--)
    {
        if (!is_ancestor(up[u][i], v))
        {
            u = up[u][i];
        }
    }
    return up[u][0];
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    timer = 1;
    time_in.resize(n + 1);
    time_out.resize(n + 1);
    up.resize(n + 1, vector<int> (20));
    dfs(1, 1);
    cout << lca(10, 7) << endl;

}
