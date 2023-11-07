/*
    p[i] = n * s[i] - T[i]
    F[i] = {f[i], f[i + 1], S[i], p[i]}
    A = {
        {0, 1, 0, 0};
        {1, 1, 1, 0};
        {0, 0, 1, 1};
        {0, 0, 0, 1};
    }
    F[n] = F[1] * A ^ n - 1;
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 4, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){  
    int n, m;
    cin >> n >> m;

    int f[N][N] = {1, 1, 1, 0};
    int A[N][N] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1},
    };
    auto mul = [&](int c[][N], int a[][N], int b[][N]){
        static int t[N][N];
        memset(t, 0, sizeof t);
        for(int i = 0; i < N; i ++ ) {
            for(int j = 0; j < N; j ++ ) {
                for(int k = 0; k < N; k ++ ) {
                    t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % m;
                }
            }
        }
        memcpy(c, t, sizeof t);
    };
    int k = n - 1;
    while(k) {
        if(k & 1) mul(f, f, A);
        mul(A, A, A);
        k >>= 1;
    }
    cout << ((n * f[0][2] - f[0][3]) % m + m) % m << endl;
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