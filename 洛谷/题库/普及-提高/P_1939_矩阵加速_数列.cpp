#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 3, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int f[N][N], a[N][N];
void mul(int c[N][N], int a[N][N], int b[N][N]) {
    static int t[N][N];
    memset(t, 0, sizeof t);
    for(int i = 0; i < N; i ++ ) {
        for(int j = 0; j < N; j ++ ) {
            for(int k = 0; k < N; k ++ ) {
                t[i][j] = (t[i][j] + a[i][k] % mod * b[k][j] % mod) % mod;
            }
        }
    }
    memcpy(c, t, sizeof t);
}
void init() {
    f[0][0] = 1, f[0][1] = 1, f[0][2] = 1;
    a[0][0] = 1, a[0][1] = 1, a[0][2] = 0;
    a[1][0] = 0, a[1][1] = 0, a[1][2] = 1;
    a[2][0] = 1, a[2][1] = 0, a[2][2] = 0;
}

void solve(){
    init();
    int n;
    cin >> n;
    n -= 3;
    if(n <= 0) {
        cout << 1 << endl;
        return;
    }
    while(n) {
        if(n & 1) mul(f, f, a);
        mul(a, a, a);
        n >>= 1;
    }
    cout << f[0][0] << endl;
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