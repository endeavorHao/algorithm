#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], s[N];
void solve(){
	cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i], s[i] = s[i-1] + a[i];
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i ++ ){
        while(s[i] - s[j - 1] > m) j ++;
        if(s[i] - s[j - 1] == m) ans ++;
    }
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