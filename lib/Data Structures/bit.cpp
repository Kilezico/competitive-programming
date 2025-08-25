template <typename T> 
struct FenwickTree {
    int n;
    vector<int> bit;
    FenwickTree(int n) : n(n)
    {
        bit.resize(n+1, 0);
    }

    T query(int x)
    {
        T ans = 0;
        while (x > 0) {
            ans += bit[x];
            x -= (x & -x);
        }
        return ans;
    }

    void update(int x, T v)
    {
        while (x <= n) {
            bit[x] += v;
            x += (x & -x);
        }
    }
};
