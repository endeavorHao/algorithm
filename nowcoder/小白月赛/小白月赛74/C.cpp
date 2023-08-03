#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int mod = 0;
void solve(){
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < m; j ++ ){
			int x;
			cin >> x;
			mp[x] ++;
		}
	cout << mp.size() << endl;
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