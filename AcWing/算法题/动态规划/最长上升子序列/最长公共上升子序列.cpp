#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 3010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], b[N];
int f[N][N];
void solve(){
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ) cin >> b[i];
    for(int i = 1; i <= n; i ++ ){
        int maxv = 1;
        for(int j = 1; j <= n; j ++ ){
            f[i][j] = f[i-1][j];
            if(a[i] == b[j])
                f[i][j] = max(f[i][j], maxv);
            if(a[i] > b[j]) maxv = max(maxv, f[i-1][j] + 1);
        }
    }

    for(int i = 1; i <= n; i ++ ) ans = max(ans, f[n][i]);
    cout << ans << endl;
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
// 	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}