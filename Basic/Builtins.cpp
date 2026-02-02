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
int sum = accumulate(v.begin(), v.end(), 0);
fill(v.begin(), v.end(), 0);
fill_n(v.begin(), n, 0);
// prefix sum, suffix use rbegin()
partial_sum(v.begin(), v.end(), v.begin());
// adjacent difference, v[i] = v[i] - v[i-1]
adjacent_difference(v.begin(), v.end(), v.begin());
// rotate left by k, right use rbegin()
rotate(v.begin(), v.begin() + k, v.end());