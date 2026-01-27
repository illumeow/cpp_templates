vector<int> fail_func(string &s) {
    int n = s.size();
    vector<int> f(n);
    for (int i = 1; i < n; ++i) {
        int j = f[i - 1];
        while(j > 0 && s[i] != s[j]) j = f[j - 1];
        if (s[i] == s[j]) j++;
        f[i] = j;
    }
    return f;
}
int kmp(string &s, string &p) {
    int n = s.size(), m = p.size();
    auto f = fail_func(p);
    int cnt = 0, j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j]) j = f[j - 1];
        if (s[i] == p[j]) j++;
        if (j == m) {
            cnt++;
            j = f[j - 1];
        }
    }
    return cnt;
}