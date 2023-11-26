#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 1) {
        cout << m << endl;
        return;
    }
    int sum = 0;
    if(k & 1) {
        int t = k / 2;  // 一个团最多需要t个女
        int x = m / t;  // 一共能凑出多少个最大女生团且需要s个男生来补
        int y = m % t;
		int maxv = min(x, n);
        sum += maxv * t;
        m -= maxv * t;
        n -= maxv;
        if(n + 2 * y >= k) {
            n -= k - 2 * y;
            sum += y;
            m -= y;
        }
    }else {
        int t = k / 2;
        int x = m / t;
        int y = m % t;
        sum += t * x;
        m -= t * x;
        if(n + 2 * y >= k) {
            n -= k - 2 * y;
            sum += y;
            m -= y;
        }
    }
    n %= k;
    cout << n + m - min(sum, n / 2) << endl;
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