#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void solve(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
	int ans = 0;
	auto dfs = [&](auto self, int x, int y, int cnt) -> void{
		if(cnt == n * m){
			ans ++;
			return;
		}
		vis[x][y] = true;
		for(int i = 0; i < 8; i ++ ){
			int a = x + dx[i], b = y + dy[i];
			if(a < 0 || a >= n || b < 0 || b >= m) continue;
			if(vis[a][b]) continue;
			self(self, a, b, cnt + 1);
		}
		vis[x][y] = false;
	};
	
	dfs(dfs, x, y, 1);
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}