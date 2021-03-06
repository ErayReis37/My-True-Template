
template<typename T> vector<T> djikstra_sq(const undigraph<T>& g, int sv) {
  assert(sv < g.n);
  vector<T> res(g.n, numeric_limits<T>::max());
  vector<bool> vis(g.n);
  queue<int> q;  
  res[sv] = 0;
  q.push(sv);
  vector<vector<T>> mat(g.n, vector<T>(g.n, -1));
  for (auto[v, u, w] : g.edges) {
   mat[u][v] = w;
   mat[v][u] = w;
  }
  int v = sv;
  while (v != -1) {
    vis[v] = true;
    int next_v = -1;
    T next_cost = numeric_limits<T>::max();
    for (int i = 0; i < g.n; ++i) {
      if (mat[v][i] != -1) {
        res[i] = min(res[i], res[v] + mat[v][i]); 
      }
      if (!vis[i] && res[i] < next_cost) {
        next_cost = res[i];
        next_v = i;
      }
    }
    v = next_v;
  }
  return res; 
}
