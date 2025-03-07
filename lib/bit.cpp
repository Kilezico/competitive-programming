ll query(int x)
{
    ll soma = 0;
    while (x > 0) {
        soma += arr[x];
        x -= (x & -x);
    }
    return soma;
}

void update(int x, ll val)
{
    while (x <= n) {
        arr[x] += val; // BIT de soma
        x += (x & -x);
    }
}
