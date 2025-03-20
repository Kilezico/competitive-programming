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