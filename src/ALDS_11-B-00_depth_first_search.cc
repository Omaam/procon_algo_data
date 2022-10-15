#include<algorithm>
#include<cstdio>
#include<set>
#include<stack>
using namespace std;

int n, time = 1;
int adj_mat[2000][2000] = {};
int f[1000] = {}, g[1000] = {};
stack<int> st;
set<int> remains;


void create_adjcent_matirix() {
  for (int i = 1; i < n + 1; i++) {
    int k, u;
    scanf("%d %d", &u, &k);
    for (int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      adj_mat[u][c] = 1;
    }
  }
}


void push_to_stack(int idx) {
  st.push(idx);
  f[idx] = time++;
  for (int i = 1; i < n + 1; i++) {
    printf("%d %d\n", idx, i);
    printf("%d\n", adj_mat[idx][i]);
    if (adj_mat[idx][i] == 1 && remains.find(i) != remains.end()) {
      printf("Stack!\n");
      push_to_stack(i);
    } else if (remains.find(i) == *remains.end()) {
      printf("Stack!\n");
      push_to_stack(i);
    }
  }
  printf("END\n");
  printf("%d\n", st.empty());
  if (st.empty()) return;
  int idx_target = st.top();
  st.pop();
  g[idx_target] = time++;
}


int main() {

  scanf("%d", &n);
  create_adjcent_matirix();
  for (int i = 1; i < n + 1; i++) remains.insert(i);

  printf("**********\n");
  while (remains.size() != 0) {
    set<int>::iterator iter = remains.begin();
    push_to_stack(*iter);
  }

  for (int i = 1; i < n + 1; i++) printf("%d %d\n", f[i], g[i]);

  return 0;
}
