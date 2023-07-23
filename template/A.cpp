#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, k;
int a[N];
void solve(){	
	cin >> n >> k;	
	string ans = "";
	if(3 * k > n) cout << "-1" << endl;
	else{
		for(int i = 0; i < k; i ++ ){
			ans += "you";
		}
		for(int i = 3 * k; i < n; i ++ ) 
			ans += "y";
		cout << ans << endl;
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