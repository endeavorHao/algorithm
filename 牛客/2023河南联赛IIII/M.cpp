#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> g[N];
	while(m -- ){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	for(int i = 1; i <= n; i ++ ){
		int ans = 0;
		for(auto u: g[i]){
			ans += g[u].size();
		}
		cout << ans << ' ';
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