#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int MAXN = 2e5;
 
ll n;
ll tree[4 * MAXN], a[MAXN];
 
void build(ll id, ll l, ll r) {
  if (l > r) return;
  if (l == r) {
    tree[id] = a[l];
    return;
  }
  build(id * 2, l, (l + r) / 2);
  build(id * 2 + 1, (l + r) / 2 + 1, r);
  tree[id] = tree[id * 2] ^ tree[id * 2 + 1];
}
 
ll query(ll id, ll L, ll R, ll l, ll r) {
  if (L > r || l > R) return 0;
  if (l <= L && R <= r) return tree[id];
  return query(id * 2, L, (L + R) / 2, l, r) ^ query(id * 2 + 1, (L + R) / 2 + 1, R, l, r);
}
 
int main() {
  cin >> n;
  ll Q;
  cin >> Q;
  for (ll i = 0; i < n; i++) cin >> a[i];
  build(1, 0, n - 1);
  while (Q--) {
    ll l, r;
    cin >> l >> r;
    cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
  }
  return 0;
}
