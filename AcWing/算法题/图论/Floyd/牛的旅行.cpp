#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<PII> q(n);
    for(int i = 0; i < n; i ++ ) cin >> q[i].x >> q[i].y;
    vector<vector<char>> g(n, vector<char>(n)); 
    vector<vector<double>> d(n, vector<double>(n));
    vector<double> maxd(n, 0);
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ ) 
            cin >> g[i][j];
    
    auto get_dist = [&](int a, int b) -> double{
        int x1 = q[a].x, x2 = q[b].x, y1 = q[a].y, y2 = q[b].y;
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ ){
            if(i == j) d[i][j] = 0;
            else if(g[i][j] == '1') d[i][j] = get_dist(i, j);
            else d[i][j] = 1e9;
        }
    
    for(int k = 0; k < n; k ++ )
        for(int i = 0; i < n; i++ )
            for(int j = 0; j < n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    double r1 = 0;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ )
            if(d[i][j] < 1e9 / 2)
                maxd[i] = max(maxd[i], d[i][j]);
        r1 = max(maxd[i], r1);
    }
    double r2 = 1e9;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < n; j ++ ){
            if(d[i][j] > 1e9 / 2)
                r2 = min(r2, maxd[i] + get_dist(i, j) + maxd[j]);
        }
    }
    printf("%.6lf\n", max(r1, r2));
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