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

    int find_ultimate_parent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find_ultimate_parent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultimate_parent_u = find_ultimate_parent(u);
        int ultimate_parent_v = find_ultimate_parent(v);
        if (ultimate_parent_u == ultimate_parent_v) return;
        if (size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};