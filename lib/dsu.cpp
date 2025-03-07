pai[i] = i;
sz[i] = 1;

int find(int a)
{
    if (pai[a] == a) return a;
    return pai[a] = find(pai[a]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);

    if (sz[b] > sz[a]) swap(a, b);
    
    pai[b] = a;
    sz[a] += sz[b];
}