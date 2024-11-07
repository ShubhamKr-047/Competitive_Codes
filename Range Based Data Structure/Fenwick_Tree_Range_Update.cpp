//1-based indexing (input vector is also 1 based)
struct FenwickTree
{
    int n;
    vector<int> B1, B2;

    FenwickTree(vector<int> const &a)
    {
        int n = sz(a) - 1;
        this->n = n;
        B1.assign(this->n + 1, 0);
        B2.assign(this->n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            point_add(i, a[i]);
        }
    }

    // Add delta at position pos in tree t
    void add(vector<int>& t, int pos, int delta)
    {
        for(; pos <= n; pos += pos & (-pos)) t[pos] += delta;
    }

    // Get sum from 1 to pos in tree t
    int sum(vector<int>& t, int pos)
    {
        int res = 0;
        for(; pos > 0; pos -= pos & (-pos)) res += t[pos];
        return res;
    }

    // Add x to all elements in range [l, r]
    void update(int l, int r, int x)
    {
        add(B1, l, x);
        add(B1, r + 1, -x);
        add(B2, l, x * (l - 1));
        add(B2, r + 1, -x * r);
    }

    // Returns sum from 1 to pos
    int prefix_sum(int pos)
    {
        return sum(B1, pos) * pos - sum(B2, pos);
    }

    // Returns sum of elements in range [l, r]
    int query(int l, int r)
    {
        return prefix_sum(r) - prefix_sum(l - 1);
    }

    // Update single element at position pos
    void point_add(int pos, int x)
    {
        update(pos, pos, x);
    }

    int lower_bound(int target)
    {
        int pos = 0;
        int sum = 0;
        for (int i = log2(n); i >= 0; i--)
        {
            int next_pos = pos + (1 << i);
            if (next_pos <= n && sum + B1[next_pos] < target)
            {
                pos = next_pos;
                sum += B1[next_pos];
            }
        }
        return pos + 1;
    }
};
