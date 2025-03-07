int query(int lq, int rq, int idx=1, int l=1, int r=n)
{
    if (r < lq || l > rq) return 0; // NEUTRO
    if (lq <= l && rq >= r) return seg[idx];

    int m = (l + r) / 2;
    int f1 = query(lq, rq, 2*idx, l, m);
    int f2 = query(lq, rq, 2*idx+1, m+1, r);
    
    return f1 + f2;
}

void update(int pos, int val, int idx=1, int l=1, int r=n)
{
    if (pos < l || pos > r) return;
    if (l == r) { seg[idx] = val; return; }
    
    int m = (l+r)/2;
    update(pos, val, 2*idx, l, m);
    update(pos, val, 2*idx+1, m+1, r);

    seg[idx] = seg[2*idx] + seg[2*idx+1];
}