#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 210, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dp[N][N][N];
int w[N][N];
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ ) cin >> w[i][j];
    w[1][1] = 0, w[n][m] = 0;
    for(int k = 2; k <= n + m; k ++ ){
        for(int i1 = 1; i1 <= n; i1 ++ ){
            for(int i2 = 1; i2 <= n; i2 ++ ){
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m){
                    int t = 0;
                    t += w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];
                    auto &v = dp[k][i1][i2];
                    v = max(v, dp[k - 1][i1][i2] + t);
                    v = max(v, dp[k - 1][i1 - 1][i2] + t);
                    v = max(v, dp[k - 1][i1][i2 - 1] + t);
                    v = max(v, dp[k - 1][i1 - 1][i2 - 1] + t);
                }
            }
        }
    }
    cout << dp[n + m][n][n] << endl;
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