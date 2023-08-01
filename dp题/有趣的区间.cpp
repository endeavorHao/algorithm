#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
    // dp[i]表示以i结尾有多好个有趣的区间
	vector<int> dp(n + 1, 0);
	int las = 0;
	for(int i = 1; i <= n; i ++ ){
		if(a[i] & 1){
			dp[i] = dp[i-1] + i;
			las = i;
		}else{
			dp[i] = dp[i - 1] + las;
		}
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