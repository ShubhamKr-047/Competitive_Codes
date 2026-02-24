const int LOG = 20;

vector<int> depth, value;
vector<vector<int>> up, mx, adj;

void dfs(int node, int parent)
{
    up[node][0] = parent;
    mx[node][0] = value[node];
    for (int i = 1; i < LOG; i++)
    {
        up[node][i] = up[up[node][i - 1]][i - 1];
        mx[node][i] = max(mx[node][i - 1], mx[up[node][i - 1]][i - 1]);
    }
    for (auto child : adj[node])
    {
        if (child == parent) continue;
        depth[child] = depth[node] + 1;
        dfs(child, node);
    }
}

int getMax(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v);
    int res = 0;

    // Lift u up to same level as v
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            res = max(res, mx[u][i]);
            u = up[u][i];
        }
    }

    if (u == v) return max(res, value[u]);

    // Lift both until LCA
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[u][i] != up[v][i])
        {
            res = max(res, mx[u][i]);
            res = max(res, mx[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }

    res = max(res, value[u]);
    res = max(res, value[v]);
    res = max(res, value[up[u][0]]);
    return res;
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
    depth.resize(n + 1);
    value.resize(n + 1);
    up.resize(n + 1, vector<int> (LOG));
    mx.resize(n + 1, vector<int> (LOG));
    for (int i = 1; i <= n; i++) cin >> value[i];
    dfs(1, 0);
}