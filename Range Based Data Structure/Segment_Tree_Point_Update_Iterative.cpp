class SGTree
{
public:
    int n;
    vector<int> seg;

    SGTree(vector<int> &arr)
    {
        n = arr.size();
        seg.resize(2 * n);
        for (int i = 0; i < n; i++) seg[n + i] = arr[i];
        for (int i = n - 1; i > 0; i--) seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }

    int query(int l, int r)
    {
        l += n;
        r += n;
        int res = INT_MAX;
        while (l <= r)
        {
            if (l % 2 == 1) res = min(res, seg[l++]);
            if (r % 2 == 0) res = min(res, seg[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    }

    void update(int i, int val)
    {
        i += n;
        seg[i] = val;
        while (i > 1)
        {
            i /= 2;
            seg[i] = min(seg[2 * i], seg[2 * i + 1]);
        }
    }
};