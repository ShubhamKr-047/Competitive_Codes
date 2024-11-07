class SparseTable
{

private:
    int n;
    vector<int> lg;
    vector<vector<int>> st;

public:
    SparseTable(const vector<int> &arr)
    {
        n = arr.size();
        lg.resize(n + 1, 0);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        st.resize(n, vector<int>(lg[n] + 1));
        for (int i = 0; i < n; i++) st[i][0] = arr[i];
        for (int j = 1; j <= lg[n]; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int left, int right)
    {
        int j = lg[right - left + 1];
        return min(st[left][j], st[right - (1 << j) + 1][j]);
    }
};
