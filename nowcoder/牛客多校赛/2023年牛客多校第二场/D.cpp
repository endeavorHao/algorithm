#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, k;
int g[N][N];
bool st[N];
void solve(){
	cin >> n >> m >> k;
	vector<vector<PII>> g(n, vector<PII>(m));
	memset(st, 0, sizeof st);
	for(int i = 0; i < n; i ++ ){
		for(int j = 0; j < m; j ++ ) {
			cin >> g[i][j].x;
			g[i][j].y = j + 1;
		}
		sort(g[i].begin(), g[i].end());
	}
	vector<int> ans;
	for(int i = k - 1; i >= 0; i -- ){
		int t = -1;
		for(int j = 0; j < m; j ++ ){
			if(!st[g[i%n][j].y] && (t == -1 || g[i%n][j].x > g[i%n][t].x)) t = j;
		}
		st[g[i%n][t].y] = true;
		ans.push_back(g[i%n][t].y);
	}
	sort(ans.begin(), ans.end());
	for(auto u: ans) cout << u << ' ';
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