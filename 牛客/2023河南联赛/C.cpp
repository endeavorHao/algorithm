#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, c;
set<PII> S;
void solve(){
	cin >> n >> c;
    vector<int> a(n + 1);
    vector<int> dp(n + 1);
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int i = 1; i <= n; i ++ ){
		dp[i] = dp[i - 1];
		S.insert({a[i], i});
		if(i > c) S.erase({a[i - c], i - c});
		if(i >= c) dp[i] = max(dp[i], dp[i - c] + S.begin()->first);
	}
	cout << dp[n] << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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