
template<typename T> class dfs_tree : public undigraph<T> {
  public:
  using undigraph<T>::n;  
  using undigraph<T>::g;
  using undigraph<T>::edges;

  vector<int> depth, parent, root, sz, edge, back, child, order;
  vector<T> dist;
  vector<bool> is_back;

  void clear() {
    depth.clear();
    parent.clear();
    root.clear();
    sz.clear();
    edge.clear();
    depth.clear();
    dist.clear();
    back.clear();
    child.clear();
    order.clear(); 
    is_back.clear();
  }

  void init() {
    depth.resize(n, 0);
    parent.resize(n, -1);
    root.resize(n, -1);
    sz.resize(n, 1);
    edge.resize(n, -1);
    depth.resize(n, 0);
    dist.resize(n, T{});
    back.resize(n, 0);
    child.resize(n, 0);
    is_back.resize((int) edges.size(), true);
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
      if (parent[nxt] == -1 && root[v] != nxt) {
        is_back[id] = false;
        depth[nxt] = depth[v] + 1;
        parent[nxt] = v;
        root[nxt] = root[v];
        edge[nxt] = id;
        dist[nxt] = dist[v] + e.w;
        Dfs(nxt);
        ++child[v];
        sz[v] += sz[nxt];
        back[v] += back[nxt];
      } else if (depth[nxt] < depth[v]) {
        ++back[v];
      } else {
        --back[v];      
      }
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

  dfs_tree(int _n) : undigraph<T>(_n) { }

  dfs_tree(const undigraph<T> _g) : undigraph<T>(_g) { }

};
