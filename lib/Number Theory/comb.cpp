ll fact[MAXN];
ll calc_fact(ll n)
{
    fact[0] = fact[1] = 1;
    for (int i=2; i<=n; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
    }
}

ll fexp(ll a, ll b) // Exponenciação rápida
{
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return fexp(x, MOD-2);
}

ll mul(ll a, ll b)
{
    return ((a * b) % MOD);
}

ll comb(ll n, ll k)
{
    return mul(mul(fact[n], inv(fact[k])), inv(fact[n-k]));
}