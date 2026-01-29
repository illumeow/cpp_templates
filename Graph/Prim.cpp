// O(V + E log E)
ll prim(vector<vector<pair<int, int>>> &adj, int n) {
    vector<bool> inMST(n, false);
    // {weight, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0);
    ll totalWeight = 0;
    int count = 0;
    while (!pq.empty()) {
        auto [uw, u] = pq.top();
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += uw;
        count++;
        for (auto &[v, w]: adj[u]) {
            if (!inMST[v]) {
                pq.emplace(w, v);
            }
        }
    }
    return (count == n) ? totalWeight : -1;
}