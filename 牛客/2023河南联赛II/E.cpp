#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N], x[N];
int b[N];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> x[i];
	for(int i = 1; i <= n; i ++ ){
		b[max(1ll, i - x[i])] ++, b[i] --;
		b[i + 1] ++, b[min(n + 1, i + x[i] + 1)] --;
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++ ){
		b[i] += b[i-1];
		if(b[i]) ans ++;
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