int LIS()
{
    vector<int> aux;
    for (int i=0; i<(int) seq.size(); i++) {
        auto it = upper_bound(aux.begin(), aux.end(), seq[i]);
        if (it == aux.end()) {
            aux.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
    }
    return aux.size();
}
