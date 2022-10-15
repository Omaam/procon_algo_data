//COMPLETE!
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;


int main() {
  int n;
  scanf("%d", &n);

  string command;
  int key;
  for (int i = 0; i < n; i++) {
    cin >> command;
    if (command == "find") {
      scanf("%d", &key);
      Node *target = find(key);
      if (target != NIL) printf("yes\n");
      else printf("no\n");
    } else if (command == "insert") {
      scanf("%d", &key);
      insert(key);
    } else if (command == "print") {
      print_inorder(root);
      printf("\n");
      print_preorder(root);
      printf("\n");
    }
  }
  return 0;
}
