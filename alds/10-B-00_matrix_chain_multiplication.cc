#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int main() {
  int n;
  cin >> n;
  int p[n+1];
  for (int i = 1; i < n + 1; i++) cin >> p[i-1] >> p[i];

  int cost[n+1][n+1] = {};
  for (int i = 1; i < n + 1; i++) cost[i][i] = 0;

  for (int l = 2; l < n + 1; l++) {
    for (int i = 1; i < n - l + 2; i++) {
      int j = i + l - 1;
      cost[i][j] = (1 << 21);
      for (int k = i; k < j; k++) {
        cost[i][j] = min(cost[i][j],
                         cost[i][k] + cost[k+1][j] + p[i-1] * p[k] * p[j]);
      }
    }
  }
  printf("%d\n", cost[1][n]);

  return 0;
}
