#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 3010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int dp[N][N], f[N][N];
void solve(){
	string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s, t = " " + t;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                f[i][j] = 2;
            }else if(dp[i][j - 1] > dp[i - 1][j]) {
                dp[i][j] = dp[i][j - 1], f[i][j] = 1;
            }else {
                dp[i][j] = dp[i - 1][j], f[i][j] = 3;
            }
        }
    }
    // cout << dp[n][m] << endl;
    string ans;
    int x = n, y = m;
    while(x >= 1&& y >= 1) {
        if(f[x][y] == 2) {
            ans += s[x];
            x -- , y --;
        }else if(f[x][y] == 3) {
            x --;
        }else y --;
    }
    reverse(all(ans));
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