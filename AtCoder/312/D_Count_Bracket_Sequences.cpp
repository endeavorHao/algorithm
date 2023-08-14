#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
void solve(){
	string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++ ){
        for(int j = (i + 1) / 2; j <= i; j ++ ){
            if(s[i] == '('){
                dp[i][j] += dp[i - 1][j - 1]; 
            }else if(s[i] == ')'){
                dp[i][j] += dp[i - 1][j];
            }else{
                dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];
            }
            dp[i][j] %= mod;
        }
    } 
    cout << dp[n][n / 2] << endl;
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