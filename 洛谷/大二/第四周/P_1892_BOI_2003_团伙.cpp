#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 100010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int p[N], sz[N];
int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void merge(int u, int v) {
    if(find(v) != find(u)) {
        sz[find(v)] += sz[find(u)];
        p[find(u)] = find(v);
    }
}
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i ++ ) {
        char op;
        int u, v;
        cin >> op >> u >> v;
        if(op == 'F') {
            merge(u, v);
        }else {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    } 
    for(int i = 1; i <= n; i ++ ){
        for(auto j: adj[i]) {
            for(auto v: adj[j]) {
                if(i != v) merge(i, v);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) {
        if(find(i) == i) ans ++;
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