void FloydWarshall()
{
    // dist[i][j] = inf, se não existe aresta i->j;
    //              peso(i, j), se existe aresta i->j.
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (dist[i][k] != inf && dist[k][j] != inf) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}