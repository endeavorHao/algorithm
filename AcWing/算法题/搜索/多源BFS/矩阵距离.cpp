#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
int dist[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> g[i] + 1;

	auto bfs = [&]() -> void{
		memset(dist, -1, sizeof dist);
		queue<PII> q;
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= m; j ++ ){
				if(g[i][j] == '1'){
					dist[i][j] = 0;
					q.push({i, j});
				}
			}
		while(q.size()){
			auto t = q.front();
			q.pop();
			for(int i = 0; i < 4; i ++ ){
				int x = t.x + dx[i], y = t.y + dy[i];
				if(x <= 0 || x > n || y <= 0 || y > m) continue;
				if(dist[x][y] != -1) continue;
				dist[x][y] = dist[t.x][t.y] + 1;	
				q.push({x, y});
			}
		}
	};
	bfs();
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= m; j ++ ) cout << dist[i][j] << ' ';
		cout << endl; 
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