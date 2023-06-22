#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define endl '\n';
typedef long long ll;
typedef long double ld;
using namespace std;
 
const int inf = 2e9;
const int N = 2e5 + 10;
int x[N];
int tree[4 * N];
int n, q;
int L, R;
int I, V;
 
void update(int node, int lo, int hi) {
  if (I < lo || hi < I) return;
  if (lo == hi) {
    tree[node] = V;
    return;
  }
  int mid = (lo + hi) / 2;
  update(2 * node + 1, lo, mid);
  update(2 * node + 2, mid + 1, hi);
  tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}
 
int query(int node, int lo, int hi) {
  if (R < lo || hi < L) return inf;
  if (L <= lo && hi <= R) {
    return tree[node];
  }
  int mid = (lo + hi) / 2;
  return min(
    query(2 * node + 1, lo, mid), 
    query(2 * node + 2, mid + 1, hi)
  );
}
 
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", x + i);
    I = i; V = x[i];
    update(0, 1, n);
  }
  for (int i = 1; i <= q; i++) {
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);
    if (t == 1) {
      I = a; V = b;
      update(0, 1, n);
    } else {
      L = a; R = b;
      printf("%d\n", query(0, 1, n));
    }
  }
  return 0;
}
