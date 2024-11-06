// 0 based indexing
struct FenwickTree
{
    int n;
    vector<int> bit;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(sz(a))
    {
        for (int i = 0; i < sz(a); i++) add(i, a[i]);
    }

    int sum(int r)
    {
        int sum = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) sum += bit[r];
        return sum;
    }

    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int index, int delta)
    {
        for (; index < n; index = index | (index + 1)) bit[index] += delta;
    }

    int lower_bound(int target_sum)
    {
        int curr = -1, prev_sum = 0;
        for (int i = log2(n); i >= 0; i--)
        {
            if ((curr + (1 << i)) < n && prev_sum + bit[curr + (1 << i)] < target_sum)
            {
                prev_sum += bit[curr + (1 << i)];
                curr = curr + (1 << i);
            }
        }
        return curr + 1;
    }
};
