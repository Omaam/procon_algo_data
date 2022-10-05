#include<iostream>
using namespace std;

class Stack{
  int top = 0;
  int S[];

  Stack(int n) {
    int S[n];
  }

  int pop() {
    top--;
    return S[top+1];
  }

  void push(int x) {
    S[++top] = x;
  }
};

int main() {

  Stack st(1000);
  char s[100];

  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      a = st.pop();
      b = st.pop();
      st.push(a + b);

    } else if (s[0] == '-') {
      b = st.pop();
      a = st.pop();
      st.push(a - b);

    } else if (s[0] == '*') {
      a = st.pop();
      b = st.pop();
      st.push(a * b);

    } else {
      st.push(atoi(s));
    }
  }

  cout << st.pop << endl;

  return 0;
}
