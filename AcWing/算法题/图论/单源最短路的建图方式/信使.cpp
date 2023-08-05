#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int g[N][N];
int n, m;
void solve(){
	cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i ++ ) g[i][i] = 0;
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    for(int k = 1; k <= n; k ++ ){
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i ++ ){
        if(g[1][i] == INF){
            ans = -1;
            break; 
        }
        ans = max(ans, g[1][i]);
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