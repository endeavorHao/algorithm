#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, k, m;
int c[N], p[N];
void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ ) cin >> c[i];
	vector<bool> vis(n + 1, false);
	vector<int> ans(n + 1);
	vector<vector<int>> e;
	for(int i = 1; i <= k; i ++ ){
		int x;
		cin >> x;
		c[x] = 0;
		vis[x] = true;
		ans[x] = 0;
	}
	e.clear();
	e.push_back({0});
	for(int i = 1; i <= n; i ++ ){
		cin >> m;
		vector<int> temp;
		for(int j = 0; j < m; j ++ ){
			int x; 
			cin >> x;
			temp.push_back(x);
		}
		e.push_back(temp);
	}
	auto dfs = [&](auto self, int u)->void{
		for(int i = 0; i < e[u].size(); i ++){
			if(!vis[e[u][i]]) self(self, e[u][i]);
			ans[u] += ans[e[u][i]];
		}
		if(e[u].size() == 0) ans[u] = c[u];
		ans[u] = min(ans[u], c[u]);
		vis[u] = true;
	};
	for(int i = 1; i <= n; i ++ ){
		if(vis[i]) continue;
		dfs(dfs, i);
	}
	for(int i = 1; i <= n; i ++ ) cout << ans[i] << ' ';
	cout << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}