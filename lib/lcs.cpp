int LCS(int i, int j)
{
    if (i >= s.size()) return 0;
    if (j >= t.size()) return 0;
    int ans = max(LCS(i + 1, j), LCS(i, j + 1));
    if (s[i] == t[j]) ans = max(ans, 1 + LCS(i + 1, j + 1));
    return ans;
}