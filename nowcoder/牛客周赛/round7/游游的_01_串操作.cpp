#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
char g[N][N];
void solve(){
	string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    vector<array<int, 2>> dp(n + 1);
    for(int i = 1; i <= n; i ++ ){
        int c = s[i] - '0';
        dp[i][c] = dp[i - 1][!c];
        dp[i][!c] = dp[i - 1][c] + i;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
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