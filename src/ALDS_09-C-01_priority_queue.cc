#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;


int main() {
  priority_queue<int> pq;

  string command;
  int key;
  while (1) {
    cin >> command;
    if (command == "end") break;
    else if (command == "insert") {
      scanf("%d", &key);
      pq.push(key);
    } else if (command == "extract") {
      printf("%d\n", pq.top());
      pq.pop();
    }
  }
  return 0;
}
