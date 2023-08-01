#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 2000120420010122;
typedef pair<int, int> PII;
void solve(){
	string s;
	while(cin >> s){
        // dp[1]表示c出现的次数,dp[2]表示cw出现的次数,dp[3]表示cwb出现的次数,dp[4]表示cwbc出现的次数
        vector<int> dp(5);
        for(auto u: s){
            u = tolower(u);
            if(u == 'c'){
                dp[1] = (dp[1] + 1) % mod;
                dp[4] = (dp[4] + dp[3]) % mod;
            }else if(u == 'w') dp[2] = (dp[1] + dp[2]) % mod;
            else if(u == 'b') dp[3] = (dp[2] + dp[3]) % mod;
        }
        cout << dp[4] << endl;
    }
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