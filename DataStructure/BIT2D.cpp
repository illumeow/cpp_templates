struct BIT2D {
    int n, m;
    vector<vector<int>> bit;
    #define lb(x) (x & -x)

    // both 1-indexed
    void build(vector<vector<int>> &data) {
        n = data.size();
        m = data[0].size();
        bit.resize(n, vector<int>(m));
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                bit[i][j] += data[i][j];
                int r = j + lb(j);
                if (r < m) bit[i][r] += bit[i][j];
            }
        }
        for (int j = 1; j < m; ++j) {
            for (int i = 1; i < n; ++i) {
                int r = i + lb(i);
                if (r < n) bit[r][j] += bit[i][j];
            }
        }
    }

    void modify(int x, int y, int v) {
        for (int i = x; i < n; i += lb(i)) {
            for (int j = y; j < m; j += lb(j)) {
                bit[i][j] += v;
            }
        }
    }

    int query(int x, int y) {
        int ret = 0;
        for (int i = x; i > 0; i -= lb(i)) {
            for (int j = y; j > 0; j -= lb(j)) {
                ret += bit[i][j];
            }
        }
        return ret;
    }

    // top-left, bottom-right
    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) 
             - query(x1 - 1, y2) 
             - query(x2, y1 - 1) 
             + query(x1 - 1, y1 - 1);
    }
};