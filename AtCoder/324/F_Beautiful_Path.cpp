#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 500010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<array<int, 4>> adj(m);
    for(int i = 0; i < m; i ++ ) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a --, b -- ;
        adj[i] = {a, b, c, d};
    }
    sort(all(adj));
    auto check = [&](double mid) ->bool{
        vector<double> dp(n, -1e18);
        dp[0] = 0;
        for(auto [u, v, b, c]: adj) {
            dp[v] = (dp[v] > dp[u] + b - c * mid) ? dp[v] : dp[u] + b - c * mid;
        }
        return dp[n - 1] >= 0;
    };
    double l = 0, r = 1e9;
    for(int i = 0; i < 100; i ++ ) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << r << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
    cout << fixed << setprecision(16);
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}