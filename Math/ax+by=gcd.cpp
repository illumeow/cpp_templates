// ax + by = gcd(a, b)
pair<ll, ll> exgcd(ll a, ll b) {
  if (b == 0) return {1, 0};
  ll p = a / b;
  auto q = exgcd(b, a % b);
  return {q.second, q.first - q.second * p};
}
/*
 * ax+by=res, let x be minimum non-negative
 * g, p = gcd(a, b), exgcd(a, b) * res / g
 * if p.first < 0: t = (abs(p.first) + b / g - 1) / (b / g)
 * else: t = -(p.first / (b / g))
 * p += {b / g, -a / g} * t
 * {x, y} = p
*/