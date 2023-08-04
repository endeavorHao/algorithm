#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int fact[N], infact[N];
int qmi(int a, int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}
int C(int n, int m){
	if(m > n) return 0;
	return fact[n] * infact[m] % mod * infact[n - m] % mod;
}
void solve(){
	fact[0] = infact[0] = 1;
	for(int i = 1; i < N; i ++ ){
		fact[i] = fact[i-1] * i % mod;
		infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod; 
	} 
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	map<int, int> mp;
	int pos1 = 0, pos2 = 0;
	for(int i = 1; i <= n; i ++ ){
		if(mp[a[i]]){
			pos1 = mp[a[i]], pos2 = i;
		}
		mp[a[i]] = i;
	}
	int ans = 0;
	ans = C(n, k);
	if(pos1){
		ans = (ans - C(n - (pos2 - pos1 + 1), k - 1) + mod) % mod;
	}
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
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}