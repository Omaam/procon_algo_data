#include<cstdio>
#include<iostream>
using namespace std;

struct Card { char s; int t; };


int partition(Card arr[], int p, int r) {
  Card x = arr[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (arr[j].t <= x.t) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i+1], arr[r]);
  // print
  for (int i = 0; i < 6; i++) {
    cout << arr[i].s << " " <<  arr[i].t << endl;
  }
  return i + 1;
}


void quick_sort(Card arr[], int p, int r) {
  if (p < r) {
    int q = partition(arr, p, r);
    quick_sort(arr, p, q - 1);
    quick_sort(arr, q + 1, r);
  }
}


int main() {

  Card arr[1000000];

  int n, t;
  char s[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %d", s, &t);
    arr[i].s = s[0];
    arr[i].t = t;
  }

  quick_sort(arr, 0, n);

  // print
  for (int i = 0; i < n; i++) {
    cout << arr[i].s << " " <<  arr[i].t << endl;
  }

  return 0;
}
