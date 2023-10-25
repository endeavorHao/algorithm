#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 20010, INF = 0x3f3f3f3f, mod = 1e8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int f[N], g[N];
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];    
    for(int i = 0; i < n; i ++ ) cin >> b[i];
    vector<int> c(n);
    for(int i = 0; i < n; i ++ ) c[i] = a[i] - k * b[i];
    memset(f, -0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);
    f[0] = g[0] = 0;
    for(int i = 0; i < n; i ++ ) {
        if(c[i] >= 0) {
            for(int j = 2e4; j >= c[i]; j -- ) {
                f[j] = max(f[j], f[j - c[i]] + a[i]);
            }
        }else {
            for(int j = 2e4; j >= -c[i]; j -- ) {
                g[j] = max(g[j], g[j + c[i]] + a[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 2e4; i ++ ) {
        ans = max(ans, f[i] + g[i]);
    }
    if(ans)
        cout << ans << endl;
    else cout << -1 << endl;
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