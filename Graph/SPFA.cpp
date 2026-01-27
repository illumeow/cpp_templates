// return true if no neg cycle
// https://hackmd.io/@illumeow/SJ_Ja7HrWl
bool spfa(int s, int n, vector<vector<pair<int, int>>> &adj) {
    vector<bool> inq(n);
    vector<ll> d(n, INF);
    vector<int> cnt(n), len(n), p(n, -1);
    deque<int> q;
    d[s] = 0;
    q.emplace_back(s);
    inq[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        if(++cnt[u] >= n) {
            return false;
        }
        inq[u] = false;
        if(p[u] != -1 && inq[p[u]]) continue;
        for(auto &[v, w] : adj[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                if(!inq[v]){
                    if (!q.empty() && d[v] < d[q.front()]) {
                        q.emplace_front(v);
                    } else {
                        q.emplace_back(v);
                    }
                    inq[v] = true;
                    len[v] = len[u] + 1;
                    if(len[v] >= n) return false;
                }
            }
        }
    }
    return true;
}