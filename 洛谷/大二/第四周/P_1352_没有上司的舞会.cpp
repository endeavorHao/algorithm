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

void solve(){
	int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<vector<int>> e(n);
    vector<int> vis(n);
    for(int i = 0; i < n - 1; i ++ ) {
        int a, b;
        cin >> a >> b;
        a --, b --;
        vis[a] = true;
        e[b].push_back(a);
    }
    int root = 0;
    for(int i = 0; i < n; i ++ ) if(!vis[i]) root = i;
    vector<vector<int>> dp(n, vector<int>(2));
    auto dfs = [&](auto self, int u)->void {
        dp[u][1] = a[u];
        dp[u][0] = 0;
        for(auto v: e[u]) {
            self(self, v);
            dp[u][0] += max(dp[v][1], dp[v][0]);
            dp[u][1] += dp[v][0];
        }
    };
    dfs(dfs, root); 
    cout << max(dp[root][1], dp[root][0]) << endl;
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