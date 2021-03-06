
template<typename T, typename M, typename F = function<T(const T&, const T&)>> 
class lift : public lca_lift<M> {
  public:
  using lca_lift<M>::n;
  using lca_lift<M>::edges;
  using lca_lift<M>::depth;
  using lca_lift<M>::mat;
  using lca_lift<M>::build;    
  using lca_lift<M>::edge;

  int l = -1;
  vector<vector<T>> t;
  F cal = nullptr;
  T def;

  void clear() {
    t.clear();
    l = -1;
    cal = nullptr;
  }

  void init() {
    l = 32 - __builtin_clz(n);
    t.resize(l, vector<T>(n));
  }

  void build() {
    vector<T> res(n, def);
    build(0);
    for (int i = 0; i < n; ++i) {
      if (edge[i] == -1) {
        continue;
      }
      res[i] = edges[edge[i]].w;
    }
    build(res);
  }
  
  void build(vector<T> values) {
    if (mat[0][0] == -1) {
      build(0);  
    }
    t[0] = values;
    for (int j = 1; j < l; ++j) {
      for (int i = 0; i < n; ++i) {
        int par = mat[j - 1][i];
        t[j][i] = cal(t[j - 1][i], t[j - 1][par]);
      }  
    }
  }

  T get(int v, int u, bool node = false) {
    T res = def;
    if (depth[v] < depth[u]) {
      swap(v, u);
    }
    int f = depth[v] - depth[u];
    int up = 0;
    while (f) {
      if (f & 1) {
        res = cal(res, t[up][v]);
        v = mat[up][v];  
      }
      f >>= 1;
      ++up;
    }
    for (int j = l - 1; j >= 0; --j) {
      if (mat[j][u] != mat[j][v]) {
        res = cal(res, t[j][v]);
        res = cal(res, t[j][u]);
        v = mat[j][v];
        u = mat[j][u];
      }
    }
    if (u != v) {
      res = cal(t[0][v], res);
      res = cal(t[0][u], res);
      v = u = mat[0][v];
    }
    if (node) {
      // if values are on nodes, not edges
      res = cal(res, t[0][v]);
    }
    return res;
  }

  lift(int _n, T _def, F _cal) : lca_lift<M>(_n), def(_def), cal(_cal) {
    init();        
  }

  lift(forest<M> f, T _def, F _cal) : lca_lift<M>(f), def(_def), cal(_cal) {
    init();    
  }

};
 
