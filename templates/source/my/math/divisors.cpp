namespace divs {

  vector<int> check_primes;
  void createSieve(long long limit) {
    check_primes = sieve::list((int) ceil(sqrt(limit)));
  }

  vector<pair<long long, int>> prime(long long n, bool fast = false) {
    assert(n > 0);
    vector<pair<long long, int>> res;
    if (!fast) {
      for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) res.emplace_back(i, 0);
        while (n % i == 0) {
          n /= i;
          ++res.back().second;
        }
      }
    } else {
      assert(!check_primes.empty());
      for (int i = 0; i < (int) check_primes.size() && 1LL * check_primes[i] * check_primes[i] <= n; ++i) {
        if (n % check_primes[i] == 0) res.emplace_back(check_primes[i], 0);
        while (n % check_primes[i] == 0) {
          n /= check_primes[i];
          ++res.back().second;
        }
      }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
  }

  vector<vector<int>> till(int n) {
    vector<vector<int>> res(n + 1);
    for (int i = 2; i <= n; ++i) {
      if (!res[i].empty()) continue;
      for (int j = i; j <= n; j += i) {
        res[j].push_back(i);
      }                
    }
    return res;
  }

  vector<long long> all(long long n) {
    assert(n > 0);
    vector<long long> res;
    for (long long i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        res.push_back(i);
        res.push_back(n / i);
      }
    }
    assert(res.size() >= 2);
    if (res.back() == res[(int) res.size() - 2]) res.pop_back();
    return res;
  }

  bool isPrime(long long n, bool fast = false) {
    if (!fast) {
      for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
      }
    } else {
      assert(!check_primes.empty());
      for (int i = 0; i < (int) check_primes.size() && 1LL * check_primes[i] * check_primes[i] <= n; ++i) {
        if (n % check_primes[i]) return false;
      }
    }
    return true;
  }
}