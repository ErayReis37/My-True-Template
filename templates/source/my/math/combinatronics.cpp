
vector<Mint> fac(1, 1), inv_fac(1, 1);

void fill_fac(int n) {
  while ((int) fac.size() <= n) {
    fac.push_back(fac.back() * (int) fac.size());
    inv_fac.push_back(1 / fac.back());
  }
}

Mint fact(int x) {
  assert(x >= 0);
  fill_fac(x);
  return fac[x];
}

Mint C(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return fac[x] * inv_fac[y] * inv_fac[x - y];
}

Mint P(int x, int y) {
  if (x < 0 || y > x) {
    return 0;
  }
  assert(y >= 0);
  fill_fac(x);
  return fac[x] * inv_fac[x - y];
}

