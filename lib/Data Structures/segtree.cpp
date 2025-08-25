template <typename T>
struct SegTree {
    int n;
    vector<T> seg;

    SegTree(int n) : n(n)
    {
        seg.resize(4*n+5);
    }
    T combine(T t1, T t2) 
    {
        return t1 + t2;
    }
    void build(vector<T> &arr, int idx, int l, int r)
    {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int m=(l+r)/2, e=2*idx, d=2*idx+1;
        build(arr, e, l, m);
        build(arr, d, m+1, r);
        seg[idx] = combine(seg[e], seg[d]);
    }
    void update(int pos, T val, int idx, int l, int r)
    {
        if (pos < l || pos > r) return;
        if (l == r) {
            seg[idx] = val;
            return;
        }
        int m=(l+r)/2, e=2*idx, d=2*idx+1;
        update(pos, val, e, l, m);
        update(pos, val, d, m+1, r);
        seg[idx] = combine(seg[e], seg[d]);
    }
    T query(int lq, int rq, int idx, int l, int r)
    {
        if (rq < l || r < lq) return T();
        if (lq <= l && r <= rq) return seg[idx];
        int m=(l+r)/2, e=2*idx, d=2*idx+1;
        T t1 = query(lq, rq, e, l, m);
        T t2 = query(lq, rq, d, m+1, r);
        return combine(t1, t2);
    }
};
