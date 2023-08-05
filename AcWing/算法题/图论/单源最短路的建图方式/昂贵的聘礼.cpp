#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int g[N][N];
int level[N];
int n, m;
int dist[N];
bool st[N];
int dijkstra(int l, int r){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[0] = 0;
    for(int i = 1; i <= n + 1; i ++ ){
        int t = -1;
        for(int j = 0; j <= n; j ++ ){
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
        for(int j = 1; j <= n; j ++ )
            if(level[j] >= l && level[j] <= r)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    return dist[1];
}
void solve(){
	cin >> m >> n;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i <= n; i ++ ) g[i][i] = 0;
    for(int i = 1; i <= n; i ++ ){
        int price, cnt;
        cin >> price >> level[i] >> cnt;
        g[0][i] = price;
        while(cnt -- ){
            int b, cost;
            cin >> b >> cost;
            g[b][i] = cost;
        }
    }
    int ans = INF;
    for(int i = level[1] - m; i <= level[1]; i ++ ) ans = min(ans, dijkstra(i, i + m));
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