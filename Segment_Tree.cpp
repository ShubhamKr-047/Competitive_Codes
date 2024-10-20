class SGTree
{

public:

    int n;
    vector<int> seg;

    SGTree(int n) : n(n) { seg.resize(4 * n + 1); }
    void build(vector<int> &arr, int orr) { build(0, 0, n - 1, arr, orr); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int i, int val, int orr) { update(0, 0, n - 1, i, val, orr); }

private:

    //sg.build(0, 0, n - 1, arr);
    void build(int ind, int low, int high, vector<int> &arr, int orr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr, !orr);
        build(2 * ind + 2, mid + 1, high, arr, !orr);
        if (orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }

    //sg.query(0, 0, n - 1, l, r);
    int query(int ind, int low, int high, int l, int r)
    {
        // no overlap
        if (r < low || high < l) return INT_MAX;
        // complete overlap
        if (low >= l && high <= r) return seg[ind];
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    //sg.update(0, 0, n - 1, index, value);
    void update(int ind, int low, int high, int i, int val, int orr)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val, !orr);
        else update(2 * ind + 2, mid + 1, high, i, val, !orr);
        if (orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }
};
