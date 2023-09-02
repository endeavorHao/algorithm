#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(3 * (n + 1))), dp(n + 1, vector<int>(3 * (n + 1), -1e18));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= 2 * i - 1; j ++ )
            cin >> a[i][j];
    dp[1][1] = a[1][1];
    for(int i = 1; i < n; i ++ ){
        for(int j = 1; j <= 2 * i - 1; j ++ ){
            for(int l = 0; l < 3; l ++ ){
                dp[i + 1][j + l] = max(dp[i + 1][j + l], dp[i][j] + a[i + 1][j + l]);
            } 
        }
    }
    int ans = -1e18;
    for(int i = n - k; i <= n + k; i ++ ){
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
}
signed main() {
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