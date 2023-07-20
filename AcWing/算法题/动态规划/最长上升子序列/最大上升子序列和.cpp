#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 10010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int f[N], g[N];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    for(int i = 1; i <= n; i ++ ){
        f[i] = a[i];
        for(int j = 1; j < i; j ++ ){
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + a[i]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++ ) ans = max(ans, f[i]);
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