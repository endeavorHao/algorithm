#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 5010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    vector<array<int, 3>> dp(n + 1);
    dp[1][0] = a[1] * p;
    dp[1][1] = a[1] * (p + q);
    dp[1][2] = a[1] * (p + q + r);
    for(int i = 2; i <= n; i ++ ) {
        dp[i][0] = max(dp[i - 1][0], a[i] * p);
        dp[i][1] = max(dp[i - 1][1], dp[i][0] + a[i] * q);
        dp[i][2] = max(dp[i - 1][2], dp[i][1] + a[i] * r);
    }
    cout << dp[n][2] << endl; 
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