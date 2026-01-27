void dijkstra(int n, vector<vector<pair<int, int>>> &adj) {
    vector<int> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.emplace(0, 0);
    while (!minHeap.empty()) {
        auto [ud, u] = minHeap.top();
        minHeap.pop();
        // if (u == target) break;
        if (ud > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > ud + w) {
                dist[v] = ud + w;
                minHeap.emplace(dist[v], v);
            }
        }
    }
}