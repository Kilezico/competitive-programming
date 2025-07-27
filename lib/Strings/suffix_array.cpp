struct SuffixArray {
    string s;
    vector<int> p, c;
    vector<int> lcp;
    SuffixArray(const string &str)
    {
        s = str + '$';
        int n = s.size();

        p.resize(n);
        c.resize(n);
        // k=0
        vector<pair<char, int>> sla;
        for (int i=0; i<n; i++) sla.push_back({s[i], i});
        sort(sla.begin(), sla.end());
        for (int i=0; i<n; i++) p[i] = sla[i].second;
        c[p[0]]=0;
        for (int i=1; i<n; i++) {
            c[p[i]] = c[p[i-1]];
            if (s[p[i]] != s[p[i-1]]) {
                c[p[i]]++;
            }
        }
        // k
        for (int k=0; (1<<k)<n; k++) {
            for (int i=0; i<n; i++) p[i] = (p[i] - (1<<k) + n) % n;

            count_sort(p, c);

            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for (int i=1; i<n; i++) {
                pair<int, int> atual = {c[p[i]], c[(p[i] + (1<<k))%n]};
                pair<int, int> antes = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
                c_new[p[i]] = c_new[p[i-1]];
                if (atual != antes) {
                    c_new[p[i]]++;
                }
            }
            c = c_new;
        }
    }

    void calc_lcp()
    {
        int n = s.size();
        lcp.resize(n);
        for (int i=0; i<n; i++) {
            if (c[i] == 0) continue;
            int j = p[c[i]-1];
            for (int &k=lcp[c[i]]; (s[i+k] == s[j+k]); k++);
            if (i+1 < n) lcp[c[i+1]] = max(0, lcp[c[i]]-1);
        }
    }

    void count_sort(vector<int> &p, vector<int> &c)
    {
        int n = p.size();
        vector<int> cnt(n+1, 0);

        for (auto x: c) cnt[x+1]++;
        for (int i=1; i<(int) cnt.size(); i++) {
            cnt[i] += cnt[i-1];
        }
        // Ordena
        vector<int> ord(n, 0);
        for (auto x: p) {
            ord[cnt[c[x]]] = x;
            cnt[c[x]]++;
        }
        p = ord;
    }
};
