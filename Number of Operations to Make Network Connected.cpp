class UnionFind {
  vector<int> root;
  vector<int> rank;
  int numComponents;

public:
  UnionFind(int size) : root(size), rank(size) {
    for (int i = 0; i < size; i++) {
      root[i] = i;
      rank[i] = 0;
    }
    numComponents = size;
  }

  int getRoot(int n) {
    if (root[n] == n) return n;
    return root[n] = getRoot(root[n]);
  }

  void doUnion(int x, int y) {
    int rootX = getRoot(x);
    int rootY = getRoot(y);
    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY]) {
        root[rootY] = rootX;
      } else if (rank[rootX] < rank[rootY]) {
        root[rootX] = rootY;
      } else {
        root[rootY] = rootX;
        rank[rootX] += 1;
      }
      numComponents -= 1;
    }
  }

  int getNumComponents() {
    return numComponents;
  }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;

        UnionFind uf(n);
        for (vector<int>& edge : connections) {
            uf.doUnion(edge[0], edge[1]);
        }

        return (uf.getNumComponents() - 1);
    }
};