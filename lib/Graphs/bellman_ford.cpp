bool BellmanFord(int begin)
{
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    dist[begin] = 0;
    for (int i=0; i<(n-1); i++) {
        for (auto [u, v, w]: edges) { // Relaxa aresta u->v
            if (dist[u] < inf) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
    for (auto [u, v, w]: edges) {
        if (dist[u] < inf && dist[v] > dist[u] + w) {
            return false;
        }
    }
    return true;
}