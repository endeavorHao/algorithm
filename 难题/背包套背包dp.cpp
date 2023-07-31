#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 210, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<PII> w(n + 1);
	for(int i = 1; i <= n; i ++ ){
		cin >> w[i].x >> w[i].y;
	}
	vector<int> sz(m);
	for(int i = 1; i <= m; i ++){
		cin >> sz[i];
	}
	vector<vector<int>> dp(n, vector<int>(210));
	for(int i = 1; i <= n; i ++ ){
		for(int j = max(1ll, m - n); j <= m; j ++ ){
			for(int k = sz[j]; k >= w[i].x; k -- ){
				dp[j][k] = max(dp[j][k], dp[j][k - w[i].x] + w[i].y);
			}
		}
		for(int j = 1; j < m; j ++ )
			for(int k = 0; k <= sz[j]; k ++ )
				dp[j + 1][0] = max(dp[j + 1][0], dp[j][k]);
	}
		
	cout << *max_element(dp[m].begin(), dp[m].end()) << endl;
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