#include<cstdio>
#include<algorithm>
using namespace std;


int n;


int get_left(int idx) {
  return 2 * idx;
}


int get_right(int idx) {
  return 2 * idx + 1;
}


void heapify_max(int heap[], int idx) {
  int idx_l = get_left(idx);
  int idx_r = get_right(idx);

  // Search the largest key among self, left, or right.
  int idx_largest;
  if (idx_l < n + 1 && heap[idx_l] > heap[idx]) {
    idx_largest = idx_l;
  } else {
    idx_largest = idx;
  }
  if (idx_r < n + 1 && heap[idx_r] > heap[idx_largest]) {
    idx_largest = idx_r;
  }

  if (idx_largest != idx) {
    swap(heap[idx_largest], heap[idx]);
    heapify_max(heap, idx_largest);
  }
}


void build_max_heap(int heap[]) {
  for (int i = n / 2; i >= 1; i--) {
    heapify_max(heap, i);
  }
}


int main() {
  scanf("%d", &n);

  int heap[n+1];
  for (int i = 1; i < n + 1; i++) scanf("%d", &heap[i]);

  build_max_heap(heap);

  for (int i = 1; i < n + 1; i++) printf(" %d", heap[i]);
  printf("\n");

  return 0;
}
