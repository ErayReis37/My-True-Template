
template<typename T> vector<T> djikstra(const undigraph<T>& g, int sv) {
  assert(sv < g.n);
  vector<T> res(g.n, numeric_limits<T>::max());
  vector<bool> vis(g.n);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
  pq.emplace(0, sv);
  res[sv] = 0;
  while (!pq.empty()) {
    int v;
    T cost;
    tie(cost, v) = pq.top();
    pq.pop();
    if (vis[v]) {
      continue;
    }
    vis[v]  = true;
    for (auto id : g.g[v]) {
      int nxt = g.edges[id].u ^ g.edges[id].v ^ v;
      T nCost = cost + g.edges[id].w;
      if (vis[nxt] || res[nxt] < nCost) {
        continue;
      }
      res[nxt] = nCost;
      pq.emplace(nCost, nxt);
    }
  }
  return res; 
}
