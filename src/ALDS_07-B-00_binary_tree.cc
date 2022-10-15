// TODO: Solve depth and height.
//
#include<iostream>
#include<cstdio>
#define NIL -1
using namespace std;


struct Node {
  int parent, left, right;
};


void add_parent(Node nodes[], int idx) {
  if (nodes[idx].left != NIL) {
    nodes[nodes[idx].left].parent = idx;
    add_parent(nodes, nodes[idx].left);
  }
  if (nodes[idx].right != NIL) {
    nodes[nodes[idx].right].parent = idx;
    add_parent(nodes, nodes[idx].right);
  }
}


void get_depth(Node nodes[], int depths[], int depth, int idx) {
  depths[idx] = depth;
  if (nodes[idx].left != NIL) {
    get_depth(nodes, depths, depth + 1, nodes[idx].left);
  }
  if (nodes[idx].right != NIL) {
    get_depth(nodes, depths, depth + 1, nodes[idx].right);
  }
}


int get_degree(Node node) {
  int degree = 0;
  if (node.left != NIL) degree++;
  if (node.right != NIL) degree++;
  return degree;
}


int set_height(Node nodes[], int heights[], int height, int idx) {
  int height_left = 0, height_right = 0;
  if (nodes[idx].left != NIL){
    height_left = set_height(nodes, heights, height, nodes[idx].left) + 1;
  }
  if (nodes[idx].right != NIL){
    height_right = set_height(nodes, heights, height, nodes[idx].right) + 1;
  }
  return heights[idx] = (height_left > height_right ? height_left : height_right);
}


int get_sibling(int id_own, Node nodes[]) {
  if (nodes[id_own].parent == NIL) {
    return NIL;
  } else if (nodes[nodes[id_own].parent].right == id_own) {
    return nodes[nodes[id_own].parent].left;
  } else {
    return nodes[nodes[id_own].parent].right;
  }
}


string judge_type(Node node) {
  if (node.parent == NIL) return "root";
  if (node.left == NIL && node.right == NIL) return "leaf";
  else return "internal node";
}


void print(Node nodes[], int depths[], int heights[], int i) {
  cout << "node " << i << ": ";
  cout << "parent = " << nodes[i].parent << ", ";
  cout << "sibling = " << get_sibling(i, nodes) << ", ";
  cout << "degree = " << get_degree(nodes[i]) << ", ";
  cout << "depth = " << depths[i] << ", ";
  cout << "height = " << heights[i] << ", ";
  cout << judge_type(nodes[i]) << endl;
}


int main() {
  int n;
  cin >> n;

  // Create tree.
  Node nodes[n];
  for (int i = 0; i < n; i++) {
    int id;
    cin >> id >> nodes[i].left >> nodes[i].right;
  }
  add_parent(nodes, 0);

  // Search root index.
  int idx_root = 0;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parent = NIL) idx_root = i;
  }

  int depths[n] = {};
  get_depth(nodes, depths, 0, idx_root);

  int heights[n] = {};
  set_height(nodes, heights, 0, idx_root);


  // Print.
  for (int i = 0; i < n; i++) print(nodes, depths, heights, i);

  return 0;
}
