int val[MAXN][MAXM], ps[MAXN][MAXM];
void build_PS2D(int n, int m)
{
    // ps[0][i] e ps[i][0] = 0, para todo i
    // val[i][j] é 1-indexado
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ps[i][j] = val[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
    
}

int query(int i0, int j0, int i, int j)
{
    return ps[i][j] - ps[i0-1][j] - ps[i][j0-1] + ps[i0-1][j0-1];
}
