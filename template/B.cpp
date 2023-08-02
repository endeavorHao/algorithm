#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	int ans = 0;
	auto dfs = [&](auto self, int u, int s) -> void{
		if(u == n){
            int cnt = 0;
            for(int i = 0; i < 63; i ++ ){
                if(s >> i & 1) cnt ++;
            }
            if(cnt == k) ans ++;
            return;
        }
 		self(self, u + 1, s & a[u]);
		self(self, u + 1, s);
	};
	dfs(dfs, 0, (1ll << 63) - 1);
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