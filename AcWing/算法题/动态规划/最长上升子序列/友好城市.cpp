#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 10010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
PII a[N];
int f[N], g[N];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i ++ ) cin >> a[i].x >> a[i].y;
    sort(a, a + n);
    for(int i = 0; i < n; i ++ ){
        f[i] = 1;
        for(int j = 0; j < i; j ++ ){
            if(a[i].y > a[j].y) f[i] = max(f[i], f[j] + 1);
        }
    } 
    int ans = 0;
    for(int i = 0; i < n; i ++ ) ans = max(ans, f[i]); 
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