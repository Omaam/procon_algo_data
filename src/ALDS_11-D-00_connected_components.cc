#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
#define MAX 1000000
#define NIL -1


int n;
vector<int> adj_list[MAX];
int colors[MAX];

void depth_first_search(int r, int c){
  stack<int> st;
  st.push(r);
  colors[r] = c;
  while (!st.empty()) {
    int u = st.top(); st.pop();
    for (int i = 0; i < adj_list[u].size(); i++) {
      int v = adj_list[u][i];
      if (colors[v] == NIL) {
        colors[v] = c;
        st.push(v);
      }
    }
  }
}

void create_adjlist(int n, int m) {
  for (int i = 0; i < m; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    adj_list[s].push_back(t);
    adj_list[t].push_back(s);
  }
}

void assign_color() {
  int color = 0;
  for (int i = 0; i < n; i++) colors[i] = NIL;
  for (int i = 0; i < n; i++) {
    if (colors[i] == NIL) depth_first_search(i, color++);
  }
}


int main(){
  int m;
  scanf("%d %d", &n, &m);

  create_adjlist(n, m);

  assign_color();

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    if (colors[s] == colors[t]) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}
