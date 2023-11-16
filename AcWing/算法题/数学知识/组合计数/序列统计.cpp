/*
    若ai >= 1
    求k个不同ai满足 a1 + a2 + .. + ak = n
    即选法为C(n - 1, k - 1) // 隔板法
    扩展：
        a1 + a2 + .. + ak <= n
        选法个数为C(n, k)
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000003;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int qmi(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int a, int b) {
    if(a < b) return 0;
    int up = 1, down = 1;
    for(int i = a, j = 1; j <= b; i --, j ++ ) {
        up = up * i % mod;
        down = down * j % mod;
    }
    return up * qmi(down, mod - 2) % mod;
}

int Lucas(int a, int b) {
    if(a < mod && b < mod) return C(a, b);
    return Lucas(a / mod, b / mod) * C(a % mod, b % mod);
}

void solve(){  
    int n, l, r;
    cin >> n >> l >> r;
    cout << (Lucas(r - l + n + 1, n) + mod - 1) % mod << endl;
}
signed main() {
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