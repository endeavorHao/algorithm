#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(4 * n));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= 4 * n; j ++ )
			for(int k = 1; k <= 4; k ++ )
				if(j >= k) dp[i][j] += dp[i-1][j - k];
	int ans = 0;
	for(int j = 3 * n; j <= 4 * n; j ++ )
		ans += dp[n][j];
	cout << ans << '/' << pow(n, 4) << endl;
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