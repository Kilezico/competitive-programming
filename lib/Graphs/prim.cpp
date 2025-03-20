ll prim()
{
    priority_queue<pll> minheap;
    minheap.push((0, 1)); // (0, começo)
    vector<bool> vis(n, false);
    ll custo = 0;
    while (!minheap.empty()) {
        auto [w, u] = minheap.top();
        minheap.pop();
        if (vis[u]) {
            vis[u] = true;
            custo += w;
            for (auto [v, c]: grafo[u]) {
                if (vis[v] == false){
                    minheap.push((c, v));
                }
            }
        }
    }
    return custo
}

ll Kruskal()
{
    sort(arestas.begin(), arestas.end());
    ll custo = 0;
    for (int i=0; i<(int) arestas.size(); i++) {
        auto [u, v, c] = arestas[i];
        if (find(u) != find(v)) {
            join(u, v);
            custo += c;
        }
    }
    return custo;
}