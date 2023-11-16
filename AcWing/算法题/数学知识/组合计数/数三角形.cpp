/*
    点数为n + 1, m + 1
    所有方案为C(n * m, 3)
    在所有一条直线的方案数
    k为0时的方案数C(m, 3)
    k为正无穷的方案数C(n, 3)
    k>0 
        第一个点与第三个点间距为(i, j) 第二个点选的方案为(gcd(i, j) - 1) * (n - i) * (m - j)
    k<0 与 k>0 相同
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

int C(int a, int b) {
    int res = 1;
    for(int i = a, j = 1; j <= b; i --, j ++ ) {
        res = res * i / j;
    }
    return res;
}

void solve(){  
    int n, m;
    cin >> n >> m;
    n ++, m ++;
    int ans = C(n * m, 3) - C(n, 3) * m - C(m, 3) * n;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            ans -= 2 * (gcd(i, j) - 1) * (n - i) * (m - j);
        }
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