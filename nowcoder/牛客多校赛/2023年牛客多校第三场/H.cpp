#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, m;
bool is_prime(int x){
	if(x == 1) return false;
	for(int i = 2; i <= x / i; i ++ ){
		if(x % i == 0) return false;
	}
	return true;
}
void solve(){
	cin >> n;
	int s = 0;
	for(int i = 1, a; i <= n; i ++ ) cin >> a, s += a;
	if(n == 1){
		if(is_prime(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}else if(n == 2){
		if(s & 1){
			if((is_prime(s - 2))) cout << "YES" << endl;
			else cout << "NO" << endl;
		}else {
			if(s >= 2 * n) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}else{
		if(s >= 2 * n) cout << "YES" << endl;
		else cout << "NO" << endl;
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