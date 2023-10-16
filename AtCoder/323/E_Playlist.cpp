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
    int inv = qmi(n, mod - 2);
    vector<int> dp(10010);
    dp[0] = 1;
    for(int i = 1; i <= x; i ++ ) {
        for(int j = 0; j < n; j ++ ) {
            if(i - a[j] >= 0) {
                dp[i] = (dp[i] + dp[i - a[j]] * inv) % mod;
            }
        }
    }
    int ans = 0;
    for(int i = max(0ll, x - a[0] + 1); i <= x; i ++ ) ans = (ans + dp[i]) % mod;
    cout << ans * inv % mod << endl;
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