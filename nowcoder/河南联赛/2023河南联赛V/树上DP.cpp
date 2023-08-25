#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void solve(){
    int n;
    cin >> n;
    vector<int> w(n + 1);
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i ++ ) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    for(int i = 1; i <= n; i ++ ) cin >> w[i];
    sort(w.begin() + 1, w.end(), [](int x, int y){
        return x < y;
    });
    vector<int> depth(n + 1);
    depth[1] = 1;
    auto dfs = [&](auto self, int u) -> void{
        for(int i = h[u]; ~i; i = ne[i]){
            int j = e[i];
            depth[j] = depth[u] + 1;
            self(self, j);
        }
    };
    dfs(dfs, 1);
    sort(depth.begin() + 1, depth.end());
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        ans += depth[i] * w[i];
    }
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