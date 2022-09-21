#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int S[1000], top;

int pop(){
  top--;
  return S[top+1];
}

void push(int x){
  S[++top] = x;
}

int main() {
  int a, b;
  top = 0;
  char s[100];

  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      a = pop();
      b = pop();
      push(a + b);

    } else if (s[0] == '-') {
      b = pop();
      a = pop();
      push(a - b);

    } else if (s[0] == '*') {
      a = pop();
      b = pop();
      push(a * b);

    } else {
      push(atoi(s));
    }
  }

  printf("%d\n", pop());

  return 0;
}
