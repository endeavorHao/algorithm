#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void solve(){
	int n, m;
	while(cin >> m >> n, n || m){
		vector<vector<char>> g(n, vector<char>(m));
		vector<vector<bool>> st(n, vector<bool>(m, false));
		for(int i = 0; i < n; i ++ )
			for(int j = 0; j < m; j ++ ) cin >> g[i][j];
 		int x, y;
		for(int i = 0; i < n; i ++ )
			for(int j = 0; j < m; j ++ ) 
				if(g[i][j] == '@') x = i, y = j;
		int ans = 1;
		auto dfs = [&](auto self, int x, int y) -> void{
			for(int i = 0; i < 4; i ++ ){
				int a = x + dx[i], b = y + dy[i];
				if(a < 0 || a >= n || b < 0 || b >= m) continue;
				if(g[a][b] == '#') continue;
				if(st[a][b]) continue;
				st[a][b] = true;
				ans ++;
				self(self, a, b);
			}
		};
		st[x][y] = true;
		dfs(dfs, x, y);
		cout << ans << endl;
	}
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