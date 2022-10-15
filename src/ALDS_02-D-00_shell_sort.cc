#include<iostream>
#include<vector>
using namespace std;

vector<int> gg;

int insertion_sort(long arr[], long n, int g) {
  long cnt = 0;
  for (int i = g; i < n; i++){
    int v = arr[i];
    int j = i - g;
    while (j >= 0 && arr[j] > v) {
      arr[j+g] = arr[j];
      j -= g;
      cnt++;
    }
    arr[j+g] = v;
  }
  return cnt;
}

long shell_sort(long arr[], long n) {

  for (int h = 1; ; ) {
    if (h > n) break;
    gg.push_back(h);
    h = 3 * h + 1;
  }
  int m = gg.size();

  // Print.
  cout << m << endl;
  for (int i = m-1; i >= 0; i--) {
    if (i != m-1) cout << " ";
    cout << gg[i];
  }
  cout << endl;

  long cnt = 0;
  for (int i = m - 1; i >= 0; i--) {
    cnt += insertion_sort(arr, n, gg[i]);
  }
  return cnt;
}

int main() {
  long n;
  cin >> n;

  long arr[n] = {0};
  for (int i = 0; i < n; i++) cin >> arr[i];

  long cnt = shell_sort(arr, n);
  cout << cnt << endl;

  for (int i = 0; i < n; i++){
    cout << arr[i] << endl;
  }

  return 0;
}
