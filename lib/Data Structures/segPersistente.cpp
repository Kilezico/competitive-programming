using ll = long long;
struct SegPersistente {
    struct Node {
        int l, r;
        ll val;
        Node (int l_=0, int r_=0, ll v=0) : l(l_), r(r_), val(v) {}
    };
    int n;
    vector<Node> seg;
    SegPersistente (int n_) : n(n_)
    {
        build(0, n-1);
    }
    ll merge(ll a, ll b)
    {
        a + b;
    }
    int build(int l, int r)
    {
        int idx = seg.size();
        seg.emplace_back();
        if (l == r) {
            seg[idx].l = seg[idx].r = -1;
            return idx;
        }
        int m = (l+r)/2;
        seg[idx].l = build(l, m);
        seg[idx].r = build(m+1, r);
        return idx;
    }
    int update(int pos, ll val, int root, int l, int r)
    {
        // Cria novo node
        int idx = seg.size();
        seg.emplace_back();
        seg[idx] = seg[root];

        if (l == r) {
            seg[idx].val = val;
            return idx;
        }
        int m = (l+r)/2;
        if (pos <= m) {
            seg[idx].l = update(pos, val, seg[idx].l, l, m);
        } else {
            seg[idx].r = update(pos, val, seg[idx].r, m+1, r);
        }
        seg[idx].val = merge(seg[seg[idx].l].val, seg[seg[idx].r].val);
        return idx;
    }
    ll query(int lq, int rq, int idx, int l, int r)
    {
        if (rq < l || r < lq) return 0;
        if (lq <= l && r <= rq) return seg[idx].val;
        int m = (l+r)/2;
        return merge(query(lq, rq, seg[idx].l, l, m), query(lq, rq, seg[idx].r, m+1, r));
    }
    int update(int pos, ll val, int root)
    {
        return update(pos, val, root, 0, n-1);
    }
    ll query(int lq, int rq, int root)
    {
        return query(lq, rq, root, 0, n-1);
    }
};
