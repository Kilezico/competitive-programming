vector<int> num_to_vec(ll num)
{
    if (num <= 0) return {0};
    vector<int> v;
    for (; num>0; num/=10) v.push_back(num % 10);
    reverse(v.begin(), v.end());
    return v;
}

ll dp[MAX_DIGITS][MAX_K][2];
ll conta(int pos, int cnt, bool smaller)
{
    if (pos == number.size()) return (cnt == k);
    ll &res = dp[pos][cnt][smaller];
    if (res != -1) return res;
    res = 0;
    for (int i=0; i<=(smaller ? 9 : number[pos]); i++) {
        bool is_smaller_now = (smaller || (i < number[pos]));
        int new_cnt = cnt + (i != 0);
        res += conta(pos+1, new_cnt, is_smaller_now);
    }
    return res;
}
