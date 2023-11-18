// Problem: E. Connected Components?
// Contest: Codeforces - Educational Codeforces Round 37 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/920/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 200100;

int n, m;
bool vis[maxn];
set<int> S[maxn];

struct DSU {
	int fa[maxn], sz[maxn];
	
	inline void init() {
		for (int i = 1; i <= n + 1; ++i) {
			fa[i] = i;
			sz[i] = 1;
		}
	}
	
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	
	inline void merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x != y) {
			fa[x] = y;
			sz[y] += sz[x];
		}
	}
} D, d;

void dfs(int u) {
	vis[u] = 1;
	D.fa[u] = u + 1;
	for (int v = D.find(1); v <= n; v = D.find(v + 1)) {
		if (S[u].find(v) == S[u].end()) {
			d.merge(u, v);
			dfs(v);
		}
	}
}

void solve() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		S[u].insert(v);
		S[v].insert(u);
	}
	D.init();
	d.init();
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			dfs(i);
		}
	}
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (d.fa[i] == i) {
			ans.pb(d.sz[i]);
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
}

int main() {
	int T = 1;
	// scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}