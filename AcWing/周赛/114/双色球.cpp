#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<double>> dp(n + 1, vector<double>(m + 1));
    for(int i = 1; i <= n; i ++ ){
        for(int j = 0; j <= m; j ++ ){
            if(i == 0 && j == 0) continue;
            dp[i][j] = 1.0 * i / (i + j);
            double v = 1.0 * j / (i + j) * (j - 1) / (i + j - 1);
            if(i >= 1 && j >= 2)
                dp[i][j] += v * i / (i - 2 + j) * dp[i - 1][j - 2];
            if(j >= 3){
                dp[i][j] += v * (j - 2) / (i - 2 + j) * dp[i][j - 3];
            }
        }
    }
    printf("%.9lf\n", dp[n][m]);
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