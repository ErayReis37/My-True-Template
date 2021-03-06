
class trie {
  public:
  struct node {
    vector<int> way{vector<int>(26, -1)};
    int ct = 0;
  };
  node emp;
  vector<node> trie{vector<node>(1)};
  void insert(string s) {
    int cur = 0;
    for (auto c : s) {
      int tar = c - 'a';
      if (trie[cur].way[tar] == -1) {
        trie[cur].way[tar] = (int) trie.size();
        trie.push_back(emp);
      }
      cur = trie[cur].way[tar];
      ++trie[cur].ct;
    }
  } 
  void erase(string s) {
    int cur = 0;
    for (char c : s) {
      int tar = c - 'a';
      assert(trie[cur].way[tar] != -1);
      cur = trie[cur].way[tar];      
      assert(--trie[cur].ct >= 0);
    }
  }
  int get(string s) {
    int cur = 0;
    for (auto c : s) {
      int tar = c - 'a';
      if (trie[cur].way[tar] == -1) return 0;
      cur = trie[cur].way[tar];
    }
    return trie[cur].ct;
  }
}; 
