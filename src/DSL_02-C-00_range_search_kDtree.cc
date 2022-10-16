#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define NIL -1
#define MAX 1000000

class Node {
  public:
    int location;
    int p, left, right;
  Node(){}
};

class Point {
  public:
    int id, x, y;
  Point(){}
  Point(int id, int x, int y): id(id), x(x), y(y) {}
  bool operator < (const Point &p) const {
    return id < p.id;
  }

  void print() {
    printf("%d\n", id);
  }
};

Point points[MAX];
Node tree[MAX];
int np;

bool judge_less_x(const Point &p1, const Point &p2) {
  return p1.x < p2.x;
}

bool judge_less_y(const Point &p1, const Point &p2) {
  return p1.y < p2.y;
}

int make_kdtree(int left, int right, int depth) {
  if (!(left < right)) return NIL;

  int mid = (left + right) / 2;
  int t = np++;

  if (depth % 2 == 0) {
    sort(points + left, points + right, judge_less_x);
  } else {
    sort(points + left, points + right, judge_less_y);
  }
  tree[t].location = mid;
  tree[t].left = make_kdtree(left, mid, depth + 1);
  tree[t].right = make_kdtree(mid + 1, right, depth + 1);

  return t;
}

void find_within_range(int v, int sx, int tx, int sy, int ty,
                       int depth, vector<Point> &ans) {

  int x = points[tree[v].location].x;
  int y = points[tree[v].location].y;

  if (sx <= x && x <= tx && sy <= y && y <= ty) {
    ans.push_back(points[tree[v].location]);
  }

  if (depth % 2 == 0) {
    if (tree[v].left != NIL) {
      if (sx <= x) {
        find_within_range(tree[v].left, sx, tx, sy, ty, depth + 1, ans);
      }
    }
    if (tree[v].right != NIL) {
      if (x <= tx) {
        find_within_range(tree[v].right, sx, tx, sy, ty, depth + 1, ans);
      }
    }
  } else {
    if (tree[v].left != NIL) {
      if (sy <= y) {
        find_within_range(tree[v].left, sx, tx, sy, ty, depth + 1, ans);
      }
    }
    if (tree[v].right != NIL) {
      if (y <= ty) {
        find_within_range(tree[v].right, sx, tx, sy, ty, depth + 1, ans);
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int x, y;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    points[i] = Point(i, x, y);
    tree[i].left = tree[i].right = tree[i].p = NIL;
  }

  np = 0;

  int root = make_kdtree(0, n, 0);

  int q;
  scanf("%d", &q);
  int sx, tx, sy, ty;
  vector<Point> ans;
  for (int i = 0; i < q; i++) {
    ans.clear();
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    find_within_range(root, sx, tx, sy, ty, 0, ans);
    sort(ans.begin(), ans.end());
    for (int j = 0; j < ans.size(); j++) {
      ans[j].print();
    }
    printf("\n");
  }

  return 0;
}
