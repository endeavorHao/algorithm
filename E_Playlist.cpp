#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
int qmi(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve(){
	int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<vector<int>> dp(1010, vector<int>(1010));
    dp[0][0] = 1;
    for(int i = 0; i <= 1000; i ++ ) {
        for(int j = 0; j <= 1000; j ++ ) {
            for(int k = 0; k < n; k ++ ) {
                dp[i + a[k]][j + 1] += dp[i][j];
            }
        }
    }
    int ans = 0;
    for(int i = x - a[0]; i <= x; i ++ ) {
        int infact = 1;
        for(int j = 1; j <= 1000; j ++ ) {
            infact = infact * qmi(n, mod - 2) % mod;
            ans = (ans + qmi(dp[i][j], infact)) % mod;
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