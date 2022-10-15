#include<iostream>
using namespace std;

int insertion_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] < arr[j]) {
        for (int k = i; k > j; k--) {
          swap(arr[k-1], arr[k]);
        }
        continue;
      }
    }
    // Print
    for (int i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << arr[i];
    }
    cout << endl;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;

  int arr[n] = {};
  for (int i = 0; i < n; i++) cin >> arr[i];

  insertion_sort(arr, n);

  return 0;
}
