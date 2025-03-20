const ll MOD = 1e9+7;
const ll K = 157;
string str;
vector<ll> pref, pot;
void build(int n)
{
    pref.push_back(str[0]);
    for (int i=1; i<n; i++) {
        pref.push_backs((pref[i-1]*K + (str[i])) % MOD);
    }
    pot.push_back(1);
    for (int i=1; i<=n; i++) {
        pot.push_back((pot[i-1]*K) % MOD);
    }
}

ll query(int l, int r)
{
    ll ans = pref[r];
    if (l > 0) ans = (ans - pref[l-1]*pot[r-l+1]) % MOD;
    ans = (ans+MOD)%MOD; // Caso termine negativo
    return ans
}