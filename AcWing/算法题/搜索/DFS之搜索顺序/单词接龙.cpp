#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> s(n + 1);
	for(int i = 0; i < n; i ++ ) cin >> s[i];
	char c;
	cin >> c;
	vector<vector<int>> g(n + 1, vector<int>(n + 1, 0));
	vector<int> vis(n + 1, 0);
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < n; j ++ ){
			string a = s[i], b = s[j];
			for(int k = 1; k < min(a.size(), b.size()); k ++ ){
				// cout << i << "  " << j << " " << aj.substr(a.size() - k) << ' ' << b.substr(0, k) << endl;
				if(a.substr(a.size() - k) == b.substr(0, k)){
					g[i][j] = k;
					break;
				}
			}
		}
	int ans = 0;
	auto dfs = [&](auto self, string a, int last) -> void{
		ans = max(ans, (int)a.size());
		vis[last] ++;
		// cout << ans << ' ' << a << endl;
		for(int i = 0; i < n; i ++ ){
			if(vis[i] < 2 && g[last][i]){
				self(self, a + s[i].substr(g[last][i]), i);
			}
		}
		vis[last] --;
	};
	for(int i = 0; i < n; i ++ ){
		if(s[i][0] == c) 
			dfs(dfs, s[i], i);
	}
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