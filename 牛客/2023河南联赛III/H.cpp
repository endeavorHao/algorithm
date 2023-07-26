#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
int s[N];
int cnt[31];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	int maxv = 0;
	int ans = 0;
	bool ok = false;
	for(int i = 1; i <= n; i ++ ){
		ans += a[i];
		if(ans < a[i + 1] - 1) {
			ans++;
			ok = true;
			break;
		}
	}
	if(a[1] != 1) cout << 1 << endl;
	else{
		if(ok)
			cout << ans << endl;
		else cout << ans + 1 << endl;
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