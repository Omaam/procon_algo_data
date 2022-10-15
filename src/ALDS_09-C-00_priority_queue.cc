#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define INFTY (1<<30)


int idx_last = 0, heap[2000001];


int get_left_index(int idx) {
  return 2 * idx;
}


int get_right_index(int idx) {
  return 2 * idx + 1;
}


int get_parent_index(int idx) {
  return idx / 2;
}

void heapify_max(int idx) {
  int idx_l = get_left_index(idx);
  int idx_r = get_right_index(idx);

  // Search the largest key among self, left, or right.
  int idx_largest;
  if (idx_l <= idx_last && heap[idx_l] > heap[idx]) {
    idx_largest = idx_l;
  } else {
    idx_largest = idx;
  }
  if (idx_r <= idx_last && heap[idx_r] > heap[idx_largest]) {
    idx_largest = idx_r;
  }

  if (idx_largest != idx) {
    swap(heap[idx_largest], heap[idx]);
    heapify_max(idx_largest);
  }
}


int extract_heap(){
  if (idx_last < 1) return -INFTY;
  int max = heap[1];
  heap[1] = heap[idx_last--];
  heapify_max(1);
  return max;
}


void increase_key_heap(int idx, int key) {
  if (key < heap[idx]) return;
  heap[idx] = key;
  while (idx > 1 && heap[idx/2] < heap[idx]) {
    swap(heap[idx], heap[idx/2]);
    idx = idx / 2;
  }
}


void insert_heap(int key) {
  idx_last++;
  heap[idx_last] = -INFTY;
  increase_key_heap(idx_last, key);
}



int main() {
  string command;
  int key;
  while (1) {
    cin >> command;
    if (command == "insert") {
      scanf("%d", &key);
      insert_heap(key);
    } else if (command == "extract") {
      int ext = extract_heap();
      printf("%d\n", ext);
    } else if (command == "end") {
      break;
    }
  }

  return 0;
 }
