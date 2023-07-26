#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m, k, H;
int h[N];
void solve(){
	cin >> n >> m >> k >> H;
	for(int i = 1; i <= n; i ++ ) cin >> h[i];
	int ans = 0;
	for(int i = 1; i <= n; i ++ ){
		int t = abs(H - h[i]);
		if(t % k == 0 && t <= k * (m - 1) && t != 0) ans ++; 
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}