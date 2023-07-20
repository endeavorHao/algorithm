#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1e9 + 7;
typedef pair<int, int> PII;
int n, m;
int a[N];
int fact[N], infact[N];
int qmi(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int C(int a, int b){
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}
void solve(){
    int a, b;
	cin >> a >> b;
    cout << C(a, b) << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i ++ ){
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;
    }
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}