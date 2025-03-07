ll Kruskal()
{
    sort(arestas.begin(), arestas.end());
    ll custo = 0;
    for (int i=0; i<m; i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        int c = edges[i].first;
        if (find(u) != find(v)) {
            join(u, v);
            custo += c;
        }
    }
    return custo;
}