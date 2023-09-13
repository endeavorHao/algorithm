#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m, x, y;
    cin >> n >> m >> x >> y;
    int dx[9] = {-1, -2, -2, -1, 1, 2, 2, 1, 0};
    int dy[9] = {-2, -1, 1, 2, 2, 1, -1, -2, 0};
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    for(int i = 0; i < 9; i ++ ){
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a > n || b < 0 || b > m) continue;
        vis[a][b] = true;
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for(int i = 0; i <= n; i ++ ){
        for(int j = 0; j <= m; j ++ ){
            if(i && !vis[i - 1][j]) dp[i][j] = dp[i - 1][j];
            if(j && !vis[i][j - 1]) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[n][m] << endl;
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