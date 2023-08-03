#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int mod = 0;
void solve(){
	int n;
	cin >> n;
	bool ok = false;
	if(n % 2 == 0 || n % 5 == 0 || n % 7 == 0 || n % 3 == 0){
		ok = true;
	}
	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
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