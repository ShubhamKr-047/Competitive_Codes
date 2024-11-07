//This is initially for 0 - based indexing
// For one based indexing just make the initial vector 1 - based indexing

class SGTree
{

public:

    int n;
    vector<int> st, lazy;

    SGTree(vector<int> &arr)
    {
        n = sz(arr);
        st.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        build(0, 0, n - 1, arr);
    }
    
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int l, int r, int val) { update(0, 0, n - 1, l, r, val); }

private:

    //sg.build(0, 0, n - 1, arr);
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            st[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }

    //sg.query(0, 0, n - 1, l, r);
    int query(int ind, int low, int high, int l, int r)
    {
        //updating remaining updates
        if (lazy[ind] != 0)
        {
            st[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap
        if (r < low || high < l) return 0;
        // complete overlap
        if (low >= l && high <= r) return st[ind];
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }

    //sg.update(0, 0, n - 1, l, r, value);
    void update(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            st[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (high < l || r < low) return;
        if (low >= l && high <= r)
        {
            st[ind] += (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, val);
        update(2 * ind + 2, mid + 1, high, l, r, val);
        st[ind] = st[2 * ind + 1] + st[2 * ind + 2];
    }
};
