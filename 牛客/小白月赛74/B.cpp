#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int mod = 0;
void solve(){
	int n;
	cin >> n;
	int x = 1;
	while(n){
		if(n >= x + x + 1){
			cout << x << ' ';
			n -= x;
			x ++;
		}else{
			cout << n;
			break;
		}
	}
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}