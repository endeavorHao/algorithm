#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
int a[N];
bool check(int mid){
	int sum = 0;
	for(int i = 1; i <= n; i ++ ){
		if(a[i] >= mid) sum += (a[i] - mid) * 2;
		if(sum >= m) return true;
	}
	return false;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	int l = 0, r = 1e9;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	if(check(r)) cout << r << endl;
	else 
		cout << -1 << endl;
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