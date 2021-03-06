
template<typename T, typename F = function<T(const T&, const T&)>> class Bit {
  public:
  vector<T> tree;
  F cal;
  int sz;
  int lb(int x) { return x & -x; }
  void modify(int ind, T val) {
    ++ind;
    while (ind < sz) {
      tree[ind] = cal(tree[ind], val);
      ind += lb(ind);
    }
  }
  Bit(vector<T> v, T uneff, F _cal) : cal(_cal) {
    sz = (int) v.size() + 1;
    tree.resize(sz, uneff);
    for (int i = 0; i < (int) v.size(); ++i) modify(i, v[i]);
  }
  T get(int ind) {
    ++ind;
    T res = tree[0];
    while (ind) {
      res = cal(res, tree[ind]);
      ind -= lb(ind);
    }
    return res;
  }
  void clear() {
    fill(tree.begin(), tree.end(), tree[0]);
  }
};
