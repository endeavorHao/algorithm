#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
int n, m;
int qmi(int a, int b, int p){
	int ans = 1 % p;
	a %= p;
	while(b){
		if(b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
void solve(){
	int n, x;
	cin >> n >> x;
	if(x == 1 || x == mod + 1){
		int t = qmi(2, n + 1, mod);
		cout << t << endl;
		return;
	}
	int t = qmi(2, n + 1, mod - 1);
	t = (qmi(x, t, mod) - 1 + mod) % mod;
	t = t * qmi(x - 1, mod - 2, mod);
	cout << t << endl;
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