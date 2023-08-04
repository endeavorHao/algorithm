#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], b[N];
void solve(){
	cin >> n >> m;
    for(int i = 0; i < n; i ++ ) cin >> a[i] >> b[i];
    int maxv = 0;
    for(int i = 0; i < n; i ++ ) maxv = max(maxv, a[i]);
    sort(b, b + n, greater<int>());
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        if(m <= 0) break;
        if(b[i] > maxv){
            m -= b[i];
            ans ++;
        }else break;
    }
    ans += (m + maxv - 1) / maxv; 
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
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}