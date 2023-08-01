#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1001010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int fact[N], infact[N];
int s[N];
int qmi(int a, int b, int p){
	int ans = 1 % p;
	while(b){
		if(b & 1) ans = ans * a % p;	
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}
int C(int n, int m){
	if(m > n) return 0;
	return fact[n] * infact[n - m] % mod * infact[m] % mod;
}
void solve(){
	fact[0] = infact[0] = 1;
	for(int i = 1; i < N; i ++ ){
		fact[i] = fact[i - 1] * i % mod;
		infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
	}  
	int n;
	cin >> n;
	n += 2;
	for(int i = 2; i < n; i ++ ) cin >> s[i];
	s[1] = 1000, s[n] = 1;
	int ans = 1;
	for(int l = 1, r; l <= n; l = r + 1){
		r = l;
		if(s[l]) continue;
		while(s[r + 1] == 0){
			r ++;
		}
		ans = ans * C(s[l - 1] - s[r + 1] + r - l + 1, r - l + 1) % mod;
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
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}