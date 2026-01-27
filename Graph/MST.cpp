vector<array<ll, 3>> edges;  // w, u, v
ll kruskal(){
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll ret = 0;
    for(auto &[w, u, v]: edges) {
        if(dsu.merge(u, v)) {
            ret += w;
        }
    }
    return ret;
}