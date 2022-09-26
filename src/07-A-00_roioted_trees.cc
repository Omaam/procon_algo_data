// Not complete.
#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node {
  int parent, right, left;
};


void print_node(int idx, Node node) {
  cout << idx << " " << node.parent
    << " " << node.left << " "
    << node.right << endl;
}


int main(){

  // Create tree.
  int n, id, num_child, child, sibling;
  cin >> n;
  Node nodes[n] = {NIL};
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

  // Print information from nodes.
  // TODO: Fill this.

  return 0;
}
