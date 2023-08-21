#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int f[N][N];
int n, m;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int fa){
    for(int i = h[u]; ~i; i = ne[i]){
        if(e[i] == fa) continue;
        dfs(e[i], u);
        
        for(int j = m; j >= 0; j -- ){
            for(int k = 0; k < j; k ++ ){
                f[u][j] = max(f[u][j], f[u][j - k - 1] + w[i] + f[e[i]][k]);
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << f[1][m] << endl;
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