#include<stdio.h>
#include<string.h>
#define LEN 100005

typedef struct pp {
char name[1000];
  int t;
} P;

P queue[LEN];
int head, tail, n;

void enqueue(P x) {
  queue[tail] = x;
  tail = (tail + 1) % LEN;
}

P dequeue() {
  P x = queue[head];
  head = (head + 1) % LEN;
  return x;
}

int min(int a, int b) {
  return a < b ? a: b;
}

int main(){
  int elaps = 0, c;
  int q;
  P u;
  scanf("%d %d", &n, &q);

  head = 1;
  tail = n + 1;

  for (int i = 1; i <= n; i++) {
    scanf("%s", &queue[i].name);
    scanf("%d", &queue[i].t);
  }

  // Simulation
  while (head != tail) {

    u = dequeue();

    c = min(q, u.t);
    u.t -= q;
    elaps += c;

    if (u.t <= 0){
      printf("%s %d\n", u.name, elaps);
    } else {
      enqueue(u);
    }
  }

  return 0;
}
