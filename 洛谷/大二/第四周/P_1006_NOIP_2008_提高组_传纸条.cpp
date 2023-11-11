#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 110, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;

int dp[N * 2][N][N];
int g[N][N];
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) cin >> g[i][j];
    }

    for(int k = 2; k <= n + m; k ++ ) {
        for(int i1 = 1; i1 <= n; i1 ++ ) {
            for(int i2 = 1; i2 <= n; i2 ++ ) {
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m) {
                    auto &v = dp[k][i1][i2];
                    int c = g[i1][j1];
                    if(i1 != i2) c += g[i2][j2];
                    v = max(v, dp[k - 1][i1 - 1][i2] + c);
                    v = max(v, dp[k - 1][i1 - 1][i2 - 1] + c);
                    v = max(v, dp[k - 1][i1][i2 - 1] + c);
                    v = max(v, dp[k - 1][i1][i2] + c);
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