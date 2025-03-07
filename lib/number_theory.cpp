const int MOD = 1e9+7;

ll gcd(ll a, ll b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a/gcd(a, b)*b;
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

vector<pii> get_primes(int x) // Fatoração prima
{
    vector<pii> primes;
    for (int i=2; i*i<=x; i++) {
        int cnt = 0;
        while (x % i == 0) x/=i, cnt++;
        if (cnt > 0) primes.push_back({i, cnt});
    }
    if (x > 1) primes.push_back({x, 1});
    return primes;
}

vector<int> get_divisors(int x) // Divisores
{
    vector<int> v = {};
    for (int i=1; i*i<=x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (x/i != i) v.push_back(x/i); 
        }
    }
    return v;
}