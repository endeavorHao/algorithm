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
	int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i ++ ){
        int a, b;
        cin >> a >> b;
        a --, b --;
        g[a].push_back(b), g[b].push_back(a);
    }
    vector<int> depth(n, -1);
    auto dfs = [&](auto self, int u, int dist)->void{
        depth[u] = dist;
        for(auto v: g[u]){
            if(depth[v] == -1){
                self(self, v, dist + 1);
            }
        }
    };
    dfs(dfs, 0, 0);
    int root = 0;
    for(int i = 0; i < n; i ++ ) if(depth[i] > depth[root]) root = i;
    for(int i = 0; i < n; i ++ ) depth[i] = -1;
    dfs(dfs, root, 0);
    int x = 0;
    for(int i = 0; i < n; i ++ ){
        if(depth[i] == 1 || depth[i] == 3) x ++;
    }
    int y = (n - (x + 1)) / x;
    cout << x << " " << y << endl;
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