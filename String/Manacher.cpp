/* 0-base
   center i: radius z[i * 2 + 1] / 2
   center i - 1, i: radius z[i * 2] / 2
   both aba, abba have radius 2 */
vector<int> manacher(string &tmp) {
    string s = "%";
    for (char c : tmp) {
        s += c;
        s += "%";
    }
    vector<int> z(s.size());
    // rightmost [, m, r)
    int m = 0, r = 0;
    for (int i = 0; i < s.size(); ++i) {
        z[i] = r > i ? min(z[2 * m - i], r - i) : 1;
        while (i - z[i] >= 0 && i + z[i] < s.size() 
            && s[i - z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) {
            m = i;
            r = i + z[i];
        }
    }
    return z;
}
