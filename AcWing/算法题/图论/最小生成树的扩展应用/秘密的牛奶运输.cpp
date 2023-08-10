#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 5010, M = 20010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
struct node{
    int a, b, w;
    bool f;
    bool operator<(const node &t)const{
        return w < t.w;
    }
}edge[M];
int p[N];
int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist1[N][N], dist2[N][N];
int add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
void dfs(int a, int fa, int maxd1, int maxd2, int d1[], int d2[])
{
    d1[a] = maxd1, d2[a] = maxd2;
    for (int i = h[a]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            int td1 = maxd1, td2 = maxd2;
            if (w[i] > td1) td2 = td1, td1 = w[i];
            else if (w[i] < td1 && w[i] > td2) td2 = w[i];
            dfs(j, a, td1, td2, d1, d2);
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }
    sort(edge, edge + m);

    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ ) p[i] = i;
    
    int sum = 0;
    for(int i = 0; i < m; i ++ ){
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            p[pa] = pb;
            sum += w;
            edge[i].f = true;
            add(a, b, w), add(b, a, w);
        }
    }
    
    for(int i = 1; i <= n; i ++ ) dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);

    int res = 1e18;
    for (int i = 0; i < m; i ++ )
        if (!edge[i].f)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            int t;
            if (w > dist1[a][b])
                t = sum + w - dist1[a][b];
            else if (w > dist2[a][b])
                t = sum + w - dist2[a][b];
            res = min(res, t);
        }

    cout << res << endl;
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