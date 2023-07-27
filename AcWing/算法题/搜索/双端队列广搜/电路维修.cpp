#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];
int bfs(){
	deque<PII> q;
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	q.push_back({0, 0});
	dist[0][0] = 0;
	char cs[] = "\\/\\/";
	int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
	int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};

	while(q.size()){
		auto t = q.front();
		q.pop_front();

 		if(st[t.x][t.y]) continue;
		st[t.x][t.y] = true;

		for(int i = 0; i < 4; i ++ ){
			int a = t.x + dx[i], b = t.y + dy[i];
			if(a < 0 || a > n || b < 0 || b > m) continue;

			int ca = t.x + ix[i], cb = t.y + iy[i];
			int d = dist[t.x][t.y] + (cs[i] != g[ca][cb]);

			if(d < dist[a][b]){
				dist[a][b] = d;
				if(g[ca][cb] != cs[i]) q.push_back({a, b});
				else q.push_front({a, b});
			}
		}
	}
	return dist[n][m];
}
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i ++ ) cin >> g[i];
	int t = bfs();
	
	if(t == INF) cout << "NO SOLUTION" << endl;
	else cout << t << endl;
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