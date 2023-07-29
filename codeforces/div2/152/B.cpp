#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	stable_sort(p.begin(), p.end(),
		[&](int i, int j){
			return (a[i] - 1) % k > (a[j] - 1) % k;
		});
	for(int i = 0; i < n; i ++ )
		cout << p[i] + 1 << " \n" [i == n - 1];
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