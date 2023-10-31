#include <bits/stdc++.h>
#define x first
#define y second
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 810, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int g[N][N];
int dp[N][N][20][2];  // 表示走到(i, j)他们差值为p， 0表示最后一步是小u走的，1表示最后一步uim走的

void solve(){
	int n, m, k;
    cin >> n >> m >> k; 
    k ++;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            cin >> g[i][j];
            dp[i][j][g[i][j] % k][0] = 1;
        }
    }
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            for(int p = 0; p <= k; p ++ ) {
                dp[i][j][p][0] += dp[i - 1][j][((p - g[i][j]) % k + k) % k][1];
                dp[i][j][p][0] += dp[i][j - 1][((p - g[i][j]) % k + k) % k][1];
                dp[i][j][p][1] += dp[i][j - 1][(p + g[i][j]) % k][0];
                dp[i][j][p][1] += dp[i - 1][j][(p + g[i][j]) % k][0];
                dp[i][j][p][0] %= mod;
                dp[i][j][p][1] %= mod;
            }
        } 
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            ans = (ans + dp[i][j][0][1]) % mod;
        }
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