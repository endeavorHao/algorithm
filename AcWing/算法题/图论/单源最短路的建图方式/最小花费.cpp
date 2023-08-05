#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 3010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
double dist[N];
double g[N][N];
bool st[N];
int n, m, S, T;
void dijkstar(){
    dist[S] = 1;
    for(int i = 1; i <= n; i ++ ){
        int t = -1;
        for(int j = 1; j <= n; j ++ ){
            if(!st[j] && (t == -1 || dist[t] < dist[j]))
                t = j;
        }

        st[t] = true;
        for(int j = 1; j <= n; j ++ )
            dist[j] = max(dist[j], dist[t] * g[t][j]);
    }
}
void solve(){
	cin >> n >> m;
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }
    cin >> S >> T;
    dijkstar();
    printf("%.8lf\n", 100 / dist[T]);
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