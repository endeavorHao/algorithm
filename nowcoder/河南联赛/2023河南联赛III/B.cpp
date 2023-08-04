#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	map<int, int> mp;
	for(int i = 1; i <= n; i ++ ){
		mp[a[i]] ++;
	}
	int ans = -1;
	for(int i = 0; i <= m; i ++ ){
		if(mp[i]) continue;
		else{
			ans = i;
			break;
		}
	}
	if(ans == -1) cout << m << endl;
	else 
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