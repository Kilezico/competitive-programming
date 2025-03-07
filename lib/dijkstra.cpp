void Dijkstra(int begin)
{
    for (int i=1; i<=n; i++) {
        dist[i] = inf;
    }
    priority_queue<pll, vector<pll>, greater<pll>> fila;
    dist[begin] = 0;
    fila.push({dist[begin], begin});

    while (!fila.empty()) {
        ll u = fila.top().second, d = fila.top().first;
        fila.pop();
        if (d <= dist[u])
            for (auto [v, w]: grafo[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    fila.push({dist[v], v});
                }
            }
    }
}