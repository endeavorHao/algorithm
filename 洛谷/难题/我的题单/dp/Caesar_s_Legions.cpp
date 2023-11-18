#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 110, INF = 0x3f3f3f3f, mod = 1e8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int dp[N][N][11][2];
void solve(){
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;
    dp[1][0][1][0] = dp[0][1][1][1] = 1;
    for(int i = 0; i <= n; i ++ ) {
        for(int j = 0; j <= m; j ++ ) {
            if(i > 0) {
                for(int k = 2; k <= k1; k ++ ) dp[i][j][k][0] = dp[i - 1][j][k - 1][0];
                for(int k = 1; k <= k2; k ++ ) dp[i][j][1][0] = (dp[i][j][1][0] + dp[i - 1][j][k][1]) % mod; 
            }
            if(j > 0) {
                for(int k = 2; k <= k2; k ++ ) dp[i][j][k][1] = dp[i][j - 1][k - 1][1];
                for(int k = 1; k <= k1; k ++ ) dp[i][j][1][1] = (dp[i][j][1][1] + dp[i][j - 1][k][0]) % mod;
            }
        } 
    }
    int ans = 0;
    for(int i = 1; i <= k1; i ++ ) ans = (ans + dp[n][m][i][0]) % mod;
    for(int i = 1; i <= k2; i ++ ) ans = (ans + dp[n][m][i][1]) % mod;
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