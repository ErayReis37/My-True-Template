
vector<int> order(int n, function<bool(const int&, const int&)> f) {
  vector<int> res(n);
  iota(res.begin(), res.end(), 0);
  sort(res.begin(), res.end(), f);
  return res;
}
