#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int n, ans;
int d1[N], d2[N], p1[N], up[N];
bool is_leaf[N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dfs_d(int u, int fa){
    d1[u] = d2[u] = -1e18;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        int d = dfs_d(j, u) + w[i];
        if(d >= d1[u]) d2[u] = d1[u], p1[u] = j, d1[u] = d;
        else if(d > d2[u]) d2[u] = d;
    }
    if(d1[u] == -1e18){
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }
    return d1[u];
}
void dfs_u(int u, int fa){
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        if(p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
        else up[j] = max(up[u], d1[u]) + w[i];

        dfs_u(j, u);
    }
}
void solve(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs_d(1, -1);
    dfs_u(1, -1);

    int res = max(d1[1], up[1]);
    for(int i = 2; i <= n; i ++ ){
        if(is_leaf[i]) res = min(res, up[i]);
        else res = min(res, max(up[i], d1[i]));
    }
    cout << res << endl;
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