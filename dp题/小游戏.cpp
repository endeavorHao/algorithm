#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f, mod = 0;
typedef pair<int, int> PII;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	sort(a.begin(), a.end());
    // dp表示以i结尾的最大值
    // 状态转移dp[i] = max(dp[i-1], dp[i-2] + s[i])
	vector<int> dp(200001, 0);
	vector<int> s(200001);
	for(int i = 0; i < n; i ++ ){
		s[a[i]] += a[i];
	}
	dp[0] = 0;
	dp[1] = s[1];
	for(int i = 2; i <= 200000; i ++ ){
		dp[i] = max(dp[i-1], dp[i - 2] + s[i]);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;

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