#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int mod = 20010905;
void solve(){
	string target = "iloveyou";
	string s;
	cin >> s;
	vector<int> dp(9, 0);
	dp[0] = 1;
	for(int i = 0; i < s.size(); i ++ ){
		for(int j = 0; j < target.size(); j ++ ){
			if(s[i] == target[j] || s[i] == target[j] - 32){
				dp[j + 1] = (dp[j + 1] + dp[j]) % mod;
			}
		}
	}
	cout << dp[8] << endl;
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