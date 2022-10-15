#include<iostream>
#include<cstdio>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;
  int coins[m];
  for (int j = 0; j < m; j++) cin >> coins[j];

  int least[n+1];
  least[0] = 0;
  for (int i = 1; i < n + 2; i++) least[i] = (1 << 21);

  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < m; j++) {
      int price = coins[j];
      if (i - price >= 0) {
        least[i] = min(least[i], least[i-price] + 1);
      }
    }
  }
  cout << least[n] << endl;

  return 0;
}
