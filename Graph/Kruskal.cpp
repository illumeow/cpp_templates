// edges: {weight, u, v}
ll kruskal(vector<array<ll, 3>> &edges, int n){
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll totalWeight = 0;
    int count = 1;
    for(auto &[w, u, v]: edges) {
        if(dsu.merge(u, v)) {
            totalWeight += w;
            count++;
        }
    }
    return (count == n) ? totalWeight : -1;
}