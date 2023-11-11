#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
char g[N][N];
int h[N][N], l[N][N], r[N][N];
void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            if(g[i][j] == 'F') {
                h[i][j] = h[i - 1][j] + 1;
                l[i][j] = l[i][j - 1] + 1;
            }
        }
        for(int j = m; j >= 1; j --){
            if(g[i][j] == 'F') r[i][j] = r[i][j + 1] + 1;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            if(g[i][j] == 'F'){
                if(g[i - 1][j] == 'F'){
                    l[i][j] = min(l[i][j], l[i - 1][j]);
                    r[i][j] = min(r[i][j], r[i - 1][j]);
                }
                ans = max(ans, (r[i][j] + l[i][j] - 1) * h[i][j]);
            }
        }
    }
    cout << ans * 3 << endl;
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