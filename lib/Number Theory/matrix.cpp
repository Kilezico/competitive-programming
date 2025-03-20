int m = 2;
struct Matrix {
    ll mat[m][m] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix& p)
    {
        Matrix res;
        // Multiplica mat com p.mat
        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                res.mat[i][j] = 0;
                for (int k=0; k<m; k++) {
                    res.mat[i][j] += (mat[i][k] * p.mat[k][j])%MOD;
                    res.mat[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix fexp (Matrix a, ll b)
{
    Matrix res; // Identidade
    for (int i=0; i<m; i++)
        res.mat[i][i] = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}