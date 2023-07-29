#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	vector<int> r(n);
	iota(r.begin(), r.end(), 0);
	vector<int> las(n + 1, 0), nex(n + 1, n - 1);
	for(int i = 0; i < n - 1; i ++ ){
		las[i + 1] = a[i] == 0 ? i : las[i];
	}
	for(int i = n - 1; i >= 0; i -- ){
		nex[i] = a[i] == 0 ? i : nex[i + 1];
	}
	for(int i = 0; i < n; i ++ ){
		if(a[i] == 1){
			r[las[i]] = max(r[las[i]], i);
			r[i] = max(r[i], nex[i]);
		}else if(a[i] == 2){
			r[las[i]] = max(r[las[i]], nex[i]);
		}
	}
	for(int i = 1; i < n; i ++ )
		r[i] = max(r[i], r[i - 1]);
	int ans = 0;
	for(int i = 0; i < n; i = r[i] + 1){
		ans ++;
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