#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> e(n);
    for(int i = 0; i < m; i ++ ){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a --, b --;
        e[a].push_back({b, x, y});
        e[b].push_back({a, -x, -y});
    }
    vector<bool> vis(n);
    vector<PII> ans(n, {(int)1e18, (int)1e18});
    ans[0] = {0, 0};
    vis[0] = true;
    auto dfs = [&](auto self, int u)-> void {
        vis[u] = true;
        for(auto [v, x, y]: e[u]){
            if(vis[v]) continue;
            PII t = make_pair(ans[u].x + x, ans[u].y + y);
            ans[v] = t;
            self(self, v);
        }
    };
    dfs(dfs, 0);
    for(int i = 0; i < n; i ++ ){
        if(!vis[i]) cout << "undecidable" << endl;
        else cout << ans[i].x << ' ' << ans[i].y << endl;
    }
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
