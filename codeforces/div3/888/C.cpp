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
	int x = a[1], y = a[n];
	map<int, int> mp;
	for(int i = 1; i <= n; i ++ ){
		if(mp[x] && mp[x] % m == 0){
			if(mp[y] && mp[y] % m == 0){
				cout << "YES" << endl;
				return ;
			}
			if(a[i] == y) mp[y] ++;
		}
		else if(a[i] == x) mp[x] ++;
	}
	if(mp[y] && mp[y] % m == 0){
			cout << "YES" << endl;
			return ;
	}
	cout << "NO" << endl;
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