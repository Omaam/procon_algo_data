#include<iostream>
using namespace std;


void print_array(int arr[], int n) {
  // print
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << arr[i];
  }
  cout << endl;
}


void print(int a) {
  cout << a << endl;
}


void counting_sort(int arr[], int brr[], int n, int max) {
  int cnt[max + 1] = {};
  for (int j = 0; j < n; j++) {
    cnt[arr[j]]++;
  }

  for (int i = 1; i <= max+1; i++) {
    cnt[i] = cnt[i] + cnt[i-1];
  }

  for (int j = 0; j < n; j++) {
    brr[cnt[arr[j]]-1] = arr[j];
    cnt[arr[j]]--;
  }
}

int main() {
  int n;
  cin >> n;

  int arr[n] = {}, brr[n] = {}, max = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  counting_sort(arr, brr, n, max);

  print_array(brr, n);

  return 0;
}
