#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int w[N][N];
int f[N * 2][N][N];
void solve(){
	cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) 
        for(int j = 1; j <= m; j ++ ) cin >> w[i][j];
    for(int k = 2; k <= n + m; k ++ )
        for(int i1 = 1; i1 <= n; i1 ++ )
            for(int i2 = 1; i2 <= n; i2 ++ ){
                int j1 = k - i1, j2 = k - i2;
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m){
                    int t = w[i1][j1];
                    if(i1 != i2) t += w[i2][j2];
                    auto &v = f[k][i1][i2];
                    v = max(v, f[k-1][i1][i2] + t);
                    v = max(v, f[k-1][i1-1][i2-1] + t);
                    v = max(v, f[k-1][i1-1][i2] + t);
                    v = max(v, f[k-1][i1][i2-1] + t);
                }
            }
    cout << f[n + m][n][n] << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
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