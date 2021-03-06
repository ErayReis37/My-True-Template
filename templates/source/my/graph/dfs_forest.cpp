
template<typename T> class dfs_forest : public forest<T> {
  public:
  using forest<T>::n;  
  using forest<T>::g;
  using forest<T>::edges;

  vector<int> depth, parent, root, sz, edge, order;
  vector<T> dist;

  void clear() {
    depth.clear();
    parent.clear();
    root.clear();
    sz.clear();
    edge.clear();
    depth.clear();
    dist.clear();
    order.clear();
  }

  void init() {
    depth.resize(n, 0);
    parent.resize(n, -1);
    root.resize(n, -1);
    sz.resize(n, 1);
    edge.resize(n, -1);
    depth.resize(n, 0);
    dist.resize(n, T{});
  }

  private:
  void Dfs(int v) {
    order.push_back(v);
    for (auto id : g[v]) {
      auto e = edges[id];
      int nxt = e.u ^ e.v ^ v;
      if (nxt == parent[v]) {
        continue;
      }
      depth[nxt] = depth[v] + 1;
      parent[nxt] = v;
      root[nxt] = root[v];
      edge[nxt] = id;
      dist[nxt] = dist[v] + e.w;
      Dfs(nxt);
      sz[v] += sz[nxt];
    }
  }

  void root_dfs(int v) {
    root[v] = v;
    Dfs(v);
  }


  public:
  void dfs(int v) {
    if (depth.empty()) {
      init();
    }
    root_dfs(v);
  }
  
  void dfs_all() {
    if (order.empty()) {
      init();
    }
    for (int i = 0; i < n; ++i) {
      if (parent[i] == -1) {
        root_dfs(i);
      }
    }    
  }

  dfs_forest(int _n) : forest<T>(_n) { }

  dfs_forest(const forest<T> _g) : forest<T>(_g) { }

};
