#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 210, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dp[N][N][N];
void solve(){
	int n, m;
    cin >> n >> m;
    vector<PII> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i].x >> a[i].y;
    
    memset(dp, -0x3f, sizeof dp);
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ ) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
            
    
    for(int len = 2; len <= n; len ++){
        for(int k = 2; k <= len; k ++ )
            for(int l = 1; l + len - 1 <= n; l ++ ){
                int r = l + len - 1;
                int val = abs(a[r].x - a[l].x) + abs(a[r].y - a[l].y);
                dp[l][r][k] = max(dp[l][r][k], dp[l+1][r-1][k-2] + val);
                dp[l][r][k] = max({dp[l][r][k], dp[l+1][r][k], dp[l][r-1][k]});
            }
    }
    cout << dp[1][n][m] << endl;
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