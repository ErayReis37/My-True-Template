
template<typename T> vector<bool> bridges(dfs_tree<T> d) {
  if (d.depth.empty()) {
    d.dfs_all();
  }
  vector<bool> is((int) d.edges.size());
  for (int i = 0; i < d.n; ++i) {
    if (d.parent[i] == -1) {
      continue;
    }
    if (d.back[i] == 0) {
      is[d.edge[i]] = true;
    }
  }
  return is;
}
