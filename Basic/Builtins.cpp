int __builtin_popcount(int x);  // count number of 1s in bit
int __lg(int x);                // floor(log2(x))
T gcd(T a, T b);
T lcm(T a, T b);                // cast to ll first
iota(v.begin(), v.end(), 1);    // fill v, start from 1
do { } while (next_permutation(v.begin(), v.end()));

auto cmp = [&](const auto &a, const auto &b) { return a < b; };
priorty_queue<int, vector<int>, decltype(cmp)> pq(cmp);
set<int, decltype(cmp)> st(cmp);
map<int, int, decltype(cmp)> mp(cmp);

// v[k] is the k-th smallest, v[0..k) < v[k] <= v[k+1..n)
nth_element(v.begin(), v.begin() + k, v.end());  // O(n)
// v[0..k) sorted and are the smallest k elements
partial_sort(v.begin(), v.begin() + k, v.end()); // O(nlogk)