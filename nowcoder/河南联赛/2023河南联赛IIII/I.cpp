#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
	cin >> n;
	vector<PII> v(n);
	for(auto &[r, l]: v) cin >> l >> r;
	sort(v.begin(), v.end());

	int st = -INF, ed = -INF, res = 0;
	for(auto [r, l]: v){
		if(l <= st) continue;
		if(l <= ed) st = r, ed = -INF, res ++;
		else ed = r;
	}
	cout << res << endl;
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