#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
int dx[8] = {1, 2, 1, 2, -1, -2, -1, -2}, dy[8] = {2, 1, -2, -1, 2, 1, -2, -1}; 
int bfs(){
	queue<PII> q;
	int sx = 0, sy = 0;
	for(int i = 1; i <= n; i ++ ) 
		for(int j = 1; j <= m; j ++ )
			if(g[i][j] == 'K') sx = i, sy = j;
	q.push({sx, sy});
	vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
	dist[sx][sy] = 0;
	while(q.size()){
		auto t = q.front();
		q.pop();
		
		if(g[t.x][t.y] == 'H') return dist[t.x][t.y];
		for(int i = 0; i < 8; i ++ ){
			int x = t.x + dx[i], y = t.y + dy[i];
			if(x <= 0 || x > n || y <= 0 || y > m) continue;
			if(g[x][y] == '*') continue;
			if(dist[x][y] != INF) continue;
			dist[x][y] = dist[t.x][t.y] + 1;
			q.push({x, y}); 
		}
	}
	return -1;
}
void solve(){
	cin >> m >> n;
	for(int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
	
	int t = bfs();
	cout << t << endl;
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