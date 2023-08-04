#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
void solve(){
	string s;
	cin >> s;
	for(auto &u: s){
		if(u >= 'b' && u <= 'z') u = u - 1;
		else if(u == 'a') u = 'z';
		else if(u >= 'A' && u <= 'Y') u = u + 1;
		else if(u == 'Z') u = 'A';
	}
	cout << s << endl;
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