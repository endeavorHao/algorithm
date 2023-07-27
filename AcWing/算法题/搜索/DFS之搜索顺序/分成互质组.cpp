#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> vis(n + 1, false);
	vector<vector<int>> group(n + 1, vector<int>(n + 1));
	for(auto &u: a) cin >> u;
	auto check = [&](vector<int> group, int gc, int i) -> bool{
		for(int j = 0; j < gc; j ++ ){
			if(gcd(a[group[j]], a[i]) > 1) return false;
		}
		return true;
	};
	int ans = n;
	auto dfs = [&](auto dfs, int g, int gc, int gm, int start) -> void{
		if(g >= ans) return;
		if(gm == n) ans = g;
		bool flag = false;
		for(int i = start; i < n; i ++ ){
			if(!vis[i] && check(group[g], gc, i)){
				flag = true;
				vis[i] = true;
				group[g][gc] = i;
				dfs(dfs, g, gc + 1, gm + 1, i + 1);
				vis[i] = false;
				group[g][gc] = 0;
			}
		}
		if(!flag) dfs(dfs, g + 1, 0, gm, 0);
	};
	dfs(dfs, 1, 0, 0, 0);
	cout << ans << endl;
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
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}