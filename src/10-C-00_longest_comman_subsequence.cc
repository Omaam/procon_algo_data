#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;


int get_lcs(string x, string y) {
  int m = x.size();
  int n = y.size();

  int c[m+1][n+1];
  for (int i = 0; i < m + 1; i++) c[i][0] = 0;
  for (int j = 1; j < n + 1; j++) c[0][j] = 0;
  x = ' ' + x;
  y = ' ' + y;

  int maxl = 0;
  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (x[i] == y[j]) {
        c[i][j] = c[i-1][j-1] + 1;
      } else {
        c[i][j] = max(c[i][j-1], c[i-1][j]);
      }
      maxl = max(maxl, c[i][j]);
    }
  }
  return maxl;
}


int main() {
  int q;
  scanf("%d", &q);

  string x, y;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    int maxl = get_lcs(x, y);
    printf("%d\n", maxl);
  }

  return 0;
}
