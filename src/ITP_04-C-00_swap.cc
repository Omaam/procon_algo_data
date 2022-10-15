#include<iostream>
using namespace std;


int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  int q;
  cin >> q;
  for (int j = 0; j < q; j++) {
    int b, e, t;
    cin >> b >> e >> t;
    for (int k = 0; k < e - b; k++) {
      swap(arr[b+k], arr[t+k]);
    }
  }
  for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << arr[i];
  }
  cout << endl;

  return 0;
}
