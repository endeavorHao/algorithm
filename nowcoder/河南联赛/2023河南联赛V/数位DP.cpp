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
    s = " " + s;
    vector<array<int, 3>> dp(200010);
    vector<int> last(10);
    dp[0][0] = 1;
    last[0] = 1;
    for(int i = 1; i < s.size(); i ++ ){
        int x = s[i] - '0';
        int l = last[x];

        for(int j = 0; j < 3; j ++ )
            dp[i][(j + x) % 3] = dp[i - 1][j];
        for(int j = 0; j < 3; j ++ ){
            dp[i][j] = dp[i][j] + dp[i - 1][j];
        }
        if(l){
            for(int j = 0; j < 3; j ++ )
                dp[i][(j + x) % 3] -= dp[l - 1][j];
        }
        for(int j = 0; j < 3; j ++ )
            dp[i][j] = (dp[i][j] % mod + mod) % mod;
        last[x] = i;
    }
    cout << (dp[s.size() - 1][1] + dp[s.size() - 1][2]) % mod << endl;
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