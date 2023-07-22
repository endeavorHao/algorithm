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
	int64_t sum = 0;
	for(int i = 1; i <= n; i ++ ){
		sum += (int64_t)(2 * mid + a[i]) * (2 * mid + a[i]);
		if(sum >= m) return true;
	}
	return false;
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	int l = 0, r = 1e9;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(check(1)) cout << " 1" << endl;  
	cout << r << endl;
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