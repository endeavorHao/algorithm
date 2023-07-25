#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int g[N][N];
int dist[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void solve(){
	cin >> n;
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < n; j ++ ) cin >> g[i][j];
	
	vector<vector<PII>> path(n, vector<PII>(n, {-1, -1}));
	auto bfs = [&](int sx, int sy){
		queue<PII> q;
		q.push({sx, sy});
		path[sx][sy] = {0, 0};
		while(q.size()){
			auto t = q.front();
			q.pop();
			for(int i = 0; i < 4; i ++ ){
				int x = t.x + dx[i], y = t.y + dy[i];
				if(x < 0 || x >= n || y < 0 || y >= n) continue;
				if(g[x][y] == 1) continue;
				if(path[x][y].x != -1) continue;
				q.push({x, y});
				path[x][y] = t;
				if(t.x == 0 && t.y == 0) return;
			}
		}
	};

	bfs(n-1, n-1);
	PII end(0, 0);
	while(1){
		cout << end.x << ' ' << end.y << endl;
		if(end.x == n - 1 && end.y == n - 1) break;
		end = path[end.x][end.y];
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