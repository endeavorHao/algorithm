#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int dp[27][27];
void solve(){
	int n;
    cin >> n;
    memset(dp, -0x3f, sizeof dp);
    for(int i = 0; i < n; i ++ ) {
        string s;
        cin >> s;
        int len = s.size();
        int l = s[0] - 'a', r = s[len - 1] - 'a';
        for(int j = 0; j < 26; j ++ ) {
            dp[j][r] = max(dp[j][r], dp[j][l] + len);
        }
        dp[l][r] = max(dp[l][r], len);
    }
    int ans = 0;
    for(int i = 0; i < 26; i ++ ) {
        ans = max(ans, dp[i][i]);
    }
    cout << ans << endl;
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