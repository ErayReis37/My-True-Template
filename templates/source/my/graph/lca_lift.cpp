
template<typename T> class lca_lift : public dfs_forest<T> {
  public:    
  using dfs_forest<T>::n;  
  using dfs_forest<T>::edges;
  using dfs_forest<T>::depth;
  using dfs_forest<T>::parent;
  using dfs_forest<T>::dfs;
  using dfs_forest<T>::edge;

  int lg = -1;
  vector<vector<int>> mat;

  void clear() {
    mat.clear();
    lg = -1;    
  }

  private:
  void init() {
    lg = 32 - __builtin_clz(n);
    mat.resize(lg, vector<int>(n));
  }

  public:
  void build(int r = 0) {
    dfs(r);
    mat[0] = parent;
    mat[0][r] = r;
    for (int j = 1; j < lg; ++j) {
      for (int i = 0; i < n; ++i) {
        mat[j][i] = mat[j - 1][mat[j - 1][i]];
      }
    }
  }
  
  int get(int v, int u) {
    if (depth[u] > depth[v]) {
      swap(v, u);
    }
    int f = depth[v] - depth[u];
    int up = 0;
    while (f) {
      if (f & 1) {
        v = mat[up][v];  
      }
      f >>= 1;
      ++up;
    }
    for (int j = lg - 1; j >= 0; --j) {
      if (mat[j][u] != mat[j][v]) {
        v = mat[j][v];
        u = mat[j][u];
      }
    }
    if (u != v) {
      v = mat[0][v];
    }
    return v;
  }
  
  lca_lift(forest<T> x) : dfs_forest<T>(x) {
    init();
  }

  lca_lift(int _n) : dfs_forest<T>(_n) {
    init();
  }

};
