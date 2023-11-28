#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 15, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

double f[N][N][N][N][5][5];

int A, B, C, D;
double dp(int a, int b, int c, int d, int x, int y) {
    auto &v = f[a][b][c][d][x][y];
    if(v >= 0) return v;
    int as = a + (x == 0) + (y == 0);
    int bs = b + (x == 1) + (y == 1);
    int cs = c + (x == 2) + (y == 2);
    int ds = d + (x == 3) + (y == 3);
    if(as >= A && bs >= B && cs >= C && ds >= D) return v = 0;

    int sum = a + b + c + d + (x != 4) + (y != 4);
    sum = 54 - sum;
    if(sum <= 0) return v = INF;
    v = 1;
    if(a < 13) v += (13.0 - a) / sum * dp(a + 1, b, c, d, x, y);
    if(b < 13) v += (13.0 - b) / sum * dp(a, b + 1, c, d, x, y);
    if(c < 13) v += (13.0 - c) / sum * dp(a, b, c + 1, d, x, y);
    if(d < 13) v += (13.0 - d) / sum * dp(a, b, c, d + 1, x, y);
    if(x == 4) {
        double t = INF;
        for(int i = 0; i < 4; i ++ ) t = min(t, 1.0 / sum * dp(a, b, c, d, i, y));
        v += t;
    }
    if(y == 4) {
        double t = INF;
        for(int i = 0; i < 4; i ++ ) t = min(t, 1.0 / sum * dp(a, b, c, d, x, i));
        v += t;
    }
    return v;
}

void solve(){
    cin >> A >> B >> C >> D;
    memset(f, -1, sizeof f);
    double t = dp(0, 0, 0, 0, 4, 4);
    if(t >= INF / 2) cout << -1 << endl;
    else cout << t << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cout << fixed << setprecision(3);
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}