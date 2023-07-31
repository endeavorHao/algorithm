#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
    // dp[i][j]表示约翰先手有i个白球j个黑球赢得概率
	vector<vector<double>> dp(n + 1, vector<double>(m + 1));
	for(int i = 1; i <= n; i ++ )
		for(int j = 0; j <= m; j ++ ){
			double p1 = 0, p2 = 0, p3 = 0;
			p1 = i * 1.0 / (i + j);
			double p4 = j * 1.0 / (i + j) * (j - 1) / (i + j - 1);
			if(j >= 2)
				p2 = p4 * i / (i + j - 2) * dp[i-1][j-2];
			if(j >= 3)
				p3 = p4 * (j - 2) / (i + j - 2) * dp[i][j-3];
			dp[i][j] = p1 + p2 + p3;
		}
	printf("%.9lf\n", dp[n][m]);

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