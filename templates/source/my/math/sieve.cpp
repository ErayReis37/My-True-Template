
namespace sieve {
  vector<int> list(int n) {
    assert(n <= (int) 3e8 && n >= 0);
    if (n == 0) return vector<int>(0);
    vector<int> res;
    vector<bool> ip(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ip[i]) continue;
      res.push_back(i);
      if ((int) ceil(1.0 * n / i) < i) continue;
      for (int j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
    return res;
  }
  
  vector<bool> check(int n) {
    assert(n <= (int) 3e8 && n >= 0);	  
    if (n == 0) return vector<bool>(1, false);
    vector<bool> ip(n + 1, true);
    for (int i = 2; i <= n; ++i) {
      if (!ip[i]) continue;
      if (ceil(1.0 * n / i) < i) continue;
      for (int j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
    ip[0] = false;
    if (n > 1) ip[1] = false;
    return ip;
  }
}
