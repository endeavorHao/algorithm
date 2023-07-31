#include <bits/stdc++.h>
#define x first
#define y second
#define i64 long long
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	sort(a.begin(), a.end(), greater<int>());
	vector<int> sum(n);
	int ans = n;
	auto dfs = [&](auto self, int u, int k) -> void{
		if(k >= ans) return;
		if(u == n) {
			ans = k;
			return;
		} 

		for(int i = 0; i < k; i ++ ){
			if(sum[i] + a[u] <= m){
				sum[i] += a[u];
				self(self, u + 1, k);
				sum[i] -= a[u];
			}
		}
		
		sum[k] += a[u];
		self(self, u + 1, k + 1);
		sum[k] = 0;
	};

	dfs(dfs, 0, 0);
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