#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

vector<vector<int>> adj(N);
int sz[N], dp[N], depth[N];
int n;
void dfs1(int u, int fa) {
    sz[u] = 1, depth[u] = depth[fa] + 1;
    for(auto v: adj[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}
void dfs2(int u, int fa) {
    for(auto v: adj[u]) {
        if(v == fa) continue;
        dp[v] = dp[u] - sz[v] + n - sz[v];
        dfs2(v, u);
    }
}
void solve(){
    cin >> n;
    for(int i = 0; i < n - 1; i ++ ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i ++ ) dp[1] += depth[i];
    dfs2(1, 0);
    int mapos = 0;
    for(int i = 1; i <= n; i ++ ) {
        if(dp[mapos] <= dp[i]) {
            mapos = i;
        }
    }
    cout << mapos << endl;
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