#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 210, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int d[N][N];
int g[N][N];
int path[N];
int pos[N][N], cnt;
int n, m;
void get_path(int i, int j){
    if (pos[i][j] == 0) return;

    int k = pos[i][j];
    get_path(i, k);
    path[cnt ++ ] = k;
    get_path(k, j);
}
void solve(){
	cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i ++ ) g[i][i] = 0;
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    memcpy(d, g, sizeof d);
    int ans = INF;
    for(int k = 1; k <= n; k ++ ){
        for(int i = 1; i < k; i ++ )
            for(int j = i + 1; j < k; j ++ ){
                if(ans > (long long)d[i][j] + g[j][k] + g[k][i]){
                    ans = d[i][j] + g[j][k] + g[k][i];
                    cnt = 0;
                    path[cnt ++] = k;
                    path[cnt ++] = i;
                    get_path(i, j);
                    path[cnt ++] = j;
                }
            }
        
        for(int i = 1; i <= n; i ++ )
            for(int j = 1; j <= n; j ++ )
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k; 
                }
    }
    if(ans == INF) cout << "No solution." << endl;
    else {
        for(int i = 0; i < cnt; i ++ ) cout << path[i] << ' ';
        cout << endl;
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