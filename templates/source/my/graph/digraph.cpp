
template<typename T> class digraph : public graph<T> {
  public:    
  using graph<T>::n;  
  using graph<T>::g;
  using graph<T>::edges;

  digraph(int _n) : graph<T>(_n) { }
  
  digraph(const digraph<T>& _g) : graph<T>() {
    n = _g.n;
    g = _g.g;
    edges = _g.edges;
  }

  int add(int v, int u, T w = 1) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    int id = (int) edges.size();
    g[v].push_back(id);
    g[u].push_back(id); //for reverse edges
    edges.push_back({v, u, w});
    return id;
  }

  void reverse() {
    for (auto& el : edges) {
      swap(el.u, el.v);
    }
  }
};

