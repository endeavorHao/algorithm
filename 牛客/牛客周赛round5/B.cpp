#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> ans;
	k = n - k + 1;
	int x = k, y = 1;
	while(x <= n || y < k){
		if(x <= n)
			ans.emplace_back(x);
		if(y < k)
			ans.emplace_back(y);
		x ++, y ++;
	}
	for(auto u: ans) cout << u << ' ';
	cout << endl;
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