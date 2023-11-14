#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(33, -1e18));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0; j <= min(i, 32ll); j ++ ){
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] / (1ll << j) - k);
            if(j >= 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] / (1ll << j));
        }
        if(i > 32) dp[i][32] = max(dp[i][32], dp[i - 1][32]);
    }
    int ans = -1e18;
    for(int i = 0; i <= 32; i ++ ) ans = max(ans, dp[n][i]);
    cout << ans << endl;
}
signed main() {
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