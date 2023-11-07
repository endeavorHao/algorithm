/*
    f[i][j]表示前i个数，不含S串，且与S的前缀有j个相同
    f[i + 1][k] += f[i][j]
    又因为每次转移都是一样的
    因此让每个a[j][k] ++即可
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 25, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int ne[N];
int a[N][N];
int n, m, K;

void mul(int c[][N], int a[][N], int b[][N]) {
    static int t[N][N];
    memset(t, 0, sizeof t);
    for(int i = 0; i < m; i ++ ) {
        for(int j = 0; j < m; j ++ ) {
            for(int k = 0; k < m; k ++ ) {
                t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % K;
            }
        }
    }
    memcpy(c, t, sizeof t);
}

int qmi(int k) {
    int f[N][N] = {1};
    while(k) {
        if(k & 1) mul(f, f, a);
        mul(a, a, a);
        k >>= 1;
    }
    int ans = 0;
    for(int i = 0; i < m; i ++ ) ans = (ans + f[0][i]) % K;
    return ans;
}

void solve(){  
    string s;
    cin >> n >> m >> K;
    cin >> s;
    s = " " + s;
    for(int i = 2, j = 0; i <= m; i ++ ){
        while(j && s[i] != s[j + 1]) j = ne[j];
        if(s[i] == s[j + 1]) j ++;
        ne[i] = j;
    }
    for(int j = 0; j < m; j ++ ) {
        for(int k = '0'; k <= '9'; k ++ ) {
            int u = j;
            while(u && s[u + 1] != k) u = ne[u];
            if(s[u + 1] == k) u ++;
            if(u < m) a[j][u] ++; 
        }
    }
    // F[n] = F[0] * a ^ n
    cout << qmi(n) << endl;
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