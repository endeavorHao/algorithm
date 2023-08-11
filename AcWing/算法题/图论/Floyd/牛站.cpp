#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int g[N][N];
int res[N][N];
int K, n, m, S, E;
map<int, int> mp, cnt;
void mul(int a[][N], int b[][N], int c[][N]){
    static int temp[N][N];  // 计算b * c
    memset(temp, 0x3f, sizeof temp);
    for(int k = 1; k <= n; k ++ )
        for(int i = 1; i <= n; i ++ )
            for(int j = 1; j <= n; j ++ )
                temp[i][j] = min(temp[i][j], b[i][k] + c[k][j]);
    memcpy(a, temp, sizeof temp);
}
void qmi(){
    memset(res, 0x3f, sizeof res);
    for(int i = 1; i <= n; i ++ ) res[i][i] = 0;

    while(K){
        if(K & 1) mul(res, res, g);
        mul(g, g, g);  // 倍增
        K >>= 1;
    }
}
void solve(){
	cin >> K >> m >> S >> E;
    memset(g, 0x3f, sizeof g);
    while(m -- ){
        int a, b, c;
        cin >> c >> a >> b;
        if(!mp.count(a)) mp[a] = ++ n;
        if(!mp.count(b)) mp[b] = ++ n;
        a = mp[a], b = mp[b];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    qmi();

    cout << res[mp[S]][mp[E]] << endl;
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