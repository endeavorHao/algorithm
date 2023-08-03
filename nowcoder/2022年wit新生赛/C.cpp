#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 998244353;
typedef pair<int, int> PII;
int n, m, k;
int ans;
int a[N];
int fact[N], infact[N];
int C(int a, int b)
{
	if(a < b) return 0;
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}
int qmi(int a, int b){
	int ans = 1 % mod;
	while(b){
		if(b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans;
}

void solve(){
	cin >> n >> m >> k;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
	fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i ++) {
		fact[i] = fact[i - 1] * i % mod;
		infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;  
    }
    sort(a, a + n);
    vector<int> v(N + 1, 0);
	vector<int> sum(N + 1, 0);
    for(int i = 0; i < n; i ++ ){
		v[a[i]] ++; 
    }
	for(int i = 1; i <= 2e5; i ++ ) sum[i] = sum[i - 1] + v[i];
	for(int i = 1; i + k <= 2e5; i++){
		if(!v[i]) continue;
		if(!v[i + k]) continue;
		int sm = sum[i + k] - sum[i - 1];
		if(sm < m) continue;
		ans = (ans + C(sm, m) - C(sm - v[i], m) - C(sm - v[i + k], m) + C(sm - v[i] - v[i + k], m)) % mod;
	}
    cout << (ans + mod) % mod << endl;
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