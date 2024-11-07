//This is initially for 0 - based indexing
// For one based indexing just make the initial vector 1 - based indexing

class SGTree
{

public:

    int n;
    vector<int> seg;

    //building the SG Tree
    SGTree(vector<int> &arr)
    {
        n = sz(arr);
        seg.resize(4 * n + 1);
        build(0, 0, n - 1, arr);
    }

    void build(vector<int> &arr) { build(0, 0, n - 1, arr); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int i, int val) { update(0, 0, n - 1, i, val); }

private:

    //sg.build(0, 0, n - 1, arr);
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
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
    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) update(2 * ind + 1, low, mid, i, val);
        else update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};
