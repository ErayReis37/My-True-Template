
template<typename T> class graph {
  public:
  struct edge {
    int v, u;
    T w;
  };
   
  int n;
  vector<vector<int>> g;
  vector<edge> edges;
  
  graph(int _n) : n(_n) { 
    g.resize(n);  
  }

  graph(const graph<T>& _g) {
    n = _g.n;
    g = _g.g;
    edges = _g.edges;
  }

  graph() { }

  void clear() {
    n = 0;
    g.clear();
    edges.clear();
  }

  virtual int add(int v, int u, T w = 1) = 0; 
};
