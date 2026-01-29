// only keep min weight edge, use before Dijkstra, Prim, etc.
void removeMultiEdges(vector<vector<pair<int, int>>> &adj) {
    for (auto &list : adj) {
        sort(list.begin(), list.end());
        list.erase(unique(list.begin(), list.end(), [](const auto &a, const auto &b) {
            return a.first == b.first;
        }), list.end());
    }
}