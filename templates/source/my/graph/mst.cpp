
template<typename T> vector<int> mst(const forest<T>& g) {
  vector<int> res;
  vector<int> ord(g.n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) {
    return g.edges[x].w < g.edges[y].w;
  });
  dsu d(g.n);
  for (auto id : ord) {
    if (d.unite(g.edges[id].v, g.edges[id].u)) {
      res.push_back(id);  
    }
  }
  return res;
}
