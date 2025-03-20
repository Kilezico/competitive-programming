const int ALPHA = 26;

struct Node {
    int next[ALPHA] {};
    int subtree_count = 0;
};

struct Trie {
    vector<Node> tr;
    
    Trie() : tr(1) {} // Inicia vector tr com 1 elemento

    void insert(string str)
    {
        int cur = 0;
        for (char c: str) {
            if (tr[cur].next[c-'a'] == 0) {
                tr[cur].next[c-'a'] = (int) tr.size();
                tr.emplace_back();
            }
            tr[cur].subtree_count++;
            cur = tr[cur].next[c-'a'];
        }
        tr[cur].subtree_count++;
    }

    int query(string str)
    {
        int cur = 0;
        for (char c: str) {
            if (tr[cur].next[c-'a'] == 0) {
                return 0;
            }
            cur = tr[cur].next[c-'a'];
        }
        return tr[cur].subtree_count;
    }
};