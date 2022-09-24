#include<iostream>
using namespace std;

int selection_sort(int arr[], int n){
  int sw = 0;
  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i+1; j < n; j++) {
      if (arr[minj] > arr[j]) minj = j;
    }
    if (i != minj) {
      swap(arr[i], arr[minj]);
      sw++;
    }
  }
  return sw;
}

int main(){
  int n;
  cin >> n;

  int arr[n] = {0};
  for (int i = 0; i < n; i++) cin >> arr[i];

  int sw = 0;
  sw = selection_sort(arr, n);

  // Print
  for (int i = 0; i < n; i++){
    if (i) cout << " ";
    cout << arr[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}
