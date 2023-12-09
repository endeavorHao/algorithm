#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 210, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int f[N][N], g[N][N];
int a[N], s[N];
void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], a[i + n] = a[i];
    for(int i = 1; i <= 2 * n; i ++ ) s[i] = s[i - 1] + a[i];
    for(int len = 2; len <= 2 * n; len ++ ) {
        for(int l = 1; l + len - 1 <= 2 * n; l ++ ) {
            int r = l + len - 1;
            f[l][r] = -INF, g[l][r] = INF;
            for(int k = l; k < r; k ++ ) {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            } 
        }
    }
    int minv = INF, maxv = -INF;
    for(int i = 1; i <= n; i ++ ) {
        minv = min(minv, g[i][i + n - 1]);
        maxv = max(maxv, f[i][i + n - 1]);
    }    
    cout << minv << endl << maxv << endl;
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