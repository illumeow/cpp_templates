// min dist from s to all nodes with at most k edges
void spfa_k(int s, int k, int n, vector<vector<pair<int, int>>> &adj) {
    vector<bool> inq(n);
    vector<ll> d(n, INF), bestd(n, INF);
    queue<int> q;
    vector<int> update;
    d[s] = 0;
    q.emplace(s);
    inq[s] = true;
    while (!q.empty() && k--) {
        while (!q.empty()) {
            int u = q.front(); q.pop();
            inq[u] = false;
            for(auto &[v, w] : adj[u]){
                if(d[v] > d[u] + w){
                    if (bestd[v] == INF) {
                        update.emplace_back(v);
                    }
                    bestd[v] = min(bestd[v], d[u] + w);
                }
            }
        }
        for (auto &v : update) {
            d[v] = bestd[v];
            bestd[v] = INF;
            if (!inq[v]) {
                inq[v] = true;
                q.emplace(v);
            }
        }
        update.clear();
    }
}