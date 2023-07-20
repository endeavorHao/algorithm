#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int g[N][N];
int f[N][N];
void solve(){
	cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) 
        for(int j = 1; j <= m; j ++ ) cin >> g[i][j];
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ ){
            f[i][j] = max(f[i-1][j], f[i][j-1]) + g[i][j];
        }  
    cout << f[n][m] << endl;
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}