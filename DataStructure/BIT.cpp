struct BIT {
    int n;
    vector<int> bit;
    #define lb(x) (x & -x)
    // both 1-indexed
    void build(vector<int> &data) {
        n = data.size();
        bit.resize(n);
        for (int i = 1; i < n; ++i) {
            bit[i] += data[i];
            int j = i + lb(i);
            if (j < n) bit[j] += bit[i];
        }
    }
    void modify(int x, int v) {
        for (; x < n; x += lb(x)) bit[x] += v;
    }
    int query(int x) {
        int ret = 0;
        for (; x > 0; x -= lb(x)) ret += bit[x];
        return ret;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
    // use freq array to build
    // find min x s.t. freq[1..x] <= k
    // kth element when sorted
    int query_kth(int k) {
        int res = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (res + i < n && bit[res + i] < k) {
                res += i;
                k -= bit[res];
            }
        }
        return res + 1;
    }
};
