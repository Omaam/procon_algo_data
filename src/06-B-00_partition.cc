#include<iostream>
using namespace std;

int arr[200000];

int partition(int p, int r) {
  int x = arr[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (arr[j] <= x) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  return i + 1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  int q = partition(0, n-1);

  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    if (i == q) cout << "[";
    cout << arr[i];
    if (i == q) cout << "]";
  }
  cout << endl;

  return 0;
}
