#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef pair<int, int> PII;
void solve(){
	vector<int> cnt(10);
	for(int i = 1; i <= 9; i ++ ) cin >> cnt[i];

	vector<array<int, 3>> dp(10);
    // dp[i][0] 表示前i个数能凑成末3为0的个数
    // dp[i][1] 表示前i个数能凑成末3为1的个数
    // dp[i][2] 表示前i个数能凑成末3为2的个数
    // 状态转移方程
    /*
    dp[i][0] = (dp[i-1][0] + dp[i-1][0] * sum3 + dp[i-1][1] * sum2 + dp[i-1][2] * sum1) % mod;
	dp[i][1] = (dp[i-1][1] + dp[i-1][1] * sum3 + dp[i-1][2] * sum2 + dp[i-1][0] * sum1) % mod;
	dp[i][2] = (dp[i-1][2] + dp[i-1][2] * sum3 + dp[i-1][0] * sum2 + dp[i-1][1] * sum1) % mod;
    */

	// init
	for(int i = 0; i <= 9; i ++ ) dp[i][0] = 1;

	for(int i = 1; i <= 9; i ++ ){
		int sum1 = 0, sum2 = 0, sum3 = 0;
		// sum1 表示cnt[i]能凑出多少个末1结尾的数
		// sum2 表示cnt[i]能凑出多少个末2结尾的数
		// sum3 表示cnt[i]能凑出多少个末0结尾的数
		int sum = i * cnt[i];
		if(i % 3 == 1){
			sum1 = (cnt[i] + 2) / 3;
			sum2 = (cnt[i] + 1) / 3;
			sum3 = cnt[i] / 3;
		}else if(i % 3 == 2){
			sum1 = (cnt[i] + 1) / 3;
			sum2 = (cnt[i] + 2) / 3;
			sum3 = cnt[i] / 3;
		}else{
			sum1 = 0;
			sum2 = 0;
			sum3 = cnt[i];
		}
		dp[i][0] = (dp[i-1][0] + dp[i-1][0] * sum3 + dp[i-1][1] * sum2 + dp[i-1][2] * sum1) % mod;
		dp[i][1] = (dp[i-1][1] + dp[i-1][1] * sum3 + dp[i-1][2] * sum2 + dp[i-1][0] * sum1) % mod;
		dp[i][2] = (dp[i-1][2] + dp[i-1][2] * sum3 + dp[i-1][0] * sum2 + dp[i-1][1] * sum1) % mod;
	}
	cout << dp[9][0] << endl;
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