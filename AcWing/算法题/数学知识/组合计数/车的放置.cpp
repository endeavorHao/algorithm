/*
    一个a*b长方形中放k个车的方案数为C(a, k) * A(b, k)
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 100003;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int fact[N], infact[N];

int qmi(int a, int b) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    } 
    return ans;
}

int C(int a, int b) {
    if(a < b) return 0;
    if(a < 0 || b < 0) return 0;
    return fact[a] * infact[b] % mod * infact[a - b] % mod;
}
int A(int a, int b) {
    if(a < b) return 0;
    if(a < 0 || b < 0) return 0;
    return fact[a] * infact[a - b] % mod;
}

void solve(){  
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    fact[0] = infact[0] = 1;
    for(int i = 1; i < N; i ++ ) {
        fact[i] = fact[i - 1] * i % mod;
        infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;
    }
    int ans = 0;
    for(int i = 0; i <= k; i ++ ) {
        ans = (ans + C(b, i) * A(a, i) % mod * C(d, k - i) * A(a + c - i, k - i) % mod) % mod;
    }
    cout << ans << endl;
}
signed main() {
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