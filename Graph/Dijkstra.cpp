// in adj first -> node, second -> weight
// dis -> vector<int> dis(n + 1, INT_MAX)
// not applicable for -ve weights
// Complexity :- O(ElogV)

void dijkstra(vector<pair<int, int>> adj[], int n, int source, vector<int> &dis)
{
    set<pair<int, int>> st;
    st.insert({0, source});
    dis[source] = 0;
    while (st.size() > 0)
    {
        auto node = *st.begin();
        int parent = node.second;
        int parent_dist = node.first;
        st.erase(st.begin());
        for (auto &child : adj[parent])
        {
            int child_node = child.first;
            int child_dist = child.second;
            if (dis[parent] + child_dist < dis[child_node])
            {
                if (dis[child_node] != INT_MAX) st.erase({dis[child_node], child_node});
                dis[child_node] = dis[parent] + child_dist;
                st.insert({dis[child_node], child_node});
            }
        }
    }
}
