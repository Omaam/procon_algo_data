#include<cstdio>
#define MAX 1000000

class DisjointTree {
  public:
    int pointer;
  DisjointTree(){}
  DisjointTree(int pointer): pointer(pointer) {}
};

DisjointTree forest[MAX];
int ranks[MAX];

void init_disjoint_tree(int n) {
  for (int i = 0; i < n; i++) {
    forest[i].pointer = i;
    ranks[i] = 0;
  }
}

int search_representative(int idx) {
  if (forest[idx].pointer == idx) return idx;
  else search_representative(forest[idx].pointer);
}

void unite(int x, int y) {
  int r_x = search_representative(x);
  int r_y = search_representative(y);
  if (ranks[r_x] >= ranks[r_y]) {
    forest[r_y].pointer = r_x;
    ranks[r_x] += 1;
  } else {
    forest[r_x].pointer = r_y;
    ranks[r_y] += 1;
  }
}

void find(int x, int y) {
  int r_x = search_representative(x);
  int r_y = search_representative(y);
  if (r_x == r_y) printf("1\n");
  else printf("0\n");
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  init_disjoint_tree(n);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    scanf("%d %d %d", &com, &x, &y);

    if (com == 0) unite(x, y);
    else find(x, y);
  }

  return 0;
}
