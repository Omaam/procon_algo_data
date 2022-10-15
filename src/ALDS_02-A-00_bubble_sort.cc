#include<iostream>
using namespace std;

int sort_by_bubble(int arr[], int n) {
  int sw = 0;
  int flag = 1;
  for (int i = n; flag; i--) {
    flag = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        sw ++;
        flag = 1;
      }
    }
  }
  return sw;
}

int main(){
  int n;
  cin >> n;

  int arr[n] = {0};
  for (int i = 0; i < n; i++) cin >> arr[i];

  int sw;
  sw = sort_by_bubble(arr, n);

  // Print.
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << arr[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
