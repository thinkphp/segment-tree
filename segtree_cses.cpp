/*
⠀⠀⢠⢽⣿⡏⠁⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢧⡹⣇⠀⢿⣿⣿⡄⠀⠀⠀
⠀⠀⢸⢧⣻⡇⠀⠸⡿⡟⢸⠏⣏⣿⣿⣿⣿⡏⢿⠈⡇⠏⠀⢸⣿⣯⣇⠀⠀⠀
⠀⠀⠘⣾⣽⠷⣀⣀⡀⠁⠸⠀⠋⢺⣿⣯⠻⠠⠯⠚⣁⣄⣀⠜⢻⣧⡟⠀⠀⠀
⠀⠀⠀⠈⠽⠀⠉⢻⣿⣿⣿⣿⣷⣤⣿⣷⣶⣿⠿⠿⠛⡻⠁⠀⣿⠎⠀⠀⠀⠀
⠀⠀⠀⠀⠈⢣⠀⠀⠻⠟⠭⠽⠟⠈⠀⠉⠘⠻⠲⠶⠚⠃⠀⠀⠟⠀⠀⠀⠀⠀
⠀⢀⣀⣀⡀⠏⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⡰⣠⣤⣴⣤⡀⠀
⣴⣿⣿⣿⣿⣷⠘⢆⠀⡤⠀⠀⠠⠃⠀⠀⢪⠀⠀⠀⡰⠂⡻⢡⣿⣿⣿⣿⣿⡄
⣿⣿⣿⣿⣿⣿⣷⡈⢢⡘⣷⣤⣄⡹⠦⢶⢥⣤⣴⡻⢀⣾⣷⣾⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣷⣷⣬⣿⣾⣼⣤⣼⣼⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*/
#include <bits/stdc++.h>
    
using namespace std;
 
#define flash ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
#define ll long long
#define ld long double
#define dbg(x) cerr << #x << " = " << x << "\n";
#define ff first
#define ss second
      
const long long INF = 1e9 + 7;
const double MIN = 1e-6;
const long long ARR = 1e6 + 11;
const long long DRR = 1e3 + 11;
const long long MOD = 1e9 + 7;
const int maxn = 2e5 + 10;
 
int n, q;
 
ll a[maxn], t[maxn * 4];
 
void build(int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
	t[v] = t[v * 2] + t[v * 2 + 1];
}
 
ll get(int v, int tl, int tr, int l, int r) {
	if (tl >= l && tr <= r) {
		return t[v];
	}
	if (tl > r || tr < l) {
		return 0;
	}
	int tm = (tl + tr) / 2;
	return get(v * 2, tl, tm, l, r) + get(v * 2 + 1, tm + 1, tr, l, r);
}
 
void press_F_() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << get(1, 1, n, l, r) << '\n';
	}
}
 
int main() {
    flash;	
    int T = 1;
    for (int i = 1; i <= T; i++) {     
        press_F_();
    }    
}
 
// g++ -std=c++17 main.cpp
// ./a.out
