#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for(int i = 2; i <= n; i ++ ) cin >> a[i], g[a[i]].push_back(i);
    string s;
    cin >> s;
    s = " " + s;
    vector<PII> dp(n + 1);
    int ans = 0;
    auto dfs = [&](auto self, int u) ->void{
        if(s[u] == 'B') dp[u].x = 1, dp[u].y = 0;
        else dp[u].y = 1, dp[u].x = 0;
        for(auto v: g[u]){
            self(self, v);
            dp[u].x += dp[v].x;
            dp[u].y += dp[v].y;
        }
    };
    dfs(dfs, 1);
    for(int i = 1; i <= n; i ++ ) if(dp[i].x == dp[i].y) ans ++;
    cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}