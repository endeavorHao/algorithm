#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, q, k;
int a[N], h[N], s[N], sum[N];
int maxv[N];
void solve(){
	cin >> n >> q >> k;
	for(int i = 1; i <= n; i ++ ) cin >> a[i], sum[i] = sum[i-1] + a[i];
	for(int i = 1; i <= n; i ++ ) cin >> h[i];
	h[0] = -INF;
	for(int i = 1; i <= n; i ++ ){
		maxv[i] = maxv[i-1];
		if(h[i] == h[i - 1]) s[i] = s[i-1] + 1;
		else{
			s[i] = 1;
			if(s[i-1] >= k) maxv[i] = i-1;
		}
	}
	while(q -- ){
		int ans = 0;
		int x;
		cin >> x;
		if(maxv[x] == 0) ans = sum[x] - sum[0];
		else if(x - maxv[x] >= k && h[maxv[x]] == h[x]) 
			ans = sum[x] - sum[x - k];
		else {
			ans = sum[x] - sum[maxv[x] - k];
		}
		cout << ans << endl;
	}
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