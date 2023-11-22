/*
    dp[i]表示第i头放1的所有方案
	dp[i] = dp[0 ~ i - k - 1]
	即dp[i] = s[max(0, i - k - 1)]
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 25, INF = 0x3f3f3f3f, mod = 5000011;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){  
    int n, k;
    cin >> n >> k;
	vector<int> dp(n + 1), s(n + 1);
	dp[0] = s[0] = 1;
    for(int i = 1; i <= n; i ++ ) {
		dp[i] = s[max(0ll, i - k - 1)];
		s[i] = (s[i - 1] + dp[i]) % mod;
	}
	cout << s[n] << endl;
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