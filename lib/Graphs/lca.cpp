
const int BITS = 20;
int timer=0;
int tin[MAXN], tout[MAXN];
int up[MAXN][BITS];
void dfs(int u, int p)
{
    tin[u] = timer++;

    up[u][0] = p;
    for (int i=1; i<BITS; i++) {
        up[u][i] = up[up[u][i-1]][i-1]; // Avô é o pai do pai.
    }

    for (int v: grafo[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }

    tout[u] = timer;
}

bool is_ancestor(int u, int v)
{
    // true: u é ancestral de v.
    // false: u não é acestral de v.
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v)
{
    if (is_ancestor(u, v)) {
        return u;
    } else if (is_ancestor(v, u)) {
        return v;
    } else {
        for (int i=BITS-1; i>=0; i--) {
            if (up[u][i] && !is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }
}
