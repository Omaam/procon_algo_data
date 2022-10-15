#include<cstdio>

int main() {
  int n;
  scanf("%d", &n);

  int adj[n+1][n+1] = {};
  for (int i = 1; i < n + 1; i++) {
    int k, u;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      adj[u][c] = 1;
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (j - 1) printf(" ");
      printf("%d", adj[i][j]);
    }
    printf("\n");
  }

  return 0;
}
