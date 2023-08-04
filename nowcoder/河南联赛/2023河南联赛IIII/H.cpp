#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++ ) cin >> a[i];
	vector<int> p(n);
	p = a;
	sort(a.begin(), a.end(), greater<int>());
	auto check = [&](int mid) -> bool{
		int sum = 0;
		for(int i = 0; i < n; i ++ ){
			if(i == mid) continue;
			if(!sum) sum = a[i]; 
			else sum = (sum + a[i]) / 2;
		}
		return a[mid] >= sum;
	};
	int l = 0, r = n - 1;
	while(l < r){
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	for(int i = 0; i < n; i ++ ){
		if(p[i] >= a[r]) cout << 1;
		else cout << 0;
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