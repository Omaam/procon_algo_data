#include<cstdio>
#include<queue>
using namespace std;

int n;
int adj_mat[2000][2000], d[2000] = {-1};
queue<int> qu;

void create_adjcent_matirix() {
  for (int i = 1; i < n + 1; i++) {
    int k, u;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      adj_mat[u][c] = 1;
    }
  }
}


void push_queue(int i) {
  qu.push(i);
  qu.push(NIL);
  for (int j = 1; j < n + 1; j++) {
    if (adj_mat[i][j]) qu.push(j);
  }
  qu.top()
}


void do_bfs() {
  push_queue(1)
}


int main() {
  scanf("%d", &n);
  create_adjcent_matirix()

  do_bfs();

  return 0;
}
