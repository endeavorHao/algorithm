#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
    cin >> m >> n;
    vector<int> w(n);
    for(auto &v: w) cin >> v;
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    
    int k = n / 2 + 2;
    vector<int> alls;
    alls.push_back(0);
    auto dfs1 = [&](auto self, int u, int s) -> void{
        if(u == k){
            alls.push_back(s);
            return;
        }

        self(self, u + 1, s);
        if(s + w[u] <= m) self(self, u + 1, s + w[u]);
    };
    dfs1(dfs1, 0, 0);
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    int ans = 0;
    auto dfs2 = [&](auto self, int u, int s) -> void{
        if(u == n){
            int t = upper_bound(alls.begin(), alls.end(), m - s) - alls.begin();
            ans = max(ans, s + alls[t - 1]);
            return;
        }

        self(self, u + 1, s);
        if(s + w[u] <= m) self(self, u + 1, s + w[u]);
    };
    dfs2(dfs2, k, 0);
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