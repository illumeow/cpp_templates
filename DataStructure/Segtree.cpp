// range sum + range add
struct Seg {
    #define lc (x<<1)
    #define rc (x<<1|1)
    struct node {
        int data, tag;
    };
    int n;
    vector<node> seg;
    void addtag(int x, int L, int R, int t) {
        seg[x].data += t * (R - L + 1);
        seg[x].tag += t;
    }
    void pull(int x) {
        seg[x].data = seg[lc].data + seg[rc].data;
    }
    void push(int x, int L, int R) {
        int M = (L + R) / 2;
        addtag(lc, L, M, seg[x].tag);
        addtag(rc, M + 1, R, seg[x].tag);
        seg[x].tag = 0;
    }
    void build(int x, int L, int R, vector<int> &v){
        if (L == R) {
            seg[x].data = v[L];
            return;
        }
        int M = (L + R) / 2;
        build(lc, L, M, v);
        build(rc, M + 1, R, v);
        pull(x);
    }
    void modify(int x, int L, int R, int l, int r, int v) {
        if (r < L || R < l) return;
        if (l <= L && R <= r) {
            addtag(x, L, R, v);
            return;
        }
        push(x, L, R);
        int M = (L + R) / 2;
        modify(lc, L, M, l, r, v);
        modify(rc, M + 1, R, l, r, v);
        pull(x);
    }
    int query(int x, int L, int R, int l, int r) {
        if (l <= L && R <= r) return seg[x].data;
        push(x, L, R);
        int M = (L + R) / 2;
        if (r <= M) return query(lc, L, M, l, r);
        if (l > M) return query(rc, M + 1, R, l, r);
        return query(lc, L, M, l, r) + query(rc, M + 1, R, l, r);
    }
    // v is 1-indexed
    void build(vector<int> &v) {
        n = v.size() - 1;
        seg.resize(n << 2);
        build(1, 1, n, v);
    }
    // [l, r] += v
    void modify(int l, int r, int v) {
        modify(1, 1, n, l, r, v);
    }
    int query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};