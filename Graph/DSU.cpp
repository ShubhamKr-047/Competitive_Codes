class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_ult_par(int node)
    {
        if (node == parent[node]) return node;
        return parent[node] = find_ult_par(parent[node]);
    }

    void union_by_size(int u, int v)
    {
        int ult_par_u = find_ult_par(u);
        int ult_par_v = find_ult_par(v);
        if (ult_par_u == ult_par_v) return;
        if (size[ult_par_u] < size[ult_par_v])
        {
            parent[ult_par_u] = ult_par_v;
            size[ult_par_v] += size[ult_par_u];
        }
        else
        {
            parent[ult_par_v] = ult_par_u;
            size[ult_par_u] += size[ult_par_v];
        }
    }
};