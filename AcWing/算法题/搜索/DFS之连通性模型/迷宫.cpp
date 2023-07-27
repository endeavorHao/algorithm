#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
char g[N][N];
int s1, t1, s2, t2;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
bool st[N][N];
bool dfs(int x, int y){
	if(g[x][y] == '#') return false;
	if(x == s2 && y == t2) return true;

	for(int i = 0; i < 4; i ++ ){
		int a = x + dx[i], b = y + dy[i];
		if(a < 0 || a >= n || b < 0 || b >= n) continue;
		if(g[a][b] == '#') continue;
		if(st[a][b]) continue;
		st[a][b] = true;
		if(dfs(a, b)) return true;
	}
	return false;
}
void solve(){
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> g[i];
	cin >> s1 >> t1 >> s2 >> t2;
	memset(st, 0, sizeof st);
	st[s1][t1] = true;
	if(dfs(s1, t1)) cout << "YES" << endl;
	else cout << "NO" << endl;
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