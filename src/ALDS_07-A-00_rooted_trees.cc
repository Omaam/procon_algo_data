#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
  int parent, right, left;
};


void get_depth(Node nodes[], int depths[], int depth, int idx) {
  depths[idx] = depth;
  if (nodes[idx].left != NIL) {
    get_depth(nodes, depths, depth + 1, nodes[idx].left);
  }
  if (nodes[idx].right != NIL) {
    get_depth(nodes, depths, depth, nodes[idx].right);
  }
}


void print_node(int idx, Node node) {
  cout << idx << " " << node.parent
    << " " << node.left << " "
    << node.right << endl;
}


void print_siblings_rec(Node nodes[], int idx) {
  if (nodes[idx].right != NIL) {
    cout << ", " << nodes[idx].right;
    print_siblings_rec(nodes, nodes[idx].right);
  }
}


int main(){

  // Create tree.
  int n, id, num_child, child, sibling;
  cin >> n;

  // Initialize nodes.
  Node nodes[n];
  for (int i = 0; i < n; i++) {
    nodes[i].parent = NIL;
    nodes[i].left = NIL;
    nodes[i].right = NIL;
  }

  // Create tree.
  for (int i = 0; i < n; i++) {
    cin >> id >> num_child;
    for (int j = 0; j < num_child; j++) {
      cin >> child;
      if (j == 0) nodes[id].left = child;
      else nodes[sibling].right = child;
      sibling = child;  // Next child is stored as sibling.
      nodes[child].parent = id;
    }
  }

  // Search parent.
  int idx_root;
  for (int i = 0; i < n; i++) {
    if (nodes[i].parent == NIL) idx_root = i;
  }

  // Calculate depths recursively.
  int depths[n] = {};
  get_depth(nodes, depths, 0, idx_root);

  // Print information from nodes.
  for (int i = 0; i < n; i++) {
    cout << "node " << i << ": ";
    cout << "parent = " << nodes[i].parent << ", ";
    cout << "depth = " << depths[i] << ", ";

    if (nodes[i].parent == NIL) cout << "root, ";
    else if (nodes[i].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    cout << "[";
    if (nodes[i].left != NIL) {
      cout << nodes[i].left;
      print_siblings_rec(nodes, nodes[i].left);
    }
    cout << "]" << endl;
  }

  return 0;
}
