#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	string s;
	cin >> s;
	s = ' ' + s;
	vector<int> dp(s.size() + 2), dp6(s.size() + 2);
	for(int i = 1; i <= s.size(); i ++ ){
		dp6[i] = dp6[i-1];
		if(s[i] == '1'){
			// 以dp[i-1]的子串接上s[i]， s[i]为单独的字串
			dp[i] = (dp[i-1] + (dp[i-1] + 1) - dp6[i - 1] + mod) % mod;
		}else{
			if(s[i] == '6'){
				dp6[i] = (dp6[i - 1] + dp[i - 1] + 1) % mod;
			}
			dp[i] = (dp[i-1] * 2 + 1) % mod;
		}
	}
	cout << dp[s.size() - 1] << endl;
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