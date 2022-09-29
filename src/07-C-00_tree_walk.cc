// Complete!
#include<iostream>
#include<cstdio>
using namespace std;
#define NIL -1


struct Node {
  int parent, left, right;
};


void print_inorder(int idx, Node nodes[]) {
  if (idx == NIL) return;
  print_inorder(nodes[idx].left, nodes);
  printf(" %d", idx);
  print_inorder(nodes[idx].right, nodes);
}


void print_postorder(int idx, Node nodes[]) {
  if (idx == NIL) return;
  print_postorder(nodes[idx].left, nodes);
  print_postorder(nodes[idx].right, nodes);
  printf(" %d", idx);
}


void print_preorder(int idx, Node nodes[]) {
  if (idx == NIL) return;
  printf(" %d", idx);
  print_preorder(nodes[idx].left, nodes);
  print_preorder(nodes[idx].right, nodes);
}


int main(){

  int n;
  scanf("%d", &n);

  // Create tree.
  Node nodes[n];
  for (int i = 0; i < n; i++) nodes[i].parent = NIL;
  for (int i = 0; i < n; i++) {
    int id, l, r;
    scanf("%d %d %d", &id, &l, &r);
    nodes[id].left = l;
    nodes[id].right = r;
    if (nodes[id].left != NIL) {
      nodes[nodes[id].left].parent = nodes[id].left;
    }
    if (nodes[id].right != NIL) {
      nodes[nodes[id].right].parent = nodes[id].right;
    }
  }

  // Search root index.
  int idx_root = 0;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parent == NIL) idx_root = i;
  }

  printf("Preorder\n");
  print_preorder(idx_root, nodes);
  printf("\n");

  printf("Inorder\n");
  print_inorder(idx_root, nodes);
  printf("\n");

  printf("Postorder\n");
  print_postorder(idx_root, nodes);
  printf("\n");

  return 0;
}
