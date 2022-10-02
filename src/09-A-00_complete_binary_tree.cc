#include<cstdio>
using namespace std;


int main() {
  int n;
  scanf("%d", &n);

  int tree[n+1];
  for (int i = 1; i <= n; i++) scanf("%d", &tree[i]);

  for (int i = 1; i <= n; i++) {
    int idx_p = i / 2;
    int idx_l = 2 * i;
    int idx_r = 2 * i + 1;
    printf("node %d: ", i);
    printf("key = %d, ", tree[i]);
    if (idx_p > 0) printf("parent key = %d, ", tree[idx_p]);
    if (idx_l <= n) printf("left key = %d, ", tree[idx_l]);
    if (idx_r <= n) printf("right key = %d, ", tree[idx_r]);
    printf("\n");
  }

  return 0;
 }
