#include<cstdlib>
#include<iostream>
using namespace std;


struct Node {
  int key;
  Node *parent, *left, *right;
};


Node *root, *NIL;


void delete_node(int key) {
  Node *target = find(key);
  if (target -> left == NIL && target -> right == NIL) {
    target -> parent = NIL;
  } else if (target -> left != NIL && target -> right != NIL) {
  else if (!(target -> left != NIL && target -> right != NIL) {
}


Node * find(int key) {
  Node *u = root;
  while (u != NIL  && key != u -> key) {
    if (key < u -> key) {
      u = u -> left;
    } else {
      u = u -> right;
    }
  }
  return u;
}


void insert(int key) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z -> key = key;
  z -> left = NIL;
  z -> right = NIL;
  while (x != NIL) {
    y = x;
    if (z -> key < x -> key) {
      x = x -> left;
    } else {
      x = x -> right;
    }
  }
  z -> parent = y;

  if (y == NIL) {
    root = z;
  } else if (z -> key < y -> key) {
    y -> left = z;
  } else {
    y -> right = z;
  }
}


void print_inorder(Node *node) {
  if (node == NIL) return;
  print_inorder(node -> left);
  printf(" %d", node -> key);
  print_inorder(node -> right);
}


void print_postorder(Node *node) {
  if (node == NIL) return;
  print_postorder(node -> left);
  print_postorder(node -> right);
  printf(" %d", node -> key);
}


void print_preorder(Node *node) {
  if (node == NIL) return;
  printf(" %d", node -> key);
  print_preorder(node -> left);
  print_preorder(node -> right);
}



int main() {
  return 0;
}
