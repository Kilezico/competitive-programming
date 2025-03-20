int LIS()
{
    vector<int> aux = {0};
    for (int i=1; i<n; i++) {
        if (seq[i] > aux.back()) {
            aux.push_back(seq[i]);
        } else {
            auto it = lower_bound(aux.begin(), aux.end(), seq[i]);
            *it = seq[i];
        }
    }
    return aux.size();
}