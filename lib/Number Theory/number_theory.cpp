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

// Acha um par (x, y) que resolve a equação "ax + by = gcd(a, b)"
int extended_gcd(int a, int b, int &x, int &y){
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    int d = extended_gcd(b, a%b, x1, y1);
    
    x = y1;
    y = x1 - y1*(a/b);
    
    return d;
}

/*
Mais primos:
999'999'937
998'244'353
1'610'612'741
*/