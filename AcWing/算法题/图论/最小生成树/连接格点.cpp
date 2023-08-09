#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 1010, M = N * N, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int pos[N][N];
int p[M];
int n, m, cnt;
struct node{
    int u, v, w;
    bool operator< (const node &t) const{
        return w < t.w;
    }
}edge[M];
int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
bool merge(int a, int b){
    a = find(a), b = find(b);
    if(a == b){
        return false;
    }
    p[a] = b;
    return true;
}
void get_edge(){
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, dw[4] = {1, 2, 1, 2};

    for(int z = 0; z < 2; z ++ )
        for(int i = 1; i <= n; i ++ )
            for(int j = 1; j <= m; j ++ )
                for(int k = 0; k < 4; k ++ ){
                    if(k % 2 == z){
                        int x = i + dx[k], y = j + dy[k], w = dw[k];
                        if(!x && x >= n && !y && y >= m) continue;
                        int a = pos[i][j], b = pos[x][y];
                        if(a < b) edge[cnt ++ ] = {a, b, w};
                    }
                }
}
void solve(){
    cin >> m >> n;
    for(int i = 1, t = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ , t ++)
            pos[i][j] = t;
    for(int i = 1; i <= n * m; i ++ ) p[i] = i;

    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        int a = pos[x1][y1], b = pos[x2][y2];
        merge(a, b);
    }
    get_edge();

    int ans = 0;
    sort(edge, edge + cnt);
    for(int i = 0; i < cnt; i ++ ){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(merge(u, v)) ans += w;
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