/*
Algoritmo de Dinic
    - Computar Maximum Flow / Minimum Cut de uma rede de fluxo
    - Complexidade: O(V*V*E)
*/

template <typename T> struct Edge {
    int u, v; // u -> v
    T cap, flow=0;
    Edge(int from, int to, T cap) : u(from), v(to), cap(cap) {}
};
template <typename T> struct Dinic {
    int n, s, t;
    const T inf = 1e17;
    vector<vector<int>> adj;
    vector<int> dist, nxt;
    vector<Edge<T>> edges; // {destino, capacidade}

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        dist.resize(n);
        adj.resize(n);
        nxt.resize(n);
    }
    void add_edge(int u, int v, T cap)
    {
        adj[u].push_back((int) edges.size());
        edges.emplace_back(u, v, cap);
        adj[v].push_back((int) edges.size());
        edges.emplace_back(v, u, 0);
    }
    void bfs()
    {
        for (int i=0; i<n; i++) dist[i] = -1;
        queue<int> fila;
        fila.push(s);
        dist[s] = 1;
        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();
            // Capacidade residual > 0
            for (int i: adj[u]) {
                if (dist[edges[i].v] == -1 && edges[i].cap - edges[i].flow > 0) {
                    dist[edges[i].v] = dist[u] + 1;
                    fila.push(edges[i].v);
                }
            }
        }
    }
    T dfs(int u, T cap)
    {
        if (cap == 0) return 0;
        if (u == t) return cap;
        for (; nxt[u]<(int) adj[u].size(); nxt[u]++) {
            int idx = adj[u][nxt[u]];
            if (dist[u] + 1 != dist[edges[idx].v]) continue; // Não está no Level graph
            T retorno = dfs(edges[idx].v, min(cap, edges[idx].cap - edges[idx].flow));
            if (retorno == 0) continue; // Não tem caminho
            edges[idx].flow += retorno;
            edges[idx^1].flow -= retorno; // Back edge
            return retorno;
        }
        return 0; // Não tem caminho
    }
    T flow()
    {
        // Retorna o max flow
        T ans = 0;
        while (true) {
            bfs();  // Gera as distâncias
            if (dist[t] == -1) break; // Cabou?
            // Enquanto existir caminho de aumento
            for (int i=0; i<n; i++) nxt[i] = 0;
            T retorno = dfs(s, inf);
            while (retorno) {
                ans += retorno;
                retorno = dfs(s, inf);
            }
        }
        return ans;
    }
    vector<Edge<T>> min_cut()
    {
        // Retorna as edges do corte mínimo
        vector<Edge<T>> cut;
        queue<int> fila;
        fila.push(s);
        vector<bool> mark(n, false);
        // Marca todo mundo alcançável
        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();
            for (int i: adj[u]) {
                if (edges[i].cap - edges[i].flow <= 0) continue;
                if (!mark[edges[i].v]) {
                    mark[edges[i].v] = true;
                    fila.push(edges[i].v);
                }
            }
        }
        for (auto e: edges) {
            if (mark[e.u] && !mark[e.v]) cut.push_back(e);
        }
        return cut;
    }
};
